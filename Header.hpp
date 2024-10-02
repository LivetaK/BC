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
        return '0' + value;
    }
    else if (value >= 10 && value <= 15) {
        return 'a' + (value - 10);
    }
}

void menu(int& choice) {
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

	while (!(cin >> choice) || choice < 1 || choice > 9) {
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
string tikrinimas(string code) {
	if (code.length() > 256) {
		string result = code.substr(0, 256);
		string remaining = code.substr(256);
		int j = 0;
		while (j < remaining.length()) {
			for (int i = 0; i < 256; i++) {
				if (j >= remaining.length()) {
					break;
				}
				result[i] = (result[i] == remaining[j]) ? '0' : '1';
				j++;
			}
		}
		return result;


	}
	else if (code.length() == 0) {
		code.resize(256, '0');
		return code;

	}
	else { // (code.length() < 256)
		char bi = code[0];
		code.resize(50, bi);
		bi = code[7];
		code.resize(100, bi);
		bi = code[4];
		code.resize(150, bi);
		bi = code[2];
		code.resize(200, bi);
		bi = code[3];
		code.resize(256, bi);
		return code;
	}
}
char convertHex(const string& fourBits) {
	int decimalValue =stoi(fourBits, nullptr, 2);
	switch (decimalValue) {
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'a';
	case 11: return 'b';
	case 12: return 'c';
	case 13: return 'd';
	case 14: return 'e';
	case 15: return 'f';
	}
}

string binaryTohex(string kodas) {
	string hex;
	for (int i = 0; i < 256; i += 4){
		string fourBits = kodas.substr(i, 4);
		hex += convertHex(fourBits);
	}
	cout << "Hash: " << hex << endl;
	return hex;
}

string manipulation(string code) {
	reverse(code.begin(), code.end());
	string kodas = tikrinimas(code);
	cout << endl;
	for (int i = 0; i < 25; i++) {
		kodas[i] = (kodas[i] == '1') ? '0' : '1';
	}
	for (int i = 50; i < 70; i++) {
		kodas[i] = (kodas[i] == '1') ? '0' : '1';
	}
	for (int i = 122; i < 175; i++) {
		kodas[i] = (kodas[i] == '0') ? '0' : '1';
	}
	for (int i = 200; i < 256; i++) {
		kodas[i] = (kodas[i] == '0') ? '0' : '1';
	}

	string firstCode = kodas.substr(0, 128);
	string secondCode = kodas.substr(128);



	// paskutinis vertimas
	string hex = binaryTohex(kodas);



	return hex;
}

void hashfun(string input) {
	vector<char> inputVector(input.begin(), input.end());
	string code;
	for (char c : inputVector) {
		int a = convert(c);
		bitset<8> binary(a);
		code += binary.to_string();
	}
	manipulation(code);
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
