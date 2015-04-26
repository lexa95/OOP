#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(int left, int top, int width, int hight)
	:
	m_left(left), m_top(top), m_width(width), m_hight(hight)
{
	if (width  <  0)
	{	
		width = 0;
	}
	if (hight <  0)
	{
		hight = 0;
	}
	UpdateTheData();
}

void CRectangle::Move(int dx, int dy)
{
	m_left += dx;
	m_top += dy;
	UpdateTheData();
}

void CRectangle::Scale(int sx, int sy)
{
	if (sx > 0 && sy > 0)
	{
		m_width *= sx;
		m_hight *= sy;
		UpdateTheData();
	}
} 

bool CRectangle::Intersect(CRectangle const& other)
{
	if (m_top < other.GetTop() && other.GetTop() < m_bottom || m_top < other.GetBottom() && other.GetBottom() < m_bottom
		|| m_top >= other.GetTop() && m_bottom <= other.GetBottom() || other.GetTop() >= m_top && other.GetBottom() <= m_bottom)
	{
		if (m_left < other.GetLeft() && other.GetLeft() < m_right || m_left < other.GetRight() && other.GetRight() < m_right
			|| m_left >= other.GetLeft() && m_right <= other.GetRight() || other.GetLeft() >= m_left && other.GetRight() <= m_right)
		{
			m_top = other.GetTop() < m_top ? m_top : other.GetTop();
			m_left = other.GetLeft() < m_left ? m_left : other.GetLeft();
			
			m_width = (other.GetRight() > m_right ? m_right : other.GetRight()) - m_left;
			m_hight = (other.GetBottom() > m_bottom ? m_bottom : other.GetBottom()) - m_top;
			UpdateTheData();
			return true;
		}
	}

	m_width = m_hight = 0;
	UpdateTheData();
	return false;
}

void CRectangle::UpdateTheData()
{
	m_right = m_left + m_width;
	m_bottom = m_top + m_hight;
	m_area = m_hight * m_width;
	m_perimeter = 2 * m_hight + 2 * m_width;
}

int CRectangle::GetArea() const
{
	return m_area;
}

int CRectangle::GetPerimeter() const
{
	return m_perimeter;
}

int CRectangle::GetLeft() const
{
	return m_left;
}

int CRectangle::GetTop() const
{
	return m_top;
}

int CRectangle::GetRight() const
{
	return m_right;
}

int CRectangle::GetBottom() const
{
	return m_bottom;
}

int CRectangle::GetWidth() const
{ 
	return m_width;
}

int CRectangle::GetHight() const
{
	return m_hight;
}

void CRectangle::SetLeft(int left)
{
	m_left = left;
	UpdateTheData();
}

void CRectangle::SetTop(int top)
{
	m_top = top;
	UpdateTheData();
}

void CRectangle::SetWidth(int width)
{
	if (width == 0)
	{
		m_width = 0;
	}
	else
	{
		m_width = width;
	}
	UpdateTheData();
}

void CRectangle::SetHight(int hight)
{
	if (hight == 0)
	{
		m_hight = 0;
	}
	else
	{
		m_hight = hight;
	}
	UpdateTheData();
}