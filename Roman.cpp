#include <iostream>
#include <string>
#include <map>

#include "Roman.h"

using namespace std;

Roman::Roman(const std::string& numeral) : romanNumeral(numeral),integerValue(romanToInt(romanNumeral)) {}
Roman::Roman(int value) : romanNumeral(intToRoman(value)),integerValue(value) {}
Roman::Roman() : romanNumeral(0),integerValue(0) {}
//Private Methods

const map<char,int> Roman::RnMap= {
    {'M',1000},
    {'D',500},
    {'C',100},
    {'L',50},
    {'X',10},
    {'V',5},
    {'I',1},
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
        // cout << "First value is: " << firstValue << endl;
        const int nextValue = RnMap.find(next)->second;
        // cout << "Second value is: " << nextValue << endl;
        // Check relative size of the next value
        if(firstValue < nextValue){
            // If the next value is larger, we need to consider it 
            currentval=nextValue-firstValue;
            i++;
        }
        else {
            //if not, we use the first value normally
            currentval=firstValue;
        }
        sum+=currentval;
    };
    return sum;
};

string Roman::intToRoman(int value){
    int remainder=value;
    string numeral;

    while(remainder > 0){
        map<char, int>::const_iterator it = Roman::RnMap.begin();
        while(it != RnMap.end()){
            int numChar=it->first;
            int value=it->second;
            while(remainder >= value){
                numeral+=numChar;
                remainder=remainder-value;
                cout << "value: " << remainder << "Numeral: "<< numeral << endl;
            }
            int gap=value-remainder;
            map<char, int>::const_iterator next=std::next(it,2);
            if(gap < (next->second)){
                numeral=numeral.substr(0,numeral.length()-1);
                numeral+= next->first + numChar;

            }
            ++it; 
        }
    }

    return numeral;
}

//Public Methods

void Roman::printDec() const {
    std::cout << integerValue << std::endl;
};

void Roman::printRoman() const {
    std::cout << romanNumeral << std::endl;
}

int Roman::getInt() const {
    return integerValue;
}

string Roman::getRoman() const {
    return romanNumeral;
}