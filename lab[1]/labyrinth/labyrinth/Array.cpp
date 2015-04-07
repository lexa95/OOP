#include "stdafx.h"
#include "Array.h"


Array::Array()
{
}

void Array::Init(int hight, int width, int value)
{
	m_width = width;
	m_hight = hight;
	size_t length = width * hight;
	for (size_t i = 0; i < length; i++)
	{
		m_array.push_back(value);
	}
}

void Array::ChangeX(int x)
{
	m_x = x;
}

Array::~Array()
{
}
