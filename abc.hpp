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

extern char symbol;

int convert(char symbol) {
    switch (symbol) 
    {
    case '!': return 123;
    case '@': return 89;
    case '#': return 67;
    case '$': return 45;
    case '%': return 93;
    case '^': return 68;
    case '&': return 57;
    case '*': return 81;
    case '(': return 26;
    case ')': return 76;
    case '-': return 39;
    case '_': return 65;
    case '=': return 19;
    case '+': return 62;
    case '{': return 93;
    case '}': return 48;
    case '[': return 74;
    case ']': return 28;
    case ':': return 10;
    case ';': return 38;
    case '"': return 49;
    case '\'': return 51;
    case '<': return 73;
    case '>': return 19;
    case ',': return 62;
    case '.': return 82;
    case '?': return 37;
    case '/': return 45;
    case '\\': return 57;
    case '|': return 13;
    case '~': return 68;
    case '`': return 31;
    case ' ': return 61;
    case '0': return 64;
    case '1': return 15;
    case '2': return 73;
    case '3': return 26;
    case '4': return 59;
    case '5': return 83;
    case '6': return 41;
    case '7': return 82;
    case '8': return 74;
    case '9': return 52;
    case 'A': return 16;
    case 'B': return 91;
    case 'C': return 35;
    case 'D': return 79;
    case 'E': return 25;
    case 'F': return 64;
    case 'G': return 13;
    case 'H': return 82;
    case 'I': return 45;
    case 'J': return 79;
    case 'K': return 92;
    case 'L': return 51;
    case 'M': return 17;
    case 'N': return 63;
    case 'O': return 15;
    case 'P': return 83;
    case 'Q': return 27;
    case 'R': return 73;
    case 'S': return 56;
    case 'T': return 83;
    case 'U': return 61;
    case 'V': return 24;
    case 'W': return 91;
    case 'X': return 13;
    case 'Y': return 73;
    case 'Z': return 28;
    case 'a': return 63;
    case 'b': return 78;
    case 'c': return 25;
    case 'd': return 89;
    case 'e': return 43;
    case 'f': return 92;
    case 'g': return 12;
    case 'h': return 57;
    case 'i': return 21;
    case 'j': return 76;
    case 'k': return 92;
    case 'l': return 47;
    case 'm': return 28;
    case 'n': return 65;
    case 'o': return 37;
    case 'p': return 75;
    case 'q': return 86;
    case 'r': return 24;
    case 's': return 83;
    case 't': return 53;
    case 'u': return 19;
    case 'v': return 48;
    case 'w': return 47;
    case 'x': return 84;
    case 'y': return 63;
    case 'z': return 92;
    case 'à': return 68;
    case 'è': return 15;
    case 'æ': return 63;
    case 'ë': return 14;
    case 'á': return 23;
    case 'ğ': return 46;
    case 'û': return 33;
    case 'ø': return 61;
    case 'ş': return 12;
    default: return -1;
    }
}

