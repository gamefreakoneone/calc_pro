#include<iostream>
#include "Calc.h"
#include<cmath>
#include "stddef.h"

Calc::Calc(int values): storedExpressions(new std::string[values]),stored(0){} // We are basically storing some default values into the storedExpressions pointer and giveing the variable stored the default value 0

Calc::Calc(const Calc &rhs){
    if(storedExpressions!=nullptr){
        storedExpressions=new std::string[rhs.stored]; //string array of size rhs.stored
    }
}

Calc::~Calc(){
    delete[] storedExpressions;
    storedExpressions=nullptr;
    stored=0;
}

const Calc &Calc::operator=(const Calc &rhs){
    if(this != &rhs){
        Calc temp(rhs);
        std::swap(storedExpressions,temp.storedExpressions);
        std::swap(stored,temp.stored);
    }

    return *this;
}

double Calc &Calc::operator=(std::string userInput,double prevValue){
    //First Cleanse
    std::string cleansedString="";
    for(size_t i=0;i<userInput.size();i++){ //size_t tells its first going to have an positive whole number
        if(userInput[i]='=' || userInput[i]=="(" || userInput[i]==" " ||userInput[i]==")"){

        }
        else{
            cleansedString+=userInput[i];
        }
    }
    double value=std::stod(cleansedString.substr(1, cleansedString.length()-1));
    if(cleansedString[0]=='^'){
        return pow(prevValue,value);
    }
    else if(cleansedString[0]=='*' || cleansedString[0]=='/'){
        if(cleansedString[0]=='*'){
            return prevValue*value;
        }else{
            if(value==0){
                std::exit(0);
            }
            else{
                return prevValue/value;
            }
        }
    }else if(cleansedString[0]=='+' || cleansedString[0]=='-'){
        if(cleansedString[0]=='+'){
            return prevValue+value;
        }else if(cleansedString[0]=='-'){
            return prevValue-value;
        }
    }
    else{
        std::cout<<"Error: must start with operator"<<std::endl;
    }
}


void Calc::print(){
    std::cout<<"You have "<<stored<<"expresions stored: ";
    for(size_t i=0;i<stored;++i){
        std::cout<<"Expression"<<i +1<<":\n";
        std::cout<<storedExpressions[i]<<std::endl;
    }
}

void Calc::setStored(size_t newStored){
    stored=newStored;
}

size_t Calc::getStored(){
    return stored;
}
