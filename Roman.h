#ifndef ROMAN_H
#define ROMAN_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class Roman {
private:
    static const map<char,int> RnMap; // Store a conversion between the 
                                      // Roman Numeral characters and values
    static const vector<char> RnKeys; // Store keys for RnMap

    std::string romanNumeral;  // Store Roman numeral as a string
    int integerValue;          // Store the corresponding integer value

    // Utility function to convert Roman numeral to integer
    int romanToInt(const std::string& numeral);

    // Utility function to convert integer to Roman numeral
    std::string intToRoman(int value);

public:
    // Default constructor
    Roman();

    // Constructor to initialize with a Roman numeral string
    Roman(const std::string& numeral);

    // Constructor to initialize with an integer
    Roman(int value);

    // Function to print the integer value
    void printDec() const;

    // Function to print the Roman numeral
    void printRoman() const;

    // Getter for the integer value
    int getInt() const;

    // Getter for the Roman numeral string
    std::string getRoman() const;
};

#endif
