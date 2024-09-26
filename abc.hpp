#pragma once

#include <iostream>
#include "string.h"
#include <vector>
using namespace std;

// siame faile yra aprasoma visa simboliu abecele, kuri yra isversta i random skaicius 16 sistemoje
/*
| Row\Col| 0 | 1 | 2 | 3 | 4 |
|-----------------------------|
| ** 0 **| ! | @ | # | $ | % |
| ** 1 **| ^ | & | * | ( | ) |
| ** 2 **| - | _ | = | + | { |
| ** 3 **| } | [ | ] | : | ; |
| ** 4 **| " | ' | < | > | , |
| ** 5 **| . | ? | / | \ | | |
| ** 6 **| ~ | ` |   | 0 | 1 |
| ** 7 **| 2 | 3 | 4 | 5 | 6 |
| ** 8 **| 7 | 8 | 9 | A | B |
| ** 9 **| C | D | E | F | G |
| **10 **| H | I | J | K | L |
| **11 **| M | N | O | P | Q |
| **12 **| R | S | T | U | V |
| **13 **| W | X | Y | Z | a |
| **14 **| b | c | d | e | f |
| **15 **| g | h | i | j | k |
| **16 **| l | m | n | o | p |
| **17 **| q | r | s | t | u |
| **18 **| v | w | x | y | z |
*/

extern char symbol; //or some shit

int convert(char symbol) {
    switch (symbol) 
    {
        case '!': return 1;
        case '@': return 2;
        case '#': return 3;
        case '$': return 4;
        case '%': return 5;
        case '^': return 6;
        case '&': return 7;
        case '*': return 8;
        case '(': return 9;
        case ')': return 10;
        case '-': return 11;
        case '_': return 12;
        case '=': return 13;
        case '+': return 14;
        case '{': return 15;
        case '}': return 16;
        case '[': return 17;
        case ']': return 18;
        case ':': return 19;
        case ';': return 20;
        case '"': return 21;
        case '\'': return 22;
        case '<': return 23;
        case '>': return 24;
        case ',': return 25;
        case '.': return 26;
        case '?': return 27;
        case '/': return 28;
        case '\\': return 29;
        case '|': return 30;
        case '~': return 31;
        case '`': return 32;
        case ' ': return 33;
        case '0': return 34;
        case '1': return 35;
        case '2': return 36;
        case '3': return 37;
        case '4': return 38;
        case '5': return 39;
        case '6': return 40;
        case '7': return 41;
        case '8': return 42;
        case '9': return 43;
        case 'A': return 44;
        case 'B': return 45;
        case 'C': return 46;
        case 'D': return 47;
        case 'E': return 48;
        case 'F': return 49;
        case 'G': return 50;
        case 'H': return 51;
        case 'I': return 52;
        case 'J': return 53;
        case 'K': return 54;
        case 'L': return 55;
        case 'M': return 56;
        case 'N': return 57;
        case 'O': return 58;
        case 'P': return 59;
        case 'Q': return 60;
        case 'R': return 61;
        case 'S': return 62;
        case 'T': return 63;
        case 'U': return 64;
        case 'V': return 65;
        case 'W': return 66;
        case 'X': return 67;
        case 'Y': return 68;
        case 'Z': return 69;
        case 'a': return 70;
        case 'b': return 71;
        case 'c': return 72;
        case 'd': return 73;
        case 'e': return 74;
        case 'f': return 75;
        case 'g': return 76;
        case 'h': return 77;
        case 'i': return 78;
        case 'j': return 79;
        case 'k': return 80;
        case 'l': return 81;
        case 'm': return 82;
        case 'n': return 83;
        case 'o': return 84;
        case 'p': return 85;
        case 'q': return 86;
        case 'r': return 87;
        case 's': return 88;
        case 't': return 89;
        case 'u': return 90;
        case 'v': return 91;
        case 'w': return 92;
        case 'x': return 93;
        case 'y': return 94;
        case 'z': return 95;
        default: return -1; // Return -1 for unrecognized symbols
    }
}


