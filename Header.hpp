#pragma once
#include "abc.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <bitset>
#include <algorithm>
#include <cstdlib>

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
	return hex;
}


string skaiciavimai(string tempDec) { //128 max
	int n = tempDec.length();
	int y = n / 9; 
	int x = n % 9;
	vector <string> chunk;
	int j = 0;
	for (int i = 0; i < y; i++) {
		chunk.push_back(tempDec.substr(j, 9));;
		j += 9;
	}
	if (x > 0) {
		chunk.push_back(tempDec.substr(j, x));
	}

	vector <int> chunkInt;
	for (string part : chunk) {
		chunkInt.push_back(stoi(part));
	}
	int numChunks = chunkInt.size();
	
	string mainString; 
	int half = numChunks / 2;
	unsigned long long result = 0;
	for (int i = 0; i < half; i++) {
		result = chunkInt[i] * chunkInt[i + half];
		mainString += to_string(result);
		result = 0;
	}
	if (numChunks % 2 == 1) {
		result = chunkInt[0] * chunkInt[numChunks - 1];
		mainString += to_string(result);
		result = 0;
	}

	return mainString;
}

string manipulation(string code) {
	reverse(code.begin(), code.end());
	string kodas = tikrinimas(code);
	string ran1 = "1100110011001100110011110";
	string ran2 = "01010101010101010101010101010101010";
	string ran3 = "100011010111010001010100011010110111100";
	string ran4 = "011010010101101010100110111010101010001011101000111";
	string ran5 = "1110001110001110";
	string ran6 = "01010001110101000101110101011110101010010001011100100";
	string ran7 = "10100110101101010101000010101010111101010111000000101011";



	for (int i = 0; i < 25; i++) {
		kodas[i] = (kodas[i] == ran1[i]) ? '0' : '1';
	}
	for (int i = 25; i < 60; i++) {
		kodas[i] = (kodas[i] == ran2[i-25]) ? '1' : '0';
	}
	for (int i = 60; i < 99; i++) {
		kodas[i] = (kodas[i] == ran3[i-60]) ? '0' : '1';
	}
	for (int i = 99; i < 150; i++) {
		kodas[i] = (kodas[i] == ran4[i-99]) ? '1' : '0';
	}
	for (int i = 150; i < 166; i++) {
		kodas[i] = (kodas[i] == ran5[i-150]) ? '0' : '1';
	}
	for (int i = 166; i < 222; i++) {
		kodas[i] = (kodas[i] == ran6[i-166]) ? '1' : '0';
	}
	for (int i = 222; i < 256; i++) {
		kodas[i] = (kodas[i] == ran7[i-222]) ? '0' : '1';
	}

	string tempHex = binaryTohex(kodas);
	string tempDec;


	//cout << kodas << endl;
	//cout << tempHex << endl;


	for (char number : tempHex) {
		if (number >= '0' && number <= '9') {
			tempDec += number;
		}
		else {
			int decimalValue = number - 'a' + 10;
			tempDec += to_string(decimalValue);
		}
	}
	//cout << tempDec << endl;

	kodas.clear();
	kodas = skaiciavimai(tempDec);

	//cout << "kodas" << kodas << endl;
	//cout << "labas" << endl;
	vector<char> inputVector(kodas.begin(), kodas.end());
	string kodass;
	for (char c : inputVector) {
		bitset<8> binary(c);
		kodass += binary.to_string();
	}
	string Code = tikrinimas(kodass);
	string manCode;

	string codeOne = Code.substr(0, 17);
	string codeTwo = Code.substr(17, 17);
	string codeThree = Code.substr(34, 17);
	string codeFour = Code.substr(51, 17);
	string codeFive = Code.substr(68, 17);
	string codeSix = Code.substr(85, 17);
	string codeSeven = Code.substr(102, 17);
	string codeEight = Code.substr(119, 17);
	string codeNine = Code.substr(136, 17);
	string codeTen = Code.substr(153, 17);
	string codeEleven = Code.substr(170, 17);
	string codeTwelve = Code.substr(187, 17);
	string codeThirteen = Code.substr(204, 17);
	string codeFourteen = Code.substr(221, 17);
	string codeFifteen = Code.substr(238, 17);
	string codeSixteen = Code.substr(255, 1);

	for (int i = 0; i < 17; ++i) {
		swap(codeOne[i], codeEleven[i]);
		swap(codeTwo[i], codeNine[i]);
		swap(codeThree[i], codeTwelve[i]);
		swap(codeFour[i], codeFourteen[i]);
		swap(codeFive[i], codeFifteen[i]);
		swap(codeSix[i], codeThirteen[i]);
		swap(codeSeven[i], codeOne[i]);
		swap(codeEight[i], codeTwo[i]);
		swap(codeNine[i], codeSix[i]);
		swap(codeTen[i], codeThirteen[i]);
	}

	reverse(codeOne.begin(), codeOne.end());
	reverse(codeTwo.begin(), codeTwo.end());
	rotate(codeThree.begin(), codeThree.begin() + 5, codeThree.end());
	rotate(codeFour.begin(), codeFour.begin() + 7, codeFour.end());
	reverse(codeFive.begin(), codeFive.end());
	reverse(codeSix.begin(), codeSix.end());
	rotate(codeSeven.begin(), codeSeven.begin() + 3, codeSeven.end());
	reverse(codeEight.begin(), codeEight.end());
	rotate(codeNine.begin(), codeNine.begin() + 4, codeNine.end());
	reverse(codeTen.begin(), codeTen.end());
	reverse(codeEleven.begin(), codeEleven.end());
	rotate(codeTwelve.begin(), codeTwelve.begin() + 6, codeTwelve.end());
	reverse(codeThirteen.begin(), codeThirteen.end());
	rotate(codeFourteen.begin(), codeFourteen.begin() + 5, codeFourteen.end());
	reverse(codeFifteen.begin(), codeFifteen.end());

	manCode += codeOne;
	manCode += codeTwo;
	manCode += codeThree;
	manCode += codeFour;
	manCode += codeFive;
	manCode += codeSix;
	manCode += codeSixteen;
	manCode += codeSeven;
	manCode += codeEight;
	manCode += codeNine;
	manCode += codeTen;
	manCode += codeEleven;
	manCode += codeTwelve;
	manCode += codeThirteen;
	manCode += codeFourteen;
	manCode += codeFifteen;
	


	// paskutinis vertimas
	string hex = binaryTohex(manCode);
	return hex;
}

void hashfun(string input) {
	vector<char> inputVector(input.begin(), input.end());
	string code;
	for (char c : inputVector) {
		//int a = convert(c);
		bitset<8> binary(c);
		code += binary.to_string();
	}
	string hash = manipulation(code);
	cout << "Hash: " << hash << endl;
	hash.clear();
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
