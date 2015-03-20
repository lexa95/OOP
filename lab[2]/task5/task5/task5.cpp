// task5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ParseURL.h"

void PrintInformation(std::string url, int port, std::string host, std::string document)
{
	std::cout << url << std::endl;
	std::cout << "HOST: " << host << std::endl;
	std::cout << "PORT: " << port << std::endl;
	std::cout << "DOC: " << document << std::endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	
	Protocol protocol;
	int port;
	std::string host;
	std::string document;

	ParseURL("http://www.mysite.com/docs/document1.html?page=30&lang=en#title", protocol, port, host, document);
	PrintInformation("http://www.mysite.com/docs/document1.html?page=30&lang=en#title", port, host, document);

	return 0;
}

