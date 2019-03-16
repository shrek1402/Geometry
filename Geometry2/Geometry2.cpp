#include "Circle.h"
#include "Figure.h"
#include "Poligone.h"
#include "Triangle.h"
#include "pch.h"
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    string sStart = "", sName, sCoordinate;

    vector<std::unique_ptr<Figure> > figurki;

    //Считывает данные

    /*ifstream myFile;
  bool file = false;
  if (argc > 1) {
          ifstream myFile(argv[1]);
          if (myFile.is_open()) {
                  file = true;
          }
  }
          */
    ifstream myFile(argv[1]);
    while (sStart != "0") {
        //  if (!file)
        //getline(cin, sStart);
        // else

        getline(myFile, sStart);

        unsigned int i = 0, j = 0;
        if (sStart != "0") {
            while (sStart.at(i) != '(' && i < sStart.size() - 1) {
                i++;
            }

            if (i >= sStart.size()) {
                cout << "> Скобочки: \t ERROR!" << endl;
                exit(123);
            }

            sName = sStart.substr(0, i);

            j = i - 1;

            while (sStart.at(j) != ')' && j <= sStart.size() - 1) {
                j++;
            }

            if (sStart.at(sStart.size() - 1) != ')') {
                cout << "> Скобочки: \t ERROR!" << endl;
                exit(123);
            }

            sCoordinate = sStart.substr(i + 1, j - i - 1);

            cout << "> Скобочки: \t ОК!" << endl; // TODO
        }
        if (sName == "triangle") {
            figurki.push_back(make_unique<Triangle>(sCoordinate, sStart));
            cout << "> Фигура: \t OK!" << endl;
        }

        else if (sName == "circle") {
            figurki.push_back(make_unique<Circle>(sCoordinate, sStart));
            cout << "> Фигура: \t OK!" << endl;
        }

        else if (sName == "poligone") {
            figurki.push_back(make_unique<Poligone>(sCoordinate, sStart));
            cout << "> Фигура: \t OK!" << endl;
        }
        sName = "";
    }
    system("cls");

    unsigned int function, func;
    string sFunction, sFunc;

    for (function = 0; function < figurki.size(); function++) {
        cout << function + 1 << ". " << figurki[function]->getFullName() << endl;
    }
    cout << endl;

    for (function = 0; function < figurki.size(); function++) {
        vector<pair<int, int> > temp1;
        vector<pair<int, int> > temp2;
        pair<double, pair<int, int> > temp3;
        pair<double, pair<int, int> > temp4;
        pair<pair<int, int>, pair<int, int> > vector1;
        pair<pair<int, int>, pair<int, int> > vector2;
        cout << endl;
        cout << function + 1 << ". " << figurki[function]->getFullName() << endl;

        cout << "    Perimeter = " << figurki[function]->getPerimetr() << endl;
        cout << "    Area = " << figurki[function]->getSquare() << endl;
        cout << "    Intersects:" << endl;
        bool fl = false;

        if (figurki[function]->getName() != "Circle.")
            temp1 = figurki[function]->getVec();
        else
            temp3 = figurki[function]->getVec1();

        sFunction = figurki[function]->getName();

        if (function < figurki.size()) {
            for (func = 0; func < figurki.size(); func++) {
                if (func != function) {
                    if (figurki[func]->getName() != "Circle.") {
                        temp2 = figurki[func]->getVec();
                    } else {
                        temp4 = figurki[func]->getVec1();
                        fl = true;
                    }

                    sFunc = figurki[func]->getName();

                    if ((sFunction == "Triangle." && sFunc == "Poligone.") || (sFunction == "Triangle." && sFunc == "Triangle.") || (sFunction == "Poligone." && sFunc == "Triangle.") || (sFunction == "Poligone." && sFunc == "Poligone.")) {
                        for (size_t i = 0; i < temp1.size(); i++) {
                            if (i < temp1.size() - 1) {
                                vector1.first.first = temp1[i].first;
                                vector1.first.second = temp1[i].second;
                                vector1.second.first = temp1[i + 1].first;
                                vector1.second.second = temp1[i + 1].second;
                            } else {
                                vector1.first.first = temp1[i].first;
                                vector1.first.second = temp1[i].second;
                                vector1.second.first = temp1[0].first;
                                vector1.second.second = temp1[0].second;
                            }

                            for (unsigned int j = 0; j < temp2.size(); j++) {
                                if (j < temp2.size() - 1) {
                                    vector2.first.first = temp2[j].first;
                                    vector2.first.second = temp2[j].second;
                                    vector2.second.first = temp2[j + 1].first;
                                    vector2.second.second = temp2[j + 1].second;
                                } else {
                                    vector2.first.first = temp2[j].first;
                                    vector2.first.second = temp2[j].second;
                                    vector2.second.first = temp2[0].first;
                                    vector2.second.second = temp2[0].second;
                                }

                                int x1 = vector1.first.first;
                                int y1 = vector1.first.second;
                                int x2 = vector1.second.first;
                                int y2 = vector1.second.second;
                                int x3 = vector2.first.first;
                                int y3 = vector2.first.second;
                                int x4 = vector2.second.first;
                                int y4 = vector2.second.second;
                                int denominator = (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);

                                if (denominator == 0) {
                                    if (((x1 >= x3 && x1 <= x4 || x1 <= x3 && x1 >= x4) && (y1 >= y3 && y1 <= y4 || y1 <= y3 && y1 >= y4)) || ((x2 >= x3 && x2 <= x4 || x2 <= x3 && x2 >= x4) && (y2 >= y3 && y2 <= y4 || y2 <= y3 && y2 >= y4))) {
                                        if ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1) == 0 && (x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1) == 0) {
                                            cout << "      " << func + 1 << ". " << figurki[func]->getName() << endl;
                                            i = temp1.size() - 1;
                                            break;
                                        }
                                    }

                                } else {
                                    int numerator_a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
                                    int numerator_b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
                                    double Ua = 1.0 * numerator_a / denominator;
                                    double Ub = 1.0 * numerator_b / denominator;
                                    if (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1) {
                                        cout << "      " << func + 1 << ". "
                                             << figurki[func]->getName() << endl;
                                        i = temp1.size() - 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    else if ((sFunction == "Circle." && sFunc == "Poligone.") || (sFunction == "Circle." && sFunc == "Triangle.") || (sFunction == "Poligone." && sFunc == "Circle.") || (sFunction == "Triangle." && sFunc == "Circle.")) {
                        if (!fl)
                            temp1 = temp2;
                        {
                            for (unsigned int i = 0; i < temp1.size(); i++) {
                                if (i < temp1.size() - 1) {
                                    vector1.first.first = temp1[i].first;
                                    vector1.first.second = temp1[i].second;
                                    vector1.second.first = temp1[i + 1].first;
                                    vector1.second.second = temp1[i + 1].second;
                                } else {
                                    vector1.first.first = temp1[i].first;
                                    vector1.first.second = temp1[i].second;
                                    vector1.second.first = temp1[0].first;
                                    vector1.second.second = temp1[0].second;
                                }
                                if (fl)
                                    temp3 = temp4;

                                double r = temp3.first;
                                int x0 = temp3.second.first;
                                int y0 = temp3.second.second;
                                int x1 = vector1.first.first;
                                int y1 = vector1.first.second;
                                int x2 = vector1.second.first;
                                int y2 = vector1.second.second;

                                double H = abs(((x2 - x1) * (y0 - y1) - (y2 - y1) * (x0 - x1)) / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
                                if (H <= r) {
                                    cout << "      " << func + 1 << ". "
                                         << figurki[func]->getName() << endl;
                                    break;
                                }
                            }
                        }

                    }

                    else if ((sFunction == "Circle." && sFunc == "Circle.")) {
                        double H = sqrt((temp3.second.first - temp4.second.first) * (temp3.second.first - temp4.second.first) + (temp3.second.second - temp4.second.second) * (temp3.second.second - temp4.second.second));
                        if (H <= temp3.first + temp4.first) {
                            cout << "      " << func + 1 << ". " << figurki[func]->getName()
                                 << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
}