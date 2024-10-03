#include "Header.hpp"
#include "abc.hpp"
#include <fstream>

using namespace std;
using namespace std::chrono;

int main() {
	int choice;
	string input;
	int lines;
	do {
		menu(choice);
		switch (choice) {
		case 1: { // ranka
			cout << "enter input: " << endl;
			cin >> input;
			hashfun(input);
			break;
		}
		case 2: { // failas su vienu simboliu; OneSym.txt'
			input = read("OneSym.txt");
			hashfun(input);
			break;

		}
		case 3: { // failas su vienu, bet kitokiu simboliu;	OneSymDIFF.txt
			input = read("OneSymDIFF.txt");
			hashfun(input);
			break;
		}
		case 4: { // PAGRINDINIS failas su >1000 atsitiktinai sugeneruotu simboliu;	pagrindinis.txt
			input = read("pagrindinis.txt");
			hashfun(input);
			break;
		}
		case 5: { // failas su >1000 kitokiu atsitiktinai sugenruotu simboliu;	pagrindinisDIFF.txt
			
			input = read("pagrindinisDIFF.txt");
			hashfun(input);
			break;
		}
		case 6: { // PAGRINDINIS failas kuriame pakeistas vienas simbolis;	pagrindinisOneSymbol.txt
			
			input = read("pagrindinisOneSymbol.txt");
			hashfun(input);
			break;
		}
		case 7: { // tuscias failas;	empty.txt
			input = read("empty.txt");
			hashfun(input);
			break;
		}
		case 8: { // konstitucija.txt
			cout << "kiek eiluciu norite nuskaityti? ";
			while (!(cin >> lines) || lines > 789 || lines < 1) {
				cout << "Netinkama ivestis. Bandykite dar karta." << endl;
			}

			ifstream file("konstitucija.txt");
			if (!file) {
				cerr << "Nepavyko atidaryti failo" << endl;
			}

			stringstream Input;
			string input;
			for (int i = 0; i < lines; i++) {
				if (getline(file, input)) {
					Input << input << '\n';
				}
			}

			file.close();
			cout << "Failas nuskaitytas" << endl;

			string inputString = Input.str();

			auto Begin = high_resolution_clock::now();
			hashfun(inputString);
			auto End= high_resolution_clock::now();

			cout << "Kodavimas truko: " << trukmesSkaiciavimas(Begin, End).count() << " ns" << endl;
			break;
		}
		case 9: { // baigti darba
			cout << "Programa baigta." << endl;
			break;
		}
		}
	} while (choice != 9);
	return 0;
}