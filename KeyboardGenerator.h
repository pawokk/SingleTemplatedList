#pragma once

#include"Generator.h"
class KeyboardGenerator : public Generator {
private:
    std::istream& in;

public:
    KeyboardGenerator(std::istream& in = std::cin);

    int generate() override;
};