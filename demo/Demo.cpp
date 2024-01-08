#include <vector>
#include <string>
#include <iostream>
#include"..//mtarix/Matrix.h"
#include"..//mtarix/RandomGenerator.h"
#include "..//mtarix/Task.h"
using namespace matrix;

int main() {
	setlocale(LC_ALL, "rus");
	RandomGenerator rg(1, 10);
	Matrix m1(2, 2, &rg);
	std::cout << m1 << "\n";
	Task t(m1, &rg);
	Matrix m2 = t.getTask1();
	std::cout << m2 << "\n";
	return 1;
}
