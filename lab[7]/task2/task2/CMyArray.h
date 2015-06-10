#pragma once

template <class elemType>
class CMyArray {
public:
	CMyArray() :m_size(0), m_data(0)
	{
		elemType * m_data = new  elemType[1];
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
		elemType * temp = new  elemType[m_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}
		delete [] m_data;
		
		m_data = temp;
		m_data[m_size] = value;
		m_size++;
	};

	int Size()
	{ 
		return m_size; 
	}

	elemType & operator [](int index)
	{
		if ((index >= 0) && (index < m_size))
		{
			return elemType(m_data[index]);
		}
		throw out_of_range("Выход за границы массива");
		return m_data[0];
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

	void Resize(int size)
	{
		elemType * temp = new  elemType[size];
		for (int i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}
		delete[] m_data;
		m_data = temp;

		elemType value = elemType();
		for (int i = m_size; i < size; i++)
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
	int m_size;
	elemType *m_data;
};