#include <iostream>
#include <map>
#include <string>

int main() {
    // Creating objects of Roman class
    Roman roman1("XII");
    Roman roman2(1987);

    // Printing values
    roman1.printRoman();   // Output: Roman Numeral: XII
    roman1.printInteger(); // Output: Integer Value: 12

    roman2.printRoman();   // Output: Roman Numeral: MCMLXXXVII
    roman2.printInteger(); // Output: Integer Value: 1987

    return 0;
}
