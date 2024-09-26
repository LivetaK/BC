#include "Header.hpp"
#include "abc.hpp"
#include <fstream>
using namespace std;



int main() {


	int choice;
	string input;
	do {
		menu(choice);
		switch (choice) {
		case 1: { // ranka
			cout << "enter input: " << endl;
			cin >> input;
			hashFun(input);
			break;
		}
		case 2: { // failas su vienu simboliu; OneSym.txt'
			input = read("OneSym.txt");
			hashFun(input);
			break;

		}
		case 3: { // failas su vienu, bet kitokiu simboliu;	OneSymDIFF.txt
			input = read("OneSymDIFF.txt");
			hashFun(input);
			break;
		}
		case 4: { // PAGRINDINIS failas su >1000 atsitiktinai sugeneruotu simboliu;	pagrindinis.txt
			input = read("pagrindinis.txt");
			hashFun(input);
			break;
		}
		case 5: { // failas su >1000 kitokiu atsitiktinai sugenruotu simboliu;	pagrindinisDIFF.txt
			
			input = read("pagrindinisDIFF.txt");
			hashFun(input); 
			break;
		}
		case 6: { // PAGRINDINIS failas kuriame pakeistas vienas simbolis;	pagrindinisOneSymbol.txt
			
			input = read("pagrindinisOneSymbol.txt");
			hashFun(input); 
			break;
		}
		case 7: { // tuscias failas;	empty.txt
			input = read("empty.txt");
			hashFun(input);
			break;
		}
		case 8: { // baigti darba
			cout << "Programa baigta." << endl;
			break;
		}
		}
	} while (choice != 8);
	return 0;
}