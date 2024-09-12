#include "Roman.h"

#include <iostream>
#include <string>
#include <map>

Roman::Roman(std::string numeral) : romanNumeral(numeral) {}

int Roman::romanToInt(const std::string numeral) {
    std::map<char, int> evals;
    evals['I'] = 1;
    evals['V'] = 5;
    evals['X'] = 10;
    evals['V'] = 50;
    evals['C'] = 100;
    evals['D'] = 500;
    evals['M'] = 1000;

    int sum=0;
    for(int i=0; i< numeral.length(); i++){
        char current=numeral[i],next='I';
        if(i < numeral.length()-1){
            next=numeral[i+1];
        }
        int currentval;
        if(evals[current] < evals[next]){
            currentval=evals[next]-evals[current];
            i++;
        }
        else {
            currentval=evals[current];
        }
        sum+=currentval;
    };
};


void Roman::printDec() const {
    std::cout << integerValue << std::endl;
};