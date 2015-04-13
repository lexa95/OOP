#include "stdafx.h"
#include "Body.h"

int main(int argc, char* argv[])
{
	CSphere test(10, 5);
	test.ShowDate();

	CParallelepiped t(4, 4, 8, 10);
	t.ShowDate();

	CCylinder t2(2, 2, 10);
	t2.ShowDate();

	CCompound M(t2);
	M.AddObject(test);
	M.AddObject(t2);
	M.ShowDate();

	system("pause");
	return 0;
}

