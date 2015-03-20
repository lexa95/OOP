#include "stdafx.h"
#include "ParseURL.h"

//http://www.mysite.com/docs/document1.html?page=30&lang=en#title

char ToUpper(const char ch)
{
	if (ch >= 97 && ch <= 122)
	{
		return (char)(ch - ('a' - 'A'));
	}

	if (ch >= 224 && ch <= 255)
	{
		return (char)(ch - ('а' - 'А'));
	}
	return ch;
}

std::string	UpperCase(const std::string word)
{
	std::string result;
	size_t count = strlen(word.c_str());

	for (size_t i = 0; i < count; i++)
	{
		result += ToUpper(word[i]);
	}
	return result;
}

std::string GetStringToSubstring(std::string const& line, std::string const& substring)
{
	std::string result = "";

	size_t lenLine = strlen(line.c_str());
	size_t lenSubstring = strlen(substring.c_str());

	for (size_t i = 0; i < lenLine; i++)
	{
		if (line.substr(i, lenSubstring) == substring)
		{
			return result;
		}
		else
		{
			result += line[i];
		}
	}
	return result;
}

int TakePort(Protocol & protocol, const std::string key)
{
	if (UpperCase(key) == "HTTP")
	{
		protocol = HTTP;
		return 80;
	}
	else if (UpperCase(key) == "HTTPS")
	{
		protocol = HTTPS;
		return 443;
	}
	else if (UpperCase(key) == "FTP")
	{
		protocol = FTP;
		return 21;
	}
	return -1;
}

bool ParseURL(std::string const& url, Protocol & protocol, 
	int & port, std::string & host, std::string & document)
{
	std::string strProtocol = GetStringToSubstring(url, "://");
	port = TakePort(protocol, strProtocol);
	if (port == -1)
	{
		std::cout << "Не верный адрес" << std::endl;
		return false;
	}

	host = GetStringToSubstring(url.substr(strlen(strProtocol.c_str()) + 3), "/");
	if (host.find('.') == std::string::npos)
	{
		std::cout << "Не верный адрес" << std::endl;
		return false;
	}
	document = url.substr(strlen(strProtocol.c_str()) + 3 + strlen(host.c_str()));
	
	return true;
}