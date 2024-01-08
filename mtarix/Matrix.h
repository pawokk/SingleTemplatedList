#pragma once
#include "Row.h"
#include "Generator.h"
#include <iostream>
namespace  matrix {
	class Matrix {
		public:
			//конструктор с строками, столбцами и генератором
			Matrix(size_t rows, size_t cols, Generator* generator);		
			std::string MatrixToString();
			friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
			Row& operator[](const size_t index);
			size_t Get_rows();
			size_t Get_cols();

		private:
			std::vector<Row>matrix;
			size_t rows;
			size_t cols;
			Generator* generator;
	};
}