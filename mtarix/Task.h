#pragma once
#include <iostream>
#include "..//mtarix/Matrix.h"

 
class Task {
public:
	Task(matrix::Matrix matrix,Generator* generator);
	matrix::Matrix getTask1();
	int getMinElement();
	matrix::Matrix getTask2();
	bool contains(int number);
	std::vector<int> CountNewMatrixRows();
private:
	matrix::Matrix matrix;
	Generator* generator;
	std::vector<int>odd;
};