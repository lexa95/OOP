#include "stdafx.h"
#include "Body.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;
typedef boost::shared_ptr<CBody> SPtr;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

vector<string> SplitString(string line, string const& separator)
{
	vector<string> result;

	line += separator;
	string str = "";
	size_t i = 0;
	while (i < line.size())
	{
		if (separator == line.substr(i, separator.size()))
		{
			if (str != "")
			{
				result.push_back(str);
			}
			str = "";
			i += separator.size();
		}
		else
		{
			str += line[i];
			i++;
		}
	}
	return result;
}

vector<int> GetArrayIntFromArrayString(vector<string> array, bool & err)
{
	vector<int> result;

	for (size_t i = 0; i < array.size(); i++)
	{
		auto value = StringToInt(array[i].c_str(), err);

		if (err)
		{
			break;
		}

		result.push_back(value);
	}

	return result;
}

SPtr ApplyOperation(string const& line, bool & err, istream & input)
{
	const string Sphere = "Sphere";
	const string Parallelepiped = "Parallelepiped";
	const string Cone = "Cone";
	const string Cylinder = "Cylinder";
	const string Commpound = "Commpound"; 
	
	if (line.substr(0, Sphere.size()) == Sphere)
	{
		auto values = GetArrayIntFromArrayString(SplitString(line.substr(Sphere.size()), " "), err);

		if (values.size() == 2 && !err)
		{
			err = true;
			return SPtr(new CSphere(values[0], values[1]));
		}
		else
		{
			cout << "Wrong number of parameters." << endl;
			cout << "For example: Sphere <radius> <density>" << endl;
			err = false;
		}
	}
	else if (line.substr(0, Parallelepiped.size()) == Parallelepiped )
	{
		auto values = GetArrayIntFromArrayString(SplitString(line.substr(Parallelepiped.size()), " "), err);
		if (values.size() == 4 && !err)
		{
			err = true;
			return SPtr(new CParallelepiped(values[0], values[1], values[2], values[3]));
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
		auto values = GetArrayIntFromArrayString(SplitString(line.substr(Cone.size()), " "), err);
		if (values.size() == 3 && !err)
		{
			err = true;
			return SPtr(new CCone(values[0], values[1], values[2]));
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
		auto values = GetArrayIntFromArrayString(SplitString(line.substr(Cylinder.size()), " "), err);
		if (values.size() == 3 && !err)
		{
			err = true;
			return SPtr(new CCylinder(values[0], values[1], values[2]));
		}
		else
		{
			cout << "Wrong number of parameters." << endl;
			cout << "For example: Cylinder <radius> <height> <density>" << endl;
			err = false;
		}
	}
	else if (line.substr(0, Commpound.size()) == Commpound)
	{
		SPtr shape(new CCompound);
		CCompound * temp = dynamic_cast<CCompound*>(shape.get());
		string str;
		while (getline(input, str))
		{
			if ("exit" == str)
			{
				break;
			}

			auto addShape = ApplyOperation(str, err, input);
			if (err)
			{
				(*temp).AddShape(addShape);
			}
		}
		return shape;
	}
	else
	{
		cout << "Does not recognize the command." << endl;
		err = false;
	}
	return SPtr();
}

template <typename T>
void AddShapes(istream & input, T & shapes)
{
	std::string line;
	bool err;

	while (getline(input, line))
	{
		auto shape = ApplyOperation(line, err, input);
		if (err)
		{
			shapes.push_back(shape);
		}
	}
}

double GetSubmergedWeight(double p, double v)
{
	return (p - 1000)* 9.8 * v;
}

void PrintLargestMass(vector<SPtr> const & array, std::ostream& output)
{
	size_t length = array.size();
	size_t index = 0;
	for (size_t i = 0; i < length; i++)
	{
		if ((*array[index].get()).GetWeight() < (*array[i].get()).GetWeight())
		{
			index = i;
		}
	}

	(*array[index].get()).ShowDate(output);
}

void PrintEasiestInWater(vector<SPtr> const & array, std::ostream& output)
{
	size_t length = array.size();
	size_t index = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (GetSubmergedWeight((*array[index].get()).GetDensity(), (*array[index].get()).GetVolume())
	> GetSubmergedWeight((*array[i].get()).GetDensity(), (*array[i].get()).GetVolume()))
		{
			index = i;
		}
	}
	(*array[index].get()).ShowDate(output);
}

void PrintLargestMassAndEasiestInWater(vector<SPtr> const & array, std::ostream& output)
{
	if (array.size() != 0)
	{
		output << "====== large mass ======" << endl;
		PrintLargestMass(array, output);
		output << "========================" << endl;

		output << "=== easiest in water ===" << endl;
		PrintEasiestInWater(array, output);
		output << "========================" << endl;
	}
}

void ShowdData(vector<SPtr> const& shapes)
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		(*shapes[i].get()).ShowDate(cout);
		cout << "Mass in water = "<< GetSubmergedWeight((*shapes[i].get()).GetDensity(), (*shapes[i].get()).GetVolume()) << endl;
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	vector<SPtr> shapes;

	if (argc == 1)
	{
		AddShapes(std::cin, shapes);
	}
	else if (argc == 2 || argc == 3)
	{
		std::ifstream file(argv[1]);
		if (!file.is_open())
		{
			std::cout << "Could not open file" << endl;
			return 1;
		}
		AddShapes(file, shapes);
		file.close();

		if (argc == 3)
		{
			ofstream outFile(argv[2]);
			PrintLargestMassAndEasiestInWater(shapes, outFile);
			outFile.close();
		}
		else
		{
			PrintLargestMassAndEasiestInWater(shapes, std::cout);
		}
	}
	else
	{
		cout << "incorrect number of parameters" << endl;
		return 1;
	}

	//ShowdData(shapes);
	return 0;
}