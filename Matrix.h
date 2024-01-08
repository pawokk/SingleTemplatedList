#pragma once
#include "Row.h"
#include "Generator.h"
#include <iostream>
namespace  matrix {
	class Matrix {
		public:
			Matrix(int rows, int cols, Generator* generator);
			
			
			
			std::string MatrixToString();

			friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
			
			Row& operator[](const size_t index);
			int Get_rows();
			int Get_cols();

		private:
			std::vector<Row>matrix;
			int rows;
			int cols;
			Generator* generator;
	};
}
