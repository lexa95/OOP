#pragma once

enum Protocol
{
	HTTP,
	HTTPS,
	FTP
};

bool ParseURL(std::string const& url, Protocol & protocol, int & port, std::string & host,
	std::string & document);

std::string GetStringToSubstring(std::string const& line, std::string const& substring);
std::string	UpperCase(const std::string word);