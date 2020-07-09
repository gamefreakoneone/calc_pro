#ifndef RHYMECALC_CALC_H
#define RHYMECALC_CALC_H

#include<string>

class Calc{
    public:
        Calc(int val);
        Calc(const Calc &rhs); //copy constructor
        ~Calc();//delete constructor
        const Calc &operator=(const Calc &rhs); //copy assignment constructor
        double process(std::string userInput,double prevValue);
        void print();
        std::string* storedExpressions;
        void setStored(size_t newStored);
        size_t getStored();
    private:
        size_t stored;
}

#endif RHYMECALC_CALC_H
