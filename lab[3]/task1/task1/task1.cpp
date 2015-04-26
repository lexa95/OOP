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
		cout << "Не верная передача";
	}
	else if (car.GetSpeed() >= speedRange[gear][0] && car.GetSpeed() <= speedRange[gear][1])
	{
		if (gear == -1)
		{
			cout << "На задний ход можно переключиться только с нейтральной или первой передачи на нулевой скорости";
		}
		else if (car.GetGear() == -1 && gear == 1)
		{
			cout << "C заднего хода можно переключиться на первую передачу только на нулевой скорости";
		}
		else if (car.GetGear() == 0 && gear == 1)
		{
			cout << "Переключившись на заднем ходу на нейтральную передачу на ненулевой скорости, переключитьсяна первую передачу можно только после остановки"; 
		}
	}
	else
	{
		cout << "Текущая скорость автомобиля не находится в диапазоне скоростей новой передачи";
	}
	cout << endl;
}

void DisplaysInformationAboutErrorSetSpeed(int speed, CCar car)
{
	auto speedRange = car.GetSpeedRange();

	if (!car.IsTurnedOn())
	{
		cout << "Двигатель выключен." << endl;
		return;
	}

	if (speed >= speedRange[car.GetGear()][0] && speed <= speedRange[car.GetGear()][1])
	{
		if (car.GetGear() == 0 && car.GetSpeed() < speed)
		{
			cout << "На нейтральной можно изменить только в сторону нуля." << endl;
			return;
		}
	}
	cout << "На каждой передаче можно развить скорость в пределах отведенного данной передаче диапазона.";
	cout << endl;
}

void DisplayInformation(CCar car)
{
	cout << "Двигатель: ";
	car.IsTurnedOn() ? cout << "вкл" : cout << "выкл";
	cout << endl;
	cout << "Скорость: " << car.GetSpeed() << endl;


	cout << "Передача: ";
	int gear = car.GetGear();
	switch (gear)
	{
	case(-1) : cout << "Задний ход"; break;
	case(0) : cout << "Нейтраль"; break;
	case(1) : cout << "Первая"; break;
	case(2) : cout << "Вторая"; break;
	case(3) : cout << "Третья"; break;
	case(4) : cout << "Четвертая"; break;
	case(5) : cout << "Пятая"; break;
	default:
		break;
	}

	int direction = car.GetDirectionOfMotion();
	cout << endl << "Направление: ";
	switch (direction)
	{
	case(-1) : cout << "назад";break;
	case(0) : cout << "стоим на месте"; break;
	case(1) : cout << "вперед"; break;
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
			cout << "Двигатель включен." << endl;
		}
		else
		{
			cout << "Двигатель уже включен." << endl;
		}
	}
	else if (command == "EngineOff")
	{
		if (car.TurnOffEngine())
		{
			cout << "Двигатель выключен." << endl;
		}
		else
		{
			cout << "Не удалось выключить двигатель." << endl;
			/*if (car.GetSpeed() != 0)
			{
				cout << "Скорость не равна нулю." << endl;
			}
			else if (car.GetAutomotiveTransmission() != 0)
			{
				cout << "Должна быть включена нейтралная передача." << endl;
			}
			else
			{
				cout << "Двигатель уже выключен" << endl;
			}*/
		}
	}
	else if (command.substr(0, 8) == "SetGear ")
	{
		bool err;
		int gear = StringToInt(command.substr(8).c_str(), err);
		if (err)
		{
			cout << "Не удалось распознать команду." << endl;
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
			cout << "Не удалось распознать команду." << endl;
		}
		if (!car.SetSpeed(speed))
		{
			DisplaysInformationAboutErrorSetSpeed(speed, car);
		}
	}
	else
	{
		cout << "Не удалось распознать команду." << endl;
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

