#pragma once
#include "abc.hpp"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


char intToHexChar(int value) {
    if (value >= 0 && value <= 9) {
        return '0' + value; // Convert 0-9 to '0'-'9'
    }
    else if (value >= 10 && value <= 15) {
        return 'a' + (value - 10); // Convert 10-15 to 'A'-'F'
    }
}

void menu(int &choice) {
    cout << "duomenis ivesti ranka - 1" << endl;
    cout << "failas su vienu simboliu - 2" << endl;
    cout << "failas su vienu, bet kitokiu simboliu - 3" << endl;
    cout << "PAGRINDINIS failas su >1000 atsitiktinai sugeneruotu simboliu - 4" << endl;
    cout << "failas su >1000 kitokiu atsitiktinai sugenruotu simboliu - 5" << endl;
    cout << "PAGRINDINIS failas kuriame pakeistas vienas simbolis - 6" << endl;
    cout << "tuscias failas - 7" << endl;
    cout << "baigti darba - 8" << endl;
	while (!(cin >> choice)|| choice < 1 ||choice > 8) {
		cout << "Neteisingas pasirinkimas. Bandykite dar karta" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menu(choice);
	}
}

string hashFun(string input) {
	vector<char> inputVector(input.begin(), input.end());
	int sandauga = 1;
	vector<char> code;
	int i = 0;
	for (char c : inputVector) {
		i++;
		int a = convert(c);
		//cout << a <<endl;
		sandauga *= a;
		//cout << sandauga << endl;
		if (sandauga < 0) {
			//cout << sandauga << endl;
			sandauga *= -1;
			int element;
			while (sandauga != 0) {
				element = sandauga % 16;
				sandauga = sandauga / 16;
				//cout << element;
				char character = intToHexChar(element);
				code.push_back(character);

			}
			cout << endl;
			sandauga = 1;
		}
		if (sandauga != 1 && i == inputVector.size()) {
			code.push_back(sandauga);
		}
	}
	stringstream longCode;
	for (char c : code) {
		//cout << c;
		longCode << c;
	}
	string hexCode = longCode.str();
	//cout << hexCode;
	return hexCode;
}