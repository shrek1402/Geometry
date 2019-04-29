#include "Poligone.h"
#include "pch.h"

Poligone::Poligone(std::string s, std::string n) : coordinats(s), fullName(n)
{
    setPoint(coordinats);
}

bool Poligone::getError()
{
    return error;
}

std::string Poligone::getFullName()
{
    return fullName;
}

std::pair<double, std::pair<int, int>> Poligone::getVec1()
{
    std::pair<double, std::pair<int, int>> C;
    return C;
}

std::vector<std::pair<int, int>> Poligone::getVec()
{
    return C;
}

std::string Poligone::getName()
{
    return "Poligone.";
}

double Poligone::getSquare()
{
    double result = 0;
    for (size_t i = 0; i < C.size(); i++) {
        if (i < C.size() - 1) {
            result += C.at(i).first * C.at(i + 1).second
                    - C.at(i + 1).first
                            * C.at(i).second; // x1y2 - x2y1  01 10 12 21 23 32
        } else {
            result += C.at(i).first * C.at(0).second
                    - C.at(0).first * C.at(i).second;
        }
    }
    return abs(result / 2.0);
}

double Poligone::getPerimetr()
{
    double result = 0;
    for (size_t i = 0; i < C.size(); i++) {
        if (i < C.size() - 1) {
            result
                    += sqrt((C.at(i + 1).first - C.at(i).first)
                                    * (C.at(i + 1).first - C.at(i).first)
                            + (C.at(i + 1).second - C.at(i).second)
                                    * (C.at(i + 1).second - C.at(i).second));
        } else if (i = C.size() - 1) {
            result
                    += sqrt((C.at(0).first - C.at(i).first)
                                    * (C.at(0).first - C.at(i).first)
                            + (C.at(0).second - C.at(i).second)
                                    * (C.at(0).second - C.at(i).second));
        }
    }
    return result;
}

void Poligone::setPoint(std::string coordinats)
{
    std::string tmp1 = "", tmp2 = "";
    bool flag = true;

    for (size_t i = 0, j = 0; i < coordinats.size(); i++) {
        std::pair<int, int> tmpPair;

        if (coordinats.at(i) == ' '
            && coordinats.at(i - 1)
                    != ',') { // poligone(1 2, 3 4, 5 6, 7 8, 9 0)
            flag = false;

        } else if (coordinats.at(i) == ',') {
            if (tmp1 == "" || tmp2 == "") {
                std::cout << "> Координаты: \t ERROR!" << std::endl;
                exit(505);
            }
            tmpPair.first = stoi(tmp1);
            tmpPair.second = stoi(tmp2);
            C.push_back(tmpPair);
            tmp1 = "";
            tmp2 = "";
            flag = true;

        } else if (i == coordinats.size() - 1) {
            if (tmp1 == "") {
                std::cout << "> Координаты: \t ERROR!" << std::endl;
                exit(505);
            }
            tmp2 += coordinats.at(i);
            tmpPair.first = stoi(tmp1);
            tmpPair.second = stoi(tmp2);
            C.push_back(tmpPair);

        } else if (coordinats.at(i) != ',') {
            if (flag)
                tmp1 += coordinats.at(i);
            else
                tmp2 += coordinats.at(i);
        }
        // сделать проверку <0, int>
    }
    if (coordinats.size() == 0) {
        std::cout << "> Координаты: \t ERROR!" << std::endl;
        exit(505);
    } else
        std::cout << "> Координаты: \t OK!" << std::endl;
}

Poligone::~Poligone()
{
}
