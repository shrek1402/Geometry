#pragma once
#include "pch.h"

class Figure {
public:
    Figure();

	virtual std::string getFullName() = 0;
    virtual std::string getName() = 0;
    virtual double      getSquare() = 0;
    virtual double      getPerimetr() = 0;
    virtual void        setPoint(std::string) = 0;
    virtual bool        getError() = 0;

    virtual std::vector<std::pair<int, int> > getVec() = 0;
    virtual std::pair<double, std::pair<int, int> > getVec1() = 0;
    ~Figure();
};
