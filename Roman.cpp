#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Roman.h"

using namespace std;

Roman::Roman(const std::string& numeral) : romanNumeral(numeral),integerValue(romanToInt(numeral)) {}
Roman::Roman(int value) : romanNumeral(intToRoman(value)),integerValue(value) {}
Roman::Roman() : romanNumeral("I"),integerValue(1) {}
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
const vector<char> Roman::RnKeys = {'M','D','C','L','X','V','I'};

int Roman::romanToInt(const std::string& numeral) {
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
        for(int i=0;i<int(RnKeys.size());i++){
            char numChar=RnKeys[i];
            int value=RnMap.find(numChar)->second;
            // cout << "Currently adding " << numChar << " character w/ value: " << value << endl;
            while(remainder >= value){
                numeral.push_back(numChar);
                remainder=remainder-value;
                // cout << "value: " << remainder << ". Numeral: "<< numeral << endl;
            }
            int gap=value-remainder;
            char nextChar=RnKeys[i+1];
            int nextvalue=RnMap.find(nextChar)->second;
            // cout << "Next Value: " << nextvalue << endl;
            if(value/nextvalue==2){
                nextChar=RnKeys[i+2];
                nextvalue=RnMap.find(nextChar)->second;
            }
            if(gap < (nextvalue) && (nextvalue/value) <= 0.2){
                numeral=numeral.substr(0,numeral.length());
                numeral.push_back(nextChar);
                numeral.push_back(numChar);
                remainder=remainder-(value-nextvalue);
            } 
        }
    }
    std::cout << numeral << std::endl;
    return numeral;
}

//Public Methods

void Roman::printDec() const {
    cout << integerValue << endl;
};

void Roman::printRoman() const {
    cout << romanNumeral << endl;
}

int Roman::getInt() const {
    return integerValue;
}

std::string Roman::getRoman() const {
    return romanNumeral;
}