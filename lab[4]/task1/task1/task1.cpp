#include "stdafx.h"
#include "Body.h"
#include <string>
#include <vector>

using namespace std;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

vector<int> GetValuesFromStrings(string str)
{
	vector<int> values;
	str += ' ';
	string num = "";
	for (size_t i = 0; i < str.size(); i++)
	{
		if (num != "" && str[i] == ' ')
		{
			bool err;
			values.push_back(StringToInt(num.c_str(), err));
			if (err)
			{
				//error
			}
			num = "";
		}
		else
		{
			num += str[i];
		}
	}
	return values;
}

CBody ApplyOperation(string & const line, bool & err)
{
	const string Sphere = "Sphere";
	const string Parallelepiped = "Parallelepiped";
	const string Cone = "Cone";
	const string Cylinder = "Cylinder";

	err = true;

	if (line.substr(0, Sphere.size()) == Sphere)
	{
		auto values = GetValuesFromStrings(line.substr(Sphere.size()));
		if (values.size() == 2)
		{
			return CSphere(values[0], values[1]);
		}
		else
		{
			cout << "Wrong number of parameters." << endl;
			cout << "For example: Sphere <radius> <density>" << endl;
			err = false;
		}
	}
	else if (line.substr(0, Parallelepiped.size()) == Parallelepiped)
	{
		auto values = GetValuesFromStrings(line.substr(Parallelepiped.size()));
		if (values.size() == 4)
		{
			return CParallelepiped(values[0], values[1], values[2], values[3]);
		}
		else
		{
			cout << "Wrong number of parameters." << endl;
			cout << "For example: Parallelepiped <width> <height> <depth> <density>" << endl;
			err = false;
		}
	}
	else if (line.substr(0, Cone.size()) == Cone)
	{
		auto values = GetValuesFromStrings(line.substr(Cone.size()));
		if (values.size() == 3)
		{
			return CCone(values[0], values[1], values[2]);
		}
		else
		{
			cout << "Wrong number of parameters." << endl;
			cout << "For example: Cone <radius> <height> <density>" << endl;
			err = false;
		}
	}
	else if (line.substr(0, Cylinder.size()) == Cylinder)
	{
		auto values = GetValuesFromStrings(line.substr(Cylinder.size()));
		if (values.size() == 3)
		{
			return CCylinder(values[0], values[1], values[2]);
		}
		else
		{
			cout << "Wrong number of parameters." << endl;
			cout << "For example: Cylinder <radius> <height> <density>" << endl;
			err = false;
		}
	}
	else 
	{
		cout << "Does not recognize the command." << endl;
		err = false;
	}
	return CSphere(0, 0);
}

vector<CBody> InteractionWithTheUser()
{
	const string Commpound = "Commpound";
	std::string line;
	std::vector<CBody> result;
	cout << ">";
	bool flag = false;

	while (getline(std::cin, line))
	{
		if (line == Commpound)
		{
			cout << "Entry of a composite body type exit." << endl;
			cout << ">>";
			CCompound compoundShape;
			while (true)
			{
				getline(std::cin, line);
				if (line == "exit")
				{
					result.push_back(compoundShape);
					break;
				}
				bool err;
				auto shape = ApplyOperation(line, err);
				if (err)
				{
					compoundShape.AddObject(shape);
				}
				cout << ">>";
			}
		}
		else
		{
			bool err;
			auto shape = ApplyOperation(line, err);
			if (err)
			{
				result.push_back(shape);
			}
		}
		cout << ">";
	}
	return result;
}

double GetSubmergedWeight(double p, double v)
{
	return (p - 999, 97)* 9.8 * v;
}

void PrintLargestMass(vector<CBody> const & array) 
{
	size_t length = array.size();
	size_t index = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (array[index].GetWeight() < array[i].GetWeight())
		{
			index = i;
		}
	}

	cout << "====== large mass ======" << endl;
	array[index].ShowDate();
	cout << "========================" << endl;

	index = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (GetSubmergedWeight(array[index].GetDensityt(), array[index].GetVolume()) > GetSubmergedWeight(array[i].GetDensityt(), array[i].GetVolume()))
		{
			index = i;
		}
	}

	cout << "=== easiest in water ===" << endl;
	array[index].ShowDate();
	cout << "========================" << endl;
}

int main(int argc, char* argv[])
{
	auto array = InteractionWithTheUser();
	PrintLargestMass(array);
	system("pause");
	return 0;
}

