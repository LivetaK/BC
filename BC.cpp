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
		case 8: { // konstitucija.txt
			cout << "kiek eiluciu norite nuskaityti? ";
			while (!(cin >> lines) || lines > 789 || lines < 1) {
				cout << "Netinkama ivestis. Bandykite dar karta." << endl;
			}
			string Input;
			ifstream file("konstitucija.txt");
			if (!file) {
				cerr << "Nepavyko atidaryti failo" << endl;
			}
			for (int i = 0; i < lines; i++) {
				getline(file, input);
				Input += input;
			}
			file.close();
			cout << "Failas nuskaitytas" << endl;

			auto Begin = high_resolution_clock::now();
			hashFun(Input);
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