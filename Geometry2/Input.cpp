#include "Input.h"
#include "Circle.h"
#include "Figure.h"
#include "Poligone.h"
#include "Triangle.h"
#include "pch.h"

Input::Input(char** a)
  : argv(a)
{
  Input::getVerifyInput(argv);
}

Input::Input(std::string s)
  : sStart(s)
{
  Input::getVerifyInput(sStart);
}

// std::ifstream myFile(argv);

//  if (!file)
// getline(cin, sStart);
// else

void
Input::getVerifyInput(char**)
{
  std::ifstream myFile(argv[1]);

  getline(myFile, sStart);
  unsigned int i = 0, j = 0;
  if (sStart != "0") {
    while (sStart.at(i) != '(' && i < sStart.size() - 1) {
      i++;
    }

    if (i >= sStart.size()) {
      std::cout << "> Скобочки: \t ERROR!" << std::endl;
      exit(123);
    }

    sName = sStart.substr(0, i);

    j = i - 1;

    while (sStart.at(j) != ')' && j <= sStart.size() - 1) {
      j++;
    }

    if (sStart.at(sStart.size() - 1) != ')') {
      std::cout << "> Скобочки: \t ERROR!" << std::endl;
      exit(123);
    }

    sCoordinate = sStart.substr(i + 1, j - i - 1);

    std::cout << "> Скобочки: \t ОК!" << std::endl; // TODO
  }
  if (sName == "triangle") {
    figurki.push_back(std::make_unique<Triangle>(sCoordinate, sStart));
    std::cout << "> Фигура: \t OK!" << std::endl;
  }

  else if (sName == "circle") {
    figurki.push_back(std::make_unique<Circle>(sCoordinate, sStart));
    std::cout << "> Фигура: \t OK!" << std::endl;
  }

  else if (sName == "poligone") {
    figurki.push_back(std::make_unique<Poligone>(sCoordinate, sStart));
    std::cout << "> Фигура: \t OK!" << std::endl;
  }
  sName = "";
}

void
Input::getVerifyInput(std::string)
{
  {
    std::ifstream myFile(argv[1]);

    getline(std::cin, sStart);
    unsigned int i = 0, j = 0;
    if (sStart != "0") {
      while (sStart.at(i) != '(' && i < sStart.size() - 1) {
        i++;
      }

      if (i >= sStart.size()) {
        std::cout << "> Скобочки: \t ERROR!" << std::endl;
        exit(123);
      }

      sName = sStart.substr(0, i);

      j = i - 1;

      while (sStart.at(j) != ')' && j <= sStart.size() - 1) {
        j++;
      }

      if (sStart.at(sStart.size() - 1) != ')') {
        std::cout << "> Скобочки: \t ERROR!" << std::endl;
        exit(123);
      }

      sCoordinate = sStart.substr(i + 1, j - i - 1);

      std::cout << "> Скобочки: \t ОК!" << std::endl; // TODO
    }
  }
}
//Input::~Input() {}
