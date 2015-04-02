// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"

using namespace std;

void DisplaysInformationAboutErrorSetGear(int gear, CCar car)
{
	auto speedRange = car.GetSpeedRange();

	if (!(gear >= -1 && gear <= 5))
	{
		cout << "�� ������ ��������";
	}
	else if (car.GetSpeed() >= speedRange[gear][0] && car.GetSpeed() <= speedRange[gear][1])
	{
		if (gear == -1)
		{
			cout << "�� ������ ��� ����� ������������� ������ � ����������� ��� ������ �������� �� ������� ��������";
		}
		else if (car.GetGear() == -1 && gear == 1)
		{
			cout << "C ������� ���� ����� ������������� �� ������ �������� ������ �� ������� ��������";
		}
		else if (car.GetGear() == 0 && gear == 1)
		{
			cout << "�������������� �� ������ ���� �� ����������� �������� �� ��������� ��������, ��������������� ������ �������� ����� ������ ����� ���������"; 
		}
	}
	else
	{
		cout << "������� �������� ���������� �� ��������� � ��������� ��������� ����� ��������";
	}
	cout << endl;
}

void DisplaysInformationAboutErrorSetSpeed(int speed, CCar car)
{
	auto speedRange = car.GetSpeedRange();

	if (speed >= speedRange[car.GetGear()][0] && speed <= speedRange[car.GetGear()][1])
	{
		if (car.GetGear() == 0 && car.GetSpeed() < speed)
		{
			cout << "�� ����������� ����� �������� ������ � ������� ����.";
			return;
		}
	}
	cout << "�� ������ �������� ����� ������� �������� � �������� ����������� ������ �������� ���������.";
	cout << endl;
}

void DisplayInformation(CCar car)
{
	cout << "���������: ";
	car.IsTurnedOn() ? cout << "���" : cout << "����";
	cout << endl;
	cout << "��������: " << car.GetSpeed() << endl;


	cout << "��������: ";
	int gear = car.GetGear();
	switch (gear)
	{
	case(-1) : cout << "������ ���"; break;
	case(0) : cout << "��������"; break;
	case(1) : cout << "������"; break;
	case(2) : cout << "������"; break;
	case(3) : cout << "������"; break;
	case(4) : cout << "���������"; break;
	case(5) : cout << "�����"; break;
	default:
		break;
	}

	int direction = car.GetDirectionOfMotion();
	cout << endl << "�����������: ";
	switch (direction)
	{
	case(-1) : cout << "�����";break;
	case(0) : cout << "����� �� �����"; break;
	case(1) : cout << "������"; break;
	default:
		break;
	}
	cout << endl;
}

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}
void UseTheCommand(string command, CCar & car)
{
	if (command == "Info")
	{
		DisplayInformation(car);
	}
	else if (command == "EngineOn")
	{
		if (car.TurnedOnEngine())
		{
			cout << "��������� �������." << endl;
		}
		else
		{
			cout << "��������� ��� �������." << endl;
		}
	}
	else if (command == "EngineOff")
	{
		if (car.TurnOffEngine())
		{
			cout << "��������� ��������." << endl;
		}
		else
		{
			cout << "�� ������� ��������� �������.";
			/*if (car.GetSpeed() != 0)
			{
				cout << "�������� �� ����� ����." << endl;
			}
			else if (car.GetAutomotiveTransmission() != 0)
			{
				cout << "������ ���� �������� ���������� ��������." << endl;
			}
			else
			{
				cout << "��������� ��� ��������" << endl;
			}*/
		}
	}
	else if (command.substr(0, 8) == "SetGear ")
	{
		bool err;
		int gear = StringToInt(command.substr(8).c_str(), err);
		if (err)
		{
			cout << "�� ������� ���������� �������." << endl;
		}
		if (!car.SetGear(gear))
		{
			DisplaysInformationAboutErrorSetGear(gear, car);
		}
	}
	else if (command.substr(0, 9) == "SetSpeed ")
	{
		bool err;
		int speed = StringToInt(command.substr(9).c_str(), err);
		if (err)
		{
			cout << "�� ������� ���������� �������." << endl;
		}
		if (!car.SetSpeed(speed))
		{
			DisplaysInformationAboutErrorSetSpeed(speed, car);
		}
	}
	else
	{
		cout << "�� ������� ���������� �������." << endl;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	CCar car;

	std::cout << "Enter: " << std::endl;
	bool isChangeDictionary = false;
	while (!std::cin.eof())
	{
		std::string line;
		std::cout << '>';
		if (getline(cin, line))
		{
			if (line == "")
			{
				continue;
			}
			UseTheCommand(line , car);
		}
		else
		{
			break;
		}
	}
	
	return 0;
}

