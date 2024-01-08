#include "Matrix.h"
#include <vector>
#include <string>
#include<sstream>

matrix::Matrix::Matrix(size_t rows, size_t cols, Generator* generator):
	rows(rows), cols(cols),generator(generator), matrix(rows,Row(cols))
{
	if (rows <= 0 or cols <= 0 or generator==nullptr) {
		throw std::out_of_range("Error");
	}	
	
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			matrix[i][j] = generator->generate();
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

Row& matrix::Matrix::operator[](const size_t index)
{
	if (index >= matrix.size()) {
			throw std::out_of_range("Error");
	}
	return matrix[index];
	
}

size_t matrix::Matrix::Get_rows()
{
	return rows;
}

size_t matrix::Matrix::Get_cols()
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