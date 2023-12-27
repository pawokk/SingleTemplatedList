#pragma once
#include <iostream>
#include <random>

class Generator {
public:
    // Виртуальная функция генерации одного числа
    virtual int generate() = 0;

     // Виртуальный деструктор
    virtual ~Generator() = 0 {};
};