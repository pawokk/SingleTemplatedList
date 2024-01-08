#pragma once
#include <vector>
#include <iostream>

class Row {
	public:
		//конструктор по умолчанию
		Row();
		//коструктор с входящим кол-вом столбцов
		Row(int cols);

		int& operator[](const size_t index);
		friend std::ostream& operator<<(std::ostream& os, const Row& row);

private:
	std::vector<int>row;

};