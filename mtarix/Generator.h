#pragma once
#include <iostream>
#include <random>

class Generator {
public:
    virtual int generate() = 0;

    
    virtual ~Generator() = 0 {};
};