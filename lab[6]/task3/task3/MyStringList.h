#pragma once

#include <boost/shared_ptr.hpp>

struct StringList
{
	std::shared_ptr<StringList> next;
	std::shared_ptr<StringList> previous;
	std::string value;
};

class CMyStringList
{
public:
	CMyStringList();

	class Iterator
	{
	public:
		Iterator(std::shared_ptr<StringList> &  element);

		std::string & operator*();
		std::shared_ptr<StringList> Get();

		Iterator & operator--();
		Iterator & operator--(int);

		Iterator & operator++();
		Iterator & operator++(int);

		bool operator!=(Iterator & it);
		bool operator==(Iterator & it);

	private:
		std::shared_ptr<StringList> m_element;
		std::shared_ptr<Iterator> m_prefix;
	};

	/*void Show() const;*/
	void Append(std::string tail);
	void Remove(Iterator & it);
	void Insert(Iterator & it, std::string const& value);

	Iterator Begin();
	Iterator End();

	bool SearchForItems(Iterator & it) const;
private:
	std::shared_ptr<StringList> m_start;
	std::shared_ptr<StringList> m_end;

	size_t m_length;
};

