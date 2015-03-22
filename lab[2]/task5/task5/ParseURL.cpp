#include "stdafx.h"
#include "ParseURL.h"

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

char ToUpper(const char ch)
{
	if (ch >= 97 && ch <= 122)
	{
		return (char)(ch - ('a' - 'A'));
	}

	if (ch >= 224 && ch <= 255)
	{
		return (char)(ch - ('à' - 'À'));
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

void TakePort(Protocol & protocol, const std::string key, bool & err)
{
	err = true;
	if (UpperCase(key) == "HTTP")
	{
		protocol = HTTP;
	}
	else if (UpperCase(key) == "HTTPS")
	{
		protocol = HTTPS;
	}
	else if (UpperCase(key) == "FTP")
	{
		protocol = FTP;
	}
	err = false;
}

int TakeTheKeyPort(Protocol const & protocol)
{
	if (protocol == HTTP)
	{
		return 80;
	}
	else if (protocol == HTTPS)
	{
		return 443;
	}
	else if (protocol == FTP)
	{
		return 21;
	}
	return -1;
}

bool ParseURL(std::string const& url, Protocol & protocol, int & port, std::string & host, std::string & document)
{
	std::string strProtocol = GetStringToSubstring(url, "://");
	if (strProtocol == url)
	{
		return false;
	}
	
	bool err;
	TakePort(protocol, strProtocol, err);
	if (err)
	{
		return false;
	}

	host = GetStringToSubstring(url.substr(strlen(strProtocol.c_str()) + 3), "/");
	if (host.find('.') == std::string::npos)
	{
		return false;
	}
	document = url.substr(strlen(strProtocol.c_str()) + 3 + strlen(host.c_str()));

	if (host.find(':') != std::string::npos)
	{
		std::string reseltHost = GetStringToSubstring(host, ":");
		bool err;

		port = StringToInt(host.substr(strlen(reseltHost.c_str()) + 1).c_str(), err);
		if (err)
		{
			return false;
		}

		host = reseltHost;
	}
	else
	{
		port = TakeTheKeyPort(protocol);
	}
	
	if (port < 1 || port > 65535)
	{
		return false;
	}

	return true;
}