#include "stdafx.h"
#include "MyStringList.h"
#include <boost/shared_ptr.hpp>

using namespace std;


CMyStringList::CMyStringList():
			m_end(nullptr), m_start(nullptr), m_length(0)
{
}

void CMyStringList::Append(std::string tail)
{
	shared_ptr<StringList> newList(new StringList);
	newList->next = nullptr;
	newList->value = tail;

	if (m_length != 0)
	{
		newList->previous = m_end;
		m_end->next = newList;
		m_end = newList;
	}
	else
	{
		newList->previous = NULL;
		m_end = m_start = newList;
	}
	m_length++;
}

//void CMyStringList::Show() const
//{
//	shared_ptr<StringList> temp = m_start;
//	while (temp)
//	{
//		//std::cout << temp->value << std::endl;
//		temp = temp->next;
//	}
//}

CMyStringList::Iterator CMyStringList::Begin()
{
	if (!m_start)
	{
		throw out_of_range("empty list");
	}
	return Iterator(m_start);	
};

CMyStringList::Iterator CMyStringList::End()
{
	if (!m_end)
	{
		throw out_of_range("empty list");
	}
	return Iterator(m_end);
};

void CMyStringList::Remove(Iterator & it)
{
	if (!SearchForItems(it))
	{
		throw invalid_argument("incorrect arg");
	}
	std::shared_ptr<StringList> deletedItems = it.Get();
	
	if (deletedItems->previous)
	{
		if (deletedItems->next)
		{
			deletedItems->previous->next = deletedItems->next;
			deletedItems->next->previous = deletedItems->previous;
		}
		else
		{
			m_end = deletedItems->previous;
			deletedItems->previous->next = nullptr;
		}
		deletedItems.reset();
	}
	else
	{
		if (deletedItems->next)
		{
			deletedItems->next->previous = nullptr;
			m_start = deletedItems->next;
		}
		else
		{
			m_end, m_start = nullptr;
		}
		deletedItems.reset();
	}
	m_length--;
}

void CMyStringList::Insert(Iterator & it, string const& value)
{
	if (!SearchForItems(it))
	{
		throw invalid_argument("incorrect arg");
	}

	std::shared_ptr<StringList> item = it.Get();
	std::shared_ptr<StringList> newItem(new StringList);
	newItem->value = value;
	newItem->previous = item;

	if (item->next)
	{
		newItem->next = item->next;
		item->next = newItem;
		item->next->previous = newItem;
	}
	else
	{
		item->next = newItem;
		newItem->next = nullptr;
		m_end = newItem;
	}

	m_length++;
}

bool CMyStringList::SearchForItems(Iterator & it) const
{
	shared_ptr<StringList> temp = m_start;
	while (temp)
	{
		if (temp == it.Get())
		{
			return true;
		}
		temp = temp->next;
	}

	return false;
}

//==================================================================

CMyStringList::Iterator::Iterator(std::shared_ptr<StringList> &  element)
: m_element(element)
{};

std::string & CMyStringList::Iterator::operator*()
{
	return m_element->value;
};

std::shared_ptr<StringList> CMyStringList::Iterator::Get()
{
	return m_element;
}

CMyStringList::Iterator & CMyStringList::Iterator::operator--()
{
	if (!(m_element->previous))
	{
		throw out_of_range("error range");
	}

	std::shared_ptr<Iterator> temp(new Iterator(m_element));
	m_prefix = temp;
	m_element = m_element->previous;
	return *m_prefix;
};

CMyStringList::Iterator & CMyStringList::Iterator::operator--(int)
{
	if (!(m_element->previous))
	{
		throw out_of_range("error range");
	}

	m_element = m_element->previous;
	return *this;
};

CMyStringList::Iterator & CMyStringList::Iterator::operator++()
{
	if (!(m_element->next))
	{
		throw out_of_range("error range");
	}

	std::shared_ptr<Iterator> temp(new Iterator(m_element));
	m_prefix = temp;
	m_element = m_element->next;
	return *m_prefix;
};

CMyStringList::Iterator & CMyStringList::Iterator::operator++(int)
{
	if (!(m_element->next))
	{
		throw out_of_range("error range");
	}

	m_element = m_element->next;
	return *this;
};

bool CMyStringList::Iterator::operator!=(Iterator & it)
{
	return it.Get() != m_element;
};

bool CMyStringList::Iterator::operator==(Iterator & it)
{
	return it.Get() == m_element;
};