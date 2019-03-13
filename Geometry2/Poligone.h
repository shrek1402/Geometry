#pragma once
#include "Figure.h"
class Poligone : public Figure {

private:
    int x, y;
    double radius;
    std::string coordinats;
    std::string fullName;
    bool error = true;
    std::vector<std::pair<int, int>> C;

public:
    Poligone(std::string, std::string);

    std::string getFullName() override;
    std::string getName() override;
    double getSquare() override;
    double getPerimetr() override;
    void setPoint(std::string) override;
    bool getError() override;

    std::vector<std::pair<int, int>> getVec() override;
    std::pair<double, std::pair<int, int>> getVec1() override;

    ~Poligone();
};
