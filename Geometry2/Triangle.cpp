#include "pch.h"
#include "Triangle.h"


Triangle::Triangle(std::string s, std::string n)
    : coordinats(s)
    , fullName(n)
{
    setPoint(coordinats);
}

bool Triangle::getError()
{
    return error;
}

std::string Triangle::getFullName()
{
    return fullName;
}

std::pair<double, std::pair<int, int>> Triangle::getVec1()
{
    std::pair<double, std::pair<int, int>> TEMP;
    return TEMP;
}

std::vector<std::pair<int, int>> Triangle::getVec()
{
    return C;
}

std::string getName()
{
    return "Triangle.";
}

double Triangle::getSquare()
{
    return abs(((C.at(1).first - C.at(0).first) * (C.at(2).second - C.at(0).second)
                   - (C.at(2).first - C.at(0).first) * (C.at(1).second - C.at(0).second))
        / 2.0);
}

double Triangle::getPerimetr()
{
    return sqrt((C.at(1).first - C.at(0).first) * (C.at(1).first - C.at(0).first) //sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
               + (C.at(1).second - C.at(0).second) * (C.at(1).second - C.at(0).second)) // +
        + sqrt((C.at(2).first - C.at(0).first) * (C.at(2).first - C.at(0).first) //sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))
              + (C.at(2).second - C.at(0).second) * (C.at(2).second - C.at(0).second)) // +
        + sqrt((C.at(2).first - C.at(1).first) * (C.at(2).first - C.at(1).first) //sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))
              + (C.at(2).second - C.at(1).second) * (C.at(2).second - C.at(1).second));
    //Прости меня, Бог рандома, за такой код =(
}

void Triangle::setPoint(std::string coordinats)
{
    std::string tmp1 = "", tmp2 = "";
    bool flag = true;

    for (size_t i = 0, j = 0; i < coordinats.size(); i++) {
        std::pair<int, int> tmpPair;

        if (coordinats.at(i) == ' ' && coordinats.at(i - 1) != ',') { // poligone(1 2, 3 4, 5 6, 7 8, 9 0)
            flag = false;

        } else if (coordinats.at(i) == ',') {

            tmpPair.first = stoi(tmp1);
            tmpPair.second = stoi(tmp2);
            C.push_back(tmpPair);
            tmp1 = "";
            tmp2 = "";
            flag = true;

        } else if (i == coordinats.size() - 1) {

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
    if (C.size() == 3)
        std::cout << "> Координаты: \t OK!" << std::endl;
    else {
        std::cout << "> Координаты: \t ERROR!" << std::endl;
        exit(505);
    }
}

//Triangle::~Triangle()
//{
//}
