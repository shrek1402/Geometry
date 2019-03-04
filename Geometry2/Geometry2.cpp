// Geometry2.cpp : Этот файл содержит функцию "main".

#include "pch.h"

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    string sStart,
        sName,
        sCoordinate;

    //////////////////////////////////////////////  INPUT DATA  ////////////////////////////////////////////////////
    getline(cin, sStart);
    {
        int i = 0,
            j = 0;

        while (sStart.at(i) != '(' && i < sStart.size() - 1) {
            i++;
        }

        if (i >= sStart.size()) {
            cout << "ERROR 1" << endl;
            exit(123);
        }

        sName = sStart.substr(0, i);

        j = i - 1;

        while (sStart.at(j) != ')' && j <= sStart.size() - 1) {
            j++;
        }

        if (sStart.at(sStart.size() - 1) != ')') {
            cout << sStart.at(sStart.size() - 1) << "ERROR 2" << endl;
            exit(123);
        }

        sCoordinate = sStart.substr(i + 1, j - i - 1);

        cout << "#Скобочки: \t ОК!" << endl; //TODO
    }
    //////////////////////////////////////////////  LOGICK  ////////////////////////////////////////////////////
    class Figure {
    public:
        //Figure();
        //~Figure();
        virtual double getSquare() = 0;
        virtual double getPerimetr() = 0;
        virtual void setPoint() = 0;
    };
    /*Figure::Figure()
   {
   }

   Figure::~Figure()
   {
   }
   */

    class Circle : public Figure {
    private:
        int x, y;
        double radius;
        string coordinats;

    public:
        Circle(string s)
            : coordinats(s)
        {
        }

        double getSquare() override
        {
            return radius * radius * M_PI;
        }

        double getPerimetr() override
        {
            return 2 * M_PI * radius;
        }

        void setPoint() override
        {
            string temp = "";
            int i = 0;

            while (coordinats.at(i) != ' ') {
                temp += coordinats.at(i);
                i++;
            }
            x = stoi(temp);
            temp = "";

            while (coordinats.at(i) != ',') {
                temp += coordinats.at(i);
                i++;
            }
            y = stoi(temp);
            temp = "";

            while (i < coordinats.size()) {
                if (coordinats.at(i) != ' ' && coordinats.at(i) != ',') {
                    temp += coordinats.at(i);
                }
                i++;
            }
            radius = stoi(temp);
            temp = "";
        }
    };

    class Poligone : public Figure {
    private:
        string coordinats;

    public:
        vector<pair<int, int>> C;
        Poligone(string c)
            : coordinats(c)
        {
        }

        double getSquare() override
        {
            double result = 0;
            for (size_t i = 0; i < C.size(); i++) {
                if (i < C.size() - 1) {
                    result += C.at(i).first * C.at(i + 1).second - C.at(i + 1).first * C.at(i).second; //x1y2 - x2y1  01 10 12 21 23 32
                } else {
                    result += C.at(i).first * C.at(0).second - C.at(0).first * C.at(i).second;
                }
            }
            return abs(result / 2.0);
        }

        double getPerimetr() override
        {
            double result = 0;
            for (size_t i = 0; i < C.size(); i++) {
                if (i < C.size() - 1) {
                    result += sqrt((C.at(i + 1).first - C.at(i).first) * (C.at(i + 1).first - C.at(i).first)
                        + (C.at(i + 1).second - C.at(i).second) * (C.at(i + 1).second - C.at(i).second));
                } else if (i = C.size() - 1) {
                    result += sqrt((C.at(0).first - C.at(i).first) * (C.at(0).first - C.at(i).first)
                        + (C.at(0).second - C.at(i).second) * (C.at(0).second - C.at(i).second));
                }
            }
            return result;
        }

        void setPoint() override
        {
            string tmp1 = "", tmp2 = "";
            bool flag = true;

            for (size_t i = 0, j = 0; i < coordinats.size(); i++) {
                pair<int, int> tmpPair;

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
            for (size_t i = 0; i < C.size(); i++) {
                cout << C.at(i).first << " " << C.at(i).second << endl;
            }
        }
    };

    class Trinagle : public Figure {
    private:
        string coordinats;

    public:
        vector<pair<int, int>> C;
        Trinagle(string c)
            : coordinats(c)
        {
        }

        double getSquare() override
        {
            return abs(((C.at(1).first - C.at(0).first) * (C.at(2).second - C.at(0).second)
                           - (C.at(2).first - C.at(0).first) * (C.at(1).second - C.at(0).second))
                / 2.0);
        }

        double getPerimetr() override
        {
            return sqrt((C.at(1).first - C.at(0).first) * (C.at(1).first - C.at(0).first) //sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
                       + (C.at(1).second - C.at(0).second) * (C.at(1).second - C.at(0).second)) // +
                + sqrt((C.at(2).first - C.at(0).first) * (C.at(2).first - C.at(0).first) //sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))
                      + (C.at(2).second - C.at(0).second) * (C.at(2).second - C.at(0).second)) // +
                + sqrt((C.at(2).first - C.at(1).first) * (C.at(2).first - C.at(1).first) //sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))
                      + (C.at(2).second - C.at(1).second) * (C.at(2).second - C.at(1).second));
            //Прости меня, Бог рандома, за такой код =(
        }

        void setPoint() override
        {
            string tmp1 = "", tmp2 = "";
            bool flag = true;
            //typedef pair<int, int> c; // сделать массив векторов
            //vector<pair<int, int>> C;

            for (size_t i = 0, j = 0; i < coordinats.size(); i++) {
                pair<int, int> tmpPair;

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
            for (size_t i = 0; i < C.size(); i++) {
                cout << C.at(i).first << " " << C.at(i).second << endl;
            }
        }
    };
    /*
    Circle circle(sCoordinate);

    circle.setPoint();

    cout << circle.getPerimetr()
         << endl;

    cout << circle.getSquare()
         << endl;

    Poligone poligone(sCoordinate);

    poligone.setPoint();

    //Trinagle trinagle(sCoordinate);

    //trinagle.setPoint();
    //cout << trinagle.getSquare() << endl;
    cout << poligone.getSquare() << endl;
	*/
    {
        vector<unique_ptr<Figure>> figurki;

        if (sName == "trinagle") {
            figurki.push_back(make_unique<Trinagle>(sCoordinate));
            cout << "#Фигура:\t OK!" << endl;
        }

        else if (sName == "circle") {
            figurki.push_back(make_unique<Circle>(sCoordinate));
            cout << "#Фигура:\t OK!" << endl;
        }

        else if (sName == "poligone") {
            figurki.push_back(make_unique<Poligone>(sCoordinate));
            cout << "#Фигура:\t OK!" << endl;
        }

        else {
            cout << "ERROR" << endl;
            exit(404);
        }

        for (auto&& function : figurki) {
            function->setPoint();
            cout << function->getPerimetr() << endl;
        }
    }

    //////////////////////////////////////////////  CLASSES  ////////////////////////////////////////////////////

    //////////////////////////////////////////////  MAIN  ////////////////////////////////////////////////////
}