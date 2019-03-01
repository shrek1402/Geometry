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

    {
        if (sName == "trinagle") {
            cout << "trinagle" << endl;
        }

        else if (sName == "circle") {
            cout << "#Фигура:\t circle" << endl;
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
        Poligone(string c)
            : coordinats(c)
        {
        }

		double getSquare() override
        {
            return 0;
        }

        double getPerimetr() override
        {
            return 0;
        }

        void setPoint() override
        {
            string tmp1 = "";
            bool flag = 0;
            typedef pair<int, int> c; // сделать массив векторов
            vector<pair<int, int>> C;
            for (size_t i = 0, j = 0; i < coordinats.size(); i++) {
                if (coordinats.at(i) == ' ') {
                    C[j].first = stoi(tmp1);
                    tmp1 = "";
                    j++;
                    //flag = 1;                                                     TODO
                } else if (coordinats.at(i) == ',') {
                    C[j].second = stoi(tmp1);
                    tmp1 = "";
                    j++;
                } else if (i == coordinats.size() - 1) {
                    tmp1 += coordinats.at(i);
                    C[j].second = stoi(tmp1);
                    j++;
                } else {
                    tmp1 += coordinats.at(i);
                }
                // сделать проверку <0, int>
            }
            for (size_t i = 0; i < C.size() - 1; i++) {
                cout << C.at(i).first << " " << C.at(i).second << endl;
            }
        }
    };

    //////////////////////////////////////////////  MAIN  ////////////////////////////////////////////////////

    Circle circle(sCoordinate);

    circle.setPoint();

    cout << circle.getPerimetr()
         << endl;

    cout << circle.getSquare()
         << endl;

    Poligone poligone(sCoordinate);

	poligone.setPoint();
}