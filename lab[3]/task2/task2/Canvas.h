#pragma once
#include <iostream>
#include <vector>

class CCanvas
{
public:
	CCanvas(unsigned width, unsigned height);
	
	unsigned GetWidth()const;
	unsigned GetHight()const;
	
	void Clear(char code = ' ');
	void SetPixel(int x, int y, char code);
	char GetPixel(int x, int y)const;
	void Write(std::ostream & ostream)const;
	
	~CCanvas();
private:
	int m_width, m_height;
	std::vector<int> m_canvas;
};

