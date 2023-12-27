#pragma once
#include <vector>
#include <iostream>

class Row {
	public:
		Row();
		Row(int cols);

		int& operator[](const int index);
		friend std::ostream& operator<<(std::ostream& os, const Row& row);

private:
	std::vector<int>row;

};