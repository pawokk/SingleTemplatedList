#pragma once
#include <random>
#include"Generator.h"

class RandomGenerator : public Generator {
private:
    std::uniform_int_distribution<int> distribution;
    std::mt19937 generator;
public:
    RandomGenerator(const int min, const int max);


    // Реализация функции генерации случайного числа
    int generate() override;
};