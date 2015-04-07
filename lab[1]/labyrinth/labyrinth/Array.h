#pragma once
#include <vector>

class Array
{
public:
	Array();
	~Array();

	void Init(int hight, int width, int value);
	void ChangeX(int x);
	int & operator[](int y)
	{
		return m_array[m_x * m_width + y];
	}
private:
	std::vector<int> m_array;
	int m_hight, m_width, m_x;
};

