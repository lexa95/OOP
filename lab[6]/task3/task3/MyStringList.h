#pragma once
class CMyStringList
{
public:
	CMyStringList();

	void Append(std::string const& tail);
	std::string * GetLast()const;
	std::string * GetFirst()const;
	~CMyStringList();

private:
	struct StringList
	{
		StringList * next;
		StringList * previous;
		std::string value;
	};
	StringList * m_start;
	StringList * m_end;

	size_t m_count;
};

