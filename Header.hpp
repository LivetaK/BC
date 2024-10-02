#pragma once
#include "abc.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <bitset>


using namespace std;
using namespace std::chrono;


char intToHexChar(int value) {
    if (value >= 0 && value <= 9) {
        return '0' + value; // Convert 0-9 to '0'-'9'
    }
    else if (value >= 10 && value <= 15) {
        return 'a' + (value - 10); // Convert 10-15 to 'A'-'F'
    }
}

void menu(int &choice) {
	cout << "-----------------------------------------------------------------" << endl;
    cout << "1 - duomenis ivesti ranka" << endl;
    cout << "2 - failas su vienu simboliu" << endl;
    cout << "3 - failas su vienu, bet kitokiu simboliu" << endl;
    cout << "4 - PAGRINDINIS failas su >1000 atsitiktinai sugeneruotu simboliu" << endl;
    cout << "5 - failas su >1000 kitokiu atsitiktinai sugenruotu simboliu" << endl;
    cout << "6 - PAGRINDINIS failas kuriame pakeistas vienas simbolis" << endl;
    cout << "7 - tuscias failas" << endl;
	cout << "8 - skaityti eilutes is failo konstitucija.txt" << endl;
    cout << "9 - baigti darba" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Jusu pasirinkimas: ";

	while (!(cin >> choice)|| choice < 1 ||choice > 9) {
		cout << "Neteisingas pasirinkimas. Bandykite dar karta" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menu(choice);
	}
}

string hashFun(string input) {
	//cout << "input: " << input << endl;
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
	cout << "output: " << hexCode << endl;
	cout << endl;
	return hexCode;
}
void hashfun(string input) {
	vector<char> inputVector(input.begin(), input.end());
	vector<bitset<8>> code;
	for (char c : inputVector) {
		int a = convert(c);
		bitset<8> binary(a);
		cout << binary;
		code.push_back(binary);
	}
}


string read(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cerr << "Nepavyko atidaryti failo" << endl;
		return "";
	}
	string input;
	getline(file, input);
	file.close();
	cout << "Failas nuskaitytas" << endl;
	return input;
}

nanoseconds trukmesSkaiciavimas(high_resolution_clock::time_point pradzia, high_resolution_clock::time_point pabaiga) {
	auto trukme = duration_cast<nanoseconds>(pabaiga - pradzia);
	return trukme;
}
