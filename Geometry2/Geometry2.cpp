// Geometry2.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    {
        string sStart,
            sName,
            sCoordinate;

        //Входные данные//
        cin >> sStart;
        {
            size_t s = sStart.size(),
                   i = 0,
                   j = 0;

            while (sStart.at(i) != '(' && i < sStart.size() - 1) {
                i++;
            }

            if (i > sStart.size() - 1) {
                cout << "ERROR 1" << endl;
                exit(123);
            }

            sName = sStart.substr(0, i);

            j = i - 1;

            while (sStart.at(j) != ')' && j < sStart.size() - 1) {
                j++;
            }

            if (sStart.at(sStart.size() - 1) != ')') {
                cout << "ERROR 2" << endl;
                exit(123);
            }

            sCoordinate = sStart.substr(i + 1, j - i - 1);
            cout << "Со скобочками все ОК" << endl;
        }

		

		vector<tCircle> vCircle;
        vector<tTrinagle> vTrinagle;
		vector<tPoligone> vPoligone;

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
}