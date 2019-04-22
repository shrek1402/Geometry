#pragma once
#include "pch.h"
#include "Figure.h"

class Triangle : public Figure {

private:
    std::vector<std::pair<int, int> > C;
    int x, y;
    double radius;
    std::string coordinats;
    std::string fullName;
    bool error = true;

public:
    Triangle(std::string, std::string);

    std::string getFullName() override;
    std::string getName() override;
    double getSquare() override;
    double getPerimetr() override;
    void setPoint(std::string) override;
    bool getError() override;

    std::vector<std::pair<int, int> > getVec() override;
    std::pair<double, std::pair<int, int> > getVec1() override;


    ~Triangle() = default;
};
