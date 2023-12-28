#include "Task.h"
#include "Generator.h"
#include "RandomGenerator.h"
#include <cmath>
#include <vector>
Task::Task(matrix::Matrix matrix, Generator* generator) :
	matrix(matrix),generator(generator)
{

}

matrix::Matrix Task::getTask1()	{
	int cols = matrix.Get_cols();
	int rows = matrix.Get_rows();
	for (size_t row = 0; row < rows; row++) {
		for (size_t column = 0; column < cols; column++) {
			if (matrix[row][column] % 2 == 0)
			{
				matrix[row][column] = 0;
			}
			else
			{
				matrix[row][column] = matrix[row][column];
			}
		}
	}
	return matrix;
}
int Task::getMinElement()
{
	int cols = matrix.Get_cols();
	int rows = matrix.Get_rows();
	int min = matrix[0][0];
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t column = 0; column < cols; column++)
		{
			if (matrix[row][column] < min)
			{
				min = matrix[row][column];
			}
		}
	}
	return min;
}

matrix::Matrix Task::getTask2()
{
	bool flag = true;
	size_t rows = matrix.Get_rows();
	size_t cols = matrix.Get_cols();
	this->odd = CountNewMatrixRows();
	matrix::Matrix matrix2(rows+odd.size(), cols, generator);
	rows = matrix2.Get_rows();
	cols = matrix2.Get_cols();
	int coun = 0;
	flag = true;
	for (size_t row = 0; row < rows; row++) {
		for (size_t col = 0; col < cols; col++) {
			if (contains(row)) {
				if (flag == 1) {
					coun++;
				}
				matrix2[row][col] = col + 1;
				flag = false;
			}
			else {
				flag = 1;
				matrix2[row][col] = matrix[row-coun][col];
			}
		}
	}
	
	return matrix2;
}

bool Task::contains(int number)
{
	for (int i : odd) {
		if (i == number) {
			return true; 
		}
	}
	return false;
}
std::vector<int> Task::CountNewMatrixRows() {
	bool flag = true;
	size_t rows = matrix.Get_rows();
	std::vector<int> odd;
	size_t cols = matrix.Get_cols();
	int min = getMinElement();
	for (size_t row = 0; row < rows; row++) {
		for (size_t col = 0; col < cols; col++) {
			if (matrix[row][col] == min && flag) {
				odd.push_back(row + 1);
				flag = false;
			}

		}
		flag = true;
	}
	return odd;
}