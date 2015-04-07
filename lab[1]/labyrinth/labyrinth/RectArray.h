#pragma once
#include "Array.h"

class RectArray
{
public:
	RectArray(int hight, int width, int value);
	~RectArray();
	Array & operator[](int x)
	{
		m_array.ChangeX(x);
		return m_array;
	}
	Array m_array;
	int GetWidth()const;
	int GetHight()const;
private:
	int m_hight, m_width;
};

