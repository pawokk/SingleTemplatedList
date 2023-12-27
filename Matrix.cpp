#include "Matrix.h"
#include <vector>
#include <string>
#include<sstream>
matrix::Matrix::Matrix(int rows,int cols) :
	rows(rows), cols(cols), matrix(rows, Row(cols))
{

}
matrix::Matrix::Matrix(int rows, int cols, Generator* generator):
	rows(rows), cols(cols),generator(generator), matrix(rows,Row(cols))
{
	if (rows <= 0 or cols <= 0 or generator==nullptr) {
		throw std::out_of_range("Error");
	}	
	else{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = generator->generate();
			}
		}
	}
	
}


std::string matrix::Matrix::MatrixToString()
{
	std::stringstream buffer;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			buffer << matrix[i][j] << ' ';
		}
		buffer << std::endl;
	}
	return buffer.str();
}
Row& matrix::Matrix::operator[](const int index)
{
	return matrix[index];
}

int matrix::Matrix::Get_rows()
{
	return rows;
}

int matrix::Matrix::Get_cols()
{
	return cols;
}


std::ostream& matrix::operator<<(std::ostream& os, const Matrix& mat)
{
	for (const Row& row : mat.matrix) {
		os << row << '\n';
	}
	return os;
}

