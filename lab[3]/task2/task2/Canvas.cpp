#include "stdafx.h"
#include "Canvas.h"


CCanvas::CCanvas(unsigned width, unsigned height)
		:m_width(width), m_height(height)
{
	m_canvas.reserve(width * height);

	for (int i = 0; i < m_width * m_height; i++)
	{
		m_canvas.push_back(' ');
	}
}

unsigned CCanvas::GetWidth()const
{
	return m_width;
}

unsigned CCanvas::GetHight()const
{
	return m_height;
}

void CCanvas::Clear(char code)
{
	for (size_t i = 0; i < m_canvas.size(); i++)
	{
		m_canvas[i] = code;
	}
}

void CCanvas::SetPixel(int x, int y, char code)
{
	m_canvas[x * m_width + y] = code;
}

char CCanvas::GetPixel(int x, int y)const
{
	return m_canvas[x * m_width + y];
}

void CCanvas::Write(std::ostream & ostream)const
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			ostream << char(m_canvas[i * m_width + j]);
		}
		ostream << std::endl;
	}
}

CCanvas::~CCanvas()
{
}
