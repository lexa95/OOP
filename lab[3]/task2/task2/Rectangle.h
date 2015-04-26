#pragma once
class CRectangle
{
public:
	CRectangle(int left, int top, int width, int hight);
	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	bool Intersect(CRectangle const& other);

	void SetLeft(int left);
	void SetTop(int top);
	void SetWidth(int width);
	void SetHight(int hight);

	int GetArea() const;
	int GetPerimeter() const;
	int GetLeft() const;
	int GetTop() const;
	int GetRight() const;
	int GetBottom() const;
	int GetWidth() const;
	int GetHight() const;
private:
	void UpdateTheData();
	int m_width, m_hight, m_left, m_top, m_right,
		m_bottom, m_area, m_perimeter;
};

