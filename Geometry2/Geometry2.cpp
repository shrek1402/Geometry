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

    /*struct node {
        string nFigure;
        vector<int> A;
    }; */

    string sStart,
        sName,
        sCoordinate;

    //////////////////////////////////////////////  INPUT DATA  ////////////////////////////////////////////////////
    getline(cin,sStart);
    {
        size_t* s = new size_t(sStart.size());
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

        cout << "#Скобочки: \t ОК! (А может и не ОК)." << endl;
    }
    //////////////////////////////////////////////  LOGICK  ////////////////////////////////////////////////////

    {
        if (sName == "trinagle") {
            cout << "trinagle" << endl;
        }

        else if (sName == "circle") {
            cout << "circle" << endl;
        }

        else if (sName == "poligone") {
            cout << "poligone" << endl;
        }

        else {
            cout << "ERROR" << endl;
            exit(404);
        }
    }

    //////////////////////////////////////////////  CLASSES  ////////////////////////////////////////////////////
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
    //                                                         TODO

    class Circle : public Figure {
    private:
        int x, y;
        double radius;
        string coordinats;

    public:
        Circle(string c, int _x, int _y, double r)
            : coordinats(c)
            , x(_x)
            , y(_y)
            , radius(r)
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
            string tmp1, tmp2;
            pair<int, int> c;

            for (size_t i = 0; i < coordinats.size(); i++) {
                if (coordinats.at(i) == ' ') {
                    c.first = stoi(tmp1); //c[i].first =
                    tmp1 = "";
                } else if (coordinats.at(i) == ',') {
                    c.second = stoi(tmp1); //c[i].first =                          TODO
                    tmp1 = "";
					}
                    else if (i == coordinats.size() - 1)
                    {
                        c.second = stoi(tmp1); //c[i].first =                          TODO
                        tmp1 = "";
                } else {
                    tmp1 += coordinats.at(i); // 1234 123, 23 21, 11 34
                }
            }
            cout << c.first << "  " << c.second << endl;
        }
    };

    //////////////////////////////////////////////  MAI  ////////////////////////////////////////////////////

    int x = 2, y = 2;
    double R = 1;
    Circle circle(sCoordinate, x, y, R);

    cout << circle.getPerimetr()
         << endl;

    cout << circle.getSquare()
         << endl;

    circle.setPoint();
}