
#include "pch.h"
#include "Figure.h"
#include "Circle.h"
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    string sStart = "",
           sName,
           sCoordinate;
    /*
    class //Figure {
    public:
        //Figure();
        //~Figure();
        virtual string getFullName() = 0;
        virtual string getName() = 0;
        virtual double getSquare() = 0;
        virtual double getPerimetr() = 0;
        virtual void setPoint() = 0;
        virtual bool getError() = 0;

        virtual vector<pair<int, int>> getVec() = 0;
        virtual pair<double, pair<int, int>> getVec1() = 0;
        //virtual pair<int, pair<int,double> > getVec() = 0;
    };
    /*Figure::Figure()
   {
   }

   Figure::~Figure()
   {
   }
   

    class Circle : public Figure {
    private:
        int x, y;
        double radius;
        string coordinats;
        string fullName;
        bool error = true;

    public:
        Circle(string s, string n)
            : coordinats(s)
            , fullName(n)
        {
        }

        bool getError() override
        {
            return error;
        }

        string getFullName() override
        {
            return fullName;
        }

        pair<double, pair<int, int>> getVec1() override
        {
            pair<double, pair<int, int>> C;
            C.first = radius;
            C.second.first = x;
            C.second.second = y;
            return C;
        }

        vector<pair<int, int>> getVec() override
        {
            vector<pair<int, int>> C;
            return C;
        }

        string getName() override
        {
            return "Circle.";
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
            unsigned int i = 0, j = 0;

            for (i = 0, j = 0; i < coordinats.size(); i++) {

                if (coordinats.at(i) != ' ' && j == 0) {
                    temp += coordinats.at(i);
                } else if (coordinats.at(i) == ' ' && j == 0) {

                    if (temp == "") {
                        cout << "> Координаты: \t ERROR!" << endl;
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
                        cout << "> Координаты: \t ERROR!" << endl;
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
                    cout << "> Координаты: \t ERROR!" << endl;
                    exit(505);
                }
            }
            if (j != 2) {
                cout << "> Координаты: \t ERROR!" << endl;
                exit(505);
            }
            cout << "> Координаты: \t OK!" << endl;
        }
    };
	*/
    class Poligone : public Figure {
    private:
        string coordinats;
        string fullName;
        bool error = true;

    public:
        vector<pair<int, int>> C;
        Poligone(string c, string n)
            : coordinats(c)
            , fullName(n)
        {
        }

        bool Figure::getError() override
        {
            return error;
        }

        string getFullName() override
        {
            return fullName;
        }

        pair<double, pair<int, int>> getVec1() override
        {
            pair<double, pair<int, int>> C;
            return C;
        }

        vector<pair<int, int>> getVec() override
        {
            return C;
        }

        string getName() override
        {
            return "Poligone.";
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

        void setPoint(std::string coordinats) override
        {
            string tmp1 = "", tmp2 = "";
            bool flag = true;

            for (size_t i = 0, j = 0; i < coordinats.size(); i++) {
                pair<int, int> tmpPair;

                if (coordinats.at(i) == ' ' && coordinats.at(i - 1) != ',') { // poligone(1 2, 3 4, 5 6, 7 8, 9 0)
                    flag = false;

                } else if (coordinats.at(i) == ',') {
                    if (tmp1 == "" || tmp2 == "") {
                        cout << "> Координаты: \t ERROR!" << endl;
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
                        cout << "> Координаты: \t ERROR!" << endl;
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
                cout << "> Координаты: \t ERROR!" << endl;
                exit(505);
            } else
                cout << "> Координаты: \t OK!" << endl;
        }
    };
    
    class Trinagle : public Figure {
    private:
        string coordinats;
        string fullName;
        bool error = true;

    public:
        vector<pair<int, int>> C;
        Trinagle(string c, string n)
            : coordinats(c)
            , fullName(n)
        {
        }

        bool getError() override
        {
            return error;
        }

        string getFullName() override
        {
            return fullName;
        }

        pair<double, pair<int, int>> getVec1() override
        {
            pair<double, pair<int, int>> C;
            return C;
        }

        vector<pair<int, int>> getVec() override
        {
            return C;
        }

        string getName() override
        {
            return "Trinagle.";
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

        void setPoint(std::string coordinats) override
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
            if (C.size() == 3)
                cout << "> Координаты: \t OK!" << endl;
            else {
                cout << "> Координаты: \t ERROR!" << endl;
                exit(505);
            }
        }
    };
	
    vector<unique_ptr<Figure>> figurki;

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

    while (sStart != "0") {
        //  if (!file)
        getline(cin, sStart);
        //else
        //  getline(myFile, sStart);

        unsigned int i = 0,
                     j = 0;
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

            cout << "> Скобочки: \t ОК!" << endl; //TODO
        }
        if (sName == "trinagle") {
            figurki.push_back(make_unique<Trinagle>(sCoordinate, sStart));
            figurki[figurki.size() - 1]->setPoint(sCoordinate);
            cout << "> Фигура:\t OK!" << endl;
        }

        else if (sName == "circle") {
            figurki.push_back(make_unique<Circle>(sCoordinate, sStart));
            figurki[figurki.size() - 1]->setPoint(sCoordinate);
            cout << "> Фигура:\t OK!" << endl;
        }

        else if (sName == "poligone") {
            figurki.push_back(make_unique<Poligone>(sCoordinate, sStart));
            figurki[figurki.size() - 1]->setPoint(sCoordinate);
            cout << "> Фигура:\t OK!" << endl;
        }
        sName = "";
    }
    system("cls");

    unsigned int function,
        func;
    string sFunction, sFunc;

    for (function = 0; function < figurki.size(); function++) {
        cout << function + 1 << ". " << figurki[function]->getFullName() << endl;
    }
    cout << endl;

    for (function = 0; function < figurki.size(); function++) {

        vector<pair<int, int>> temp1;
        vector<pair<int, int>> temp2;
        pair<double, pair<int, int>> temp3;
        pair<double, pair<int, int>> temp4;
        pair<pair<int, int>, pair<int, int>> vector1;
        pair<pair<int, int>, pair<int, int>> vector2;
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
            for (func = 0; func < figurki.size(); func++)
                if (func != function) {

                    if (figurki[func]->getName() != "Circle.")
                        temp2 = figurki[func]->getVec();
                    else {
                        temp4 = figurki[func]->getVec1();
                        fl = true;
                    }

                    sFunc = figurki[func]->getName();

                    if ((sFunction == "Trinagle." && sFunc == "Poligone.")
                        || (sFunction == "Trinagle." && sFunc == "Trinagle.")
                        || (sFunction == "Poligone." && sFunc == "Trinagle.")
                        || (sFunction == "Poligone." && sFunc == "Poligone.")) {
                        //Peresech 2x pryam po koord
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
                                //проверка на параллельность http://www.cyberforum.ru/cpp-beginners/thread2015192.html
                                int x1 = vector1.first.first;
                                int y1 = vector1.first.second;
                                int x2 = vector1.second.first;
                                int y2 = vector1.second.second;
                                int x3 = vector2.first.first;
                                int y3 = vector2.first.second;
                                int x4 = vector2.second.first;
                                int y4 = vector2.second.second;
                                int denominator = (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);
                                if (denominator == 0) { // 1 1, 2 2; 3 3, 4 4;
                                    //(1*2 - 2*1) * (4 - 3) - (3*4 - 4 *3) *(1)
                                    if (((x1 >= x3 && x1 <= x4 || x1 <= x3 && x1 >= x4)
                                            && (y1 >= y3 && y1 <= y4 || y1 <= y3 && y1 >= y4))
                                        || ((x2 >= x3 && x2 <= x4 || x2 <= x3 && x2 >= x4)
                                               && (y2 >= y3 && y2 <= y4 || y2 <= y3 && y2 >= y4))) {

                                        if ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1) == 0
                                            && (x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1) == 0) {
                                            cout << "      " << func + 1 << ". " << figurki[func]->getName() << endl;
                                            break;
                                        }
                                    }

                                } else {
                                    int numerator_a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
                                    int numerator_b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
                                    double Ua = 1.0 * numerator_a / denominator;
                                    double Ub = 1.0 * numerator_b / denominator;
                                    if (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1) {

                                        cout << "      " << func + 1 << ". " << figurki[func]->getName() << endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    else if ((sFunction == "Circle." && sFunc == "Poligone.")
                        || (sFunction == "Circle." && sFunc == "Trinagle.")
                        || (sFunction == "Poligone." && sFunc == "Circle.")
                        || (sFunction == "Trinagle." && sFunc == "Circle.")) {
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
                                    cout << "      " << func + 1 << ". " << figurki[func]->getName() << endl;
                                    break;
                                }
                            }
                        }

                    }

                    else if ((sFunction == "Circle." && sFunc == "Circle.")) {
                        double H = sqrt((temp3.second.first - temp4.second.first) * (temp3.second.first - temp4.second.first)
                            + (temp3.second.second - temp4.second.second) * (temp3.second.second - temp4.second.second));
                        if (H <= temp3.first + temp4.first) {
                            cout << "      " << func + 1 << ". " << figurki[func]->getName() << endl;
                            break;
                        }
                    }
                }
        }
    }
}