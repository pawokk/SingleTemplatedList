#include "Task.h"
#include <cmath>
#include <vector>
Task::Task(matrix::Matrix matrix) :
	matrix(matrix)
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
	int flag = 1;
	int rows = matrix.Get_rows();
	std::vector<int> odd;
	int cols = matrix.Get_cols();
	int min = getMinElement();
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (matrix[row][col] == min && flag==1) {
				odd.push_back(row + 1);
				flag = 0;
			}
			
		}
		flag = 1;
	}
	matrix::Matrix m2(rows+odd.size(), cols);
	rows = m2.Get_rows();
	cols = m2.Get_cols();
	int coun = 0;
	flag = 1;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (isNumberInVector(odd, row)) {
				if (flag == 1) {
					coun++;
				}
				m2[row][col] = col + 1;
				flag = 0;
			}
			else {
				flag = 1;
				m2[row][col] = matrix[row-coun][col];
			}
		}
	}
	
	return m2;
}

bool Task::isNumberInVector(const std::vector<int>& vec, int number)
{
	for (int i : vec) {
		if (i == number) {
			return true; // ���� ����� �������, ���������� true
		}
	}
	return false;
}
