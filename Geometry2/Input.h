#pragma once
#include "pch.h"
class Input {
private:
    // std::ifstream myFile(char**);
    std::string sStart = "", sName, sCoordinate;
    char** argv;
    std::vector<std::unique_ptr<Figure>> figurki;

public:
    Input(char**);
    Input(std::string);

    void getVerifyInput(char**);
    void getVerifyInput(std::string);

    ~Input() = default;
};
