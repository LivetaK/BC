#include "Header.hpp"
#include "abc.hpp"
#include <fstream>

//0123456789abcdef
using namespace std;



int main() {


	int choice;
	string input;
	do {
		menu(choice);
		switch (choice) {
		case 1: { // ranka
			cin >> input;
			hashFun(input);
			break;
		}
		case 2: { // failas su vienu simboliu; OneSym.txt
			break;

		}
		case 3: { // failas su vienu, bet kitokiu simboliu;	OneSymDIFF.txt
			break;

		}
		case 4: { // PAGRINDINIS failas su >1000 atsitiktinai sugeneruotu simboliu;	pagrindinis.txt
			break;

		}
		case 5: { // failas su >1000 kitokiu atsitiktinai sugenruotu simboliu;	pagrindinisDIFF.txt
			break;

		}
		case 6: { // PAGRINDINIS failas kuriame pakeistas vienas simbolis;	pagrindinisOneSymbol.txt
			break;

		}
		case 7: { // tuscias failas;	empty.txt
			break;

		}
		case 8: { // baigti darba
			cout << "Programa baigta." << endl;
			break;
		}
		}
	} while (choice != 8);
	return 0;
	//int length = input.length();
	//code(input, length);
	//int a = convert(input);
	//cout << input << endl;
	//cout << a << endl;
}