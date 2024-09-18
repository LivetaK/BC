#pragma once
#include "abc.hpp"
#include <fstream>
#include <sstream>
#include <string>


char intToHexChar(int value) {
    if (value >= 0 && value <= 9) {
        return '0' + value; // Convert 0-9 to '0'-'9'
    }
    else if (value >= 10 && value <= 15) {
        return 'a' + (value - 10); // Convert 10-15 to 'A'-'F'
    }
}