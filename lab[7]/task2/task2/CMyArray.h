#pragma once
#include <stdexcept>
#include <algorithm>

template <class elemType>
class CMyArray {
public:
	CMyArray() :m_size(0)
	{
		m_data = new elemType[1];
	};

	CMyArray(CMyArray & obj)
	{
		delete[] m_data;
		m_data = new elemType[obj.Size()];
		for (int i = 0; i < obj.Size(); i++) 
		{ 
			m_data[i] = obj[i]; 
		}
		m_size = obj.Size();
	};

	void Add(elemType value)
	{
		elemType * temp = new elemType[m_size + 1];
		for (size_t i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}
		delete []m_data;
		m_data = new elemType[m_size + 1];

		m_data = temp;
		for (size_t i = 0; i < m_size + 1; i++)
		{
			m_data[i] = temp[i];
		}

		m_data[m_size] = value;
		m_size++;
	};

	int Size()
	{ 
		return m_size; 
	}

	elemType & operator [](size_t index)
	{
		if ((index >= 0) && (index < m_size))
		{
			return m_data[index];
		}
		throw std::out_of_range("Выход за границы массива");
	}
	
	CMyArray & operator = (const CMyArray & other)
	{
		delete[] m_data;
		m_size = other.Size();
		m_data = new elemType[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = other[i];
		}
	}

	void Resize(size_t size)
	{
		elemType * temp = new  elemType[size];
		for (size_t i = 0; i < std::min(m_size, size); i++)
		{
			temp[i] = m_data[i];
		}
		delete[] m_data;
		m_data = temp;

		elemType value = elemType();
		for (size_t i = m_size; i < size; i++)
		{
			m_data[i] = value;
		}
		m_size = size;
	};

	void Clear()
	{
		m_size = 0;
		delete[] m_data;
	};

	~CMyArray()
	{
		delete[] m_data;
	};

private:
	size_t m_size;
	elemType * m_data;
};