#include "Header.hpp"
#include "abc.hpp"
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
		}
		case 2: { // failas su vienu simboliu

		}
		case 3: { // failas su vienu, bet kitokiu simboliu

		}
		case 4: { // PAGRINDINIS failas su >1000 atsitiktinai sugeneruotu simboliu

		}
		case 5: { // failas su >1000 kitokiu atsitiktinai sugenruotu simboliu

		}
		case 6: { // PAGRINDINIS failas kuriame pakeistas vienas simbolis

		}
		case 7: { // tuscias failas
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