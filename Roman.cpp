#include <iostream>
#include <string>
#include <map>

#include "Roman.h"

using namespace std;

Roman::Roman(const std::string& numeral) : romanNumeral(numeral),integerValue(romanToInt(romanNumeral)) {}

const map<char,int> Roman::RnMap= {
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
};
int Roman::romanToInt(const std::string& numeral) {
    // std::map<char, int> evals;
    // evals['I'] = 1;
    // evals['V'] = 5;
    // evals['X'] = 10;
    // evals['V'] = 50;
    // evals['C'] = 100;
    // evals['D'] = 500;
    // evals['M'] = 1000;

    int sum=0;
    for(int i=0; i< int(numeral.length()); i++){
        char current=numeral[i],next='I';
        if(i < int(numeral.length())-1){
            next=numeral[i+1];
        }
        int currentval;
        const int firstValue = RnMap.find(current)->second;
        cout << "First value is: " << firstValue << endl;
        const int nextValue = RnMap.find(next)->second;
        cout << "Second value is: " << nextValue << endl;
        // Check relative size of the next value
        if(firstValue < nextValue){
            // If the next value is larger, we need to consider it 
            currentval=nextValue-firstValue;
            i++;
        }
        else {
            currentval=firstValue;
        }
        sum+=currentval;
    };
    return sum;
};


void Roman::printDec() const {
    std::cout << integerValue << std::endl;
};