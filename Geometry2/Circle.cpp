#include "Circle.h"
#include "pch.h"

Circle::Circle(std::string s, std::string n) : coordinats(s), fullName(n)
{
    setPoint(coordinats);
}

void Circle::setPoint(std::string coordinats)
{
    std::string temp = "";
    unsigned int i = 0, j = 0;

    for (i = 0, j = 0; i < coordinats.size(); i++) {
        if (coordinats.at(i) != ' ' && j == 0) {
            temp += coordinats.at(i);
        } else if (coordinats.at(i) == ' ' && j == 0) {
            if (temp == "") {
                std::cout << "> Координаты: \t ERROR!" << std::endl;
                exit(505);
            }
            x = stoi(temp);
            temp = "";
            j++;
        }

        if (coordinats.at(i) != ',' && j == 1) {
            temp += coordinats.at(i);
        } else if (coordinats.at(i) == ',' && j == 1) {
            if (temp == "") {
                std::cout << "> Координаты: \t ERROR!" << std::endl;
                exit(505);
            }
            y = stoi(temp);
            temp = "";
            j++;
            i += 2;
        }

        if (j == 2) {
            temp += coordinats.at(i);
            radius = stod(temp);
        }

        if (j != 2 && i == coordinats.size() - 1) {
            std::cout << "> Координаты: \t ERROR!" << std::endl;
            exit(505);
        }
    }
    if (j != 2) {
        std::cout << "> Координаты: \t ERROR!" << std::endl;
        exit(505);
    }
    std::cout << "> Координаты: \t OK!" << std::endl;
}

bool Circle::getError()
{
    return error;
}

std::string Circle::getFullName()
{
    return fullName;
}

std::pair<double, std::pair<int, int>> Circle::getVec1()
{
    std::pair<double, std::pair<int, int>> C;
    C.first = radius;
    C.second.first = x;
    C.second.second = y;
    return C;
}

std::vector<std::pair<int, int>> Circle::getVec()
{
    std::vector<std::pair<int, int>> TMPP;
    return TMPP;
}

std::string Circle::getName()
{
    return "Circle.";
}

double Circle::getSquare()
{
    return radius * radius * M_PI;
}

double Circle::getPerimetr()
{
    return 2 * M_PI * radius;
}

// Circle::~Circle()
//{
//}
