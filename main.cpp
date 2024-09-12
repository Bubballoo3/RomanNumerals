#include <iostream>
#include <map>
#include <string>

#include "Roman.h"

using namespace std;

int main() {
    std::cout << "This functions totally working" << std::endl;
    Roman roman1("XII");
    Roman roman2(2000);
     
    roman1.printDec();
    roman1.printRoman();

    roman2.printDec();
    roman2.printRoman();
    std::cout << "Did it work?" << std::endl;
    
    // Creating objects of Roman class
    // Roman roman1("XII");
    // Roman roman2(1987);

    // std::cout << "Still working?" << std::endl;
    // // Printing values
    // roman1.printRoman();   // Output: Roman Numeral: XII
    // roman1.printDec(); // Output: Integer Value: 12

    // roman2.printRoman();   // Output: Roman Numeral: MCMLXXXVII
    // roman2.printDec(); // Output: Integer Value: 1987
    
    // Roman roman3(10094);
    // std::cout << "Final Value: 10094. Numeral: ";
    // roman3.printRoman();
    // cout << std::endl;
    return 0;
}
