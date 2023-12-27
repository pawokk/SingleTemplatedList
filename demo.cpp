#include <vector>
#include <string>
#include <iostream>
#include "Matrix.h"
#include "RandomGenerator.h"

#include "Task.h"
using namespace matrix;

int main() {
	setlocale(LC_ALL, "rus");
	RandomGenerator rg(1, 100);
	Matrix m1(4, 4, &rg);
	std::cout << m1<<"\n";
	Task t(m1);
	Matrix m2 = t.getTask2();
	std::cout << m2<<"\n";

	m1 = t.getTask1();
	std::cout << m1 << "\n";
	
	return 1;
}
