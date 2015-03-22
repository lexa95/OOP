// task5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ParseURL.h"

void PrintInformation(std::string url, int port, std::string host, std::string document)
{
	std::cout << "HOST: " << host << std::endl;
	std::cout << "PORT: " << port << std::endl;
	std::cout << "DOC: " << document << std::endl;
}

void InteractionWithTheUser()
{
	Protocol protocol;
	int port;
	std::string host;
	std::string document;

	while (!std::cin.eof())
	{
		std::string url;
		std::cout << '>';
		if (std::getline(std::cin, url))
		{
			if (url == "")
			{
				continue;
			}

			if (ParseURL(url, protocol, port, host, document))
			{
				PrintInformation(url, port, host, document);
			}
			else
			{
				std::cout << "Incorrect line." << std::endl;
			}
		}
		else
		{
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	InteractionWithTheUser();

	return 0;
}

