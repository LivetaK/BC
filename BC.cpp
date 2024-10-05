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
			string hash = hashfun(input);
			cout << "Hash: " << hash << endl;
			break;
		}
		case 2: { // failas su vienu simboliu; OneSym.txt'
			input = read("OneSym.txt");
			string hash = hashfun(input);
			cout << "Hash: " << hash << endl;
			break;

		}
		case 3: { // failas su vienu, bet kitokiu simboliu;	OneSymDIFF.txt
			input = read("OneSymDIFF.txt");
			string hash = hashfun(input);
			cout << "Hash: " << hash << endl;
			break;
		}
		case 4: { // PAGRINDINIS failas su >1000 atsitiktinai sugeneruotu simboliu;	pagrindinis.txt
			input = read("pagrindinis.txt");
			string hash = hashfun(input);
			cout << "Hash: " << hash << endl;
			break;
		}
		case 5: { // failas su >1000 kitokiu atsitiktinai sugenruotu simboliu;	pagrindinisDIFF.txt
			
			input = read("pagrindinisDIFF.txt");
			string hash = hashfun(input);
			cout << "Hash: " << hash << endl;
			break;
		}
		case 6: { // PAGRINDINIS failas kuriame pakeistas vienas simbolis;	pagrindinisOneSymbol.txt
			
			input = read("pagrindinisOneSymbol.txt");
			string hash = hashfun(input);
			cout << "Hash: " << hash << endl;
			break;
		}
		case 7: { // tuscias failas;	empty.txt
			input = read("empty.txt");
			string hash = hashfun(input);
			cout << "Hash: " << hash << endl;
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
			string hash = hashfun(input);
			auto End= high_resolution_clock::now();
			cout << "Hash: " << hash << endl;
			cout << "Kodavimas truko: " << trukmesSkaiciavimas(Begin, End).count() << " ns" << endl;
			break;
		}
		case 9: { // atsitiktines poros; stringPoros.txt
			ifstream file("stringPoros.txt");
			if (!file) {
				cerr << "Nepavyko atidaryti failo" << endl;
			}
			string input1, input2;
			string hash1, hash2;
			int sutampa = 0;
			int nesutampa = 0;
			for (int i = 0; i < 100000; i++) {
				file >> input1;
				hash1 = hashfun(input1);
				file >> input2;
				hash2 = hashfun(input2);
				if (hash1 == hash2) {
					sutampa++;
				}
				else {
					nesutampa++;
				}
				/*cout << "Hash1: " << hash1 << endl;
				cout << "Hash2: " << hash2 << endl;*/
				//cout << endl;
				hash1.clear();
				hash2.clear();
			}
			cout << "sutampa: " << sutampa << endl;
			cout << "nesutampa: " << nesutampa << endl;
			file.close();
			break;

		}
		case 10: { // atsitiktines poros su vienu nesutampanciu simboliu; stringPorosDIFF.txt
			ifstream file("stringPorosDIFF.txt");
			if (!file) {
				cerr << "Nepavyko atidaryti failo" << endl;
			}
			double proc = 0.0;
			double procB = 0.0;
			double bendras =0;
			double bendrasB = 0;
			double minProc = 100.0;
			double maxProc = 0.0;
			double minProcB = 100.0;
			double maxProcB = 0.0;

			for (int i = 0; i < 100000; i++) {
				string input1, input2;
				file >> input1 >> input2;
				string hash1 = hashfun(input1);
				string hash2 = hashfun(input2);
				int skirtumasH = skirtumas(hash1, hash2);
				proc = skirtumasH / 64.0 * 100;
				bendras += proc;
				if (proc < minProc) minProc = proc;
				if (proc > maxProc) maxProc = proc;

				string binHash1 = hexToBin(hash1);
				string binHash2 = hexToBin(hash2);
				int skirtumasB = skirtumas(binHash1, binHash2);
				procB = skirtumasB / 256.0 * 100;
				bendrasB += procB;
				if (procB < minProcB) minProcB = procB;
				if (procB > maxProcB) maxProcB = procB;

				proc = 0;
				

			}
			double hexSkirtingumas = bendras / 100000;
			double biSkirtingumas = bendrasB / 100000;

			cout << "Skirtumai hex lygmenyje: " << endl;
			cout << "Vidutinis procentas: " << hexSkirtingumas << endl;
			cout << "Minimalus procentas: " << minProc << endl;
			cout << "Maksimalus procentas: " << maxProc << endl;
			cout << endl;
			cout << "Skirtumai bi lygmenyje: " << endl;
			cout << "Vidutinis procentas: " << biSkirtingumas << endl;
			cout << "Minimalus procentas: " << minProcB << endl;
			cout << "Maksimalus procentas: " << maxProcB << endl;

			file.close();
			break;

		}
		case 11: { // baigti darba
			cout << "Programa baigta." << endl;
			break;
		}
		}
	} while (choice != 11);
	return 0;
}