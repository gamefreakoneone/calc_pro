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
    delete storedExpressions;
    storedExpressions=nullptr;
    stored=0;
}

const Calc &Calc::operator=(const Calc &rhs){
    if(this != &rhs){
        
    }
}

double Calc &Calc::operator=(std::string userInput,double prevValue){
    //First Cleanse
    std::string cleansedString="";
    for(size_t i=0;i<userInput.size();i++){
        if(userInput[i]='=' || userInput[i]=="(" || userInput[i]==" " ||userInput[i]==")"){

        }
        else{
            cleansedString+=userInput[i];
        }
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
