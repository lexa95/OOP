#include "stdafx.h"
#include "RectArray.h"


RectArray::RectArray(int hight, int width, int value)
			:m_hight(hight), m_width(width)
{
	m_array.Init(hight, width, value);
}

int RectArray::GetWidth()const
{
	return m_width;
}
int RectArray::GetHight()const
{
	return m_hight;
}

RectArray::~RectArray()
{
}
