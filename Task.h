#pragma once
#include <iostream>
#include "Matrix.h"

 
class Task {
public:
	Task(matrix::Matrix matrix);
	matrix::Matrix getTask1();
	int getMinElement();
	matrix::Matrix getTask2();
	bool isNumberInVector(const std::vector<int>& vec, int number);
private:
	matrix::Matrix matrix;
	
};