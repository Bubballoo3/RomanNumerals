#include <iostream>
#include <map>
#include <string>

#include "Roman.h"

using namespace std;

int main() {
    // Creating objects of Roman class
    Roman roman1("XII");
    Roman roman2(1984);
    Roman roman3("MCCCXLIV");
    Roman roman4(14253);

    // Printing values
    roman1.printRoman();   // Output: Roman Numeral: XII
    roman1.printDec(); // Output: Integer Value: 12

    roman2.printRoman();   // Output: Roman Numeral: MCMLXXXVII
    roman2.printDec(); // Output: Integer Value: 1987
    
    roman3.printRoman();   // Output: Roman Numeral: MCCCXLIV
    roman3.printDec(); // Output: Integer Value: 1344

    roman4.printRoman();   // Output: Roman Numeral: MMMMMMMMMMMMMMCCLIII
    roman4.printDec(); // Output: Integer Value: 14253
    
    return 0;
}
