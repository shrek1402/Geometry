#pragma once
#include "Figure.h"
#include "pch.h"

class Circle : public Figure {
private:
    int x, y;
    double radius;
    std::string coordinats;
    std::string fullName;
    bool error = true;

public:
    Circle(std::string, std::string);

    std::string getFullName() override;
    std::string getName() override;
    double getSquare() override;
    double getPerimetr() override;
    void setPoint(std::string) override;
    bool getError() override;

    std::vector<std::pair<int, int>> getVec() override;
    std::pair<double, std::pair<int, int>> getVec1() override;

    ~Circle() = default;
};
