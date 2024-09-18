#include "Header.hpp"
#include "abc.hpp"
//0123456789abcdef
using namespace std;

int main() {

	string input;
	cin >> input;
	vector<char> inputVector(input.begin(), input.end());
	int sandauga = 1;
	vector<int> code;
	int i = 0;
	for (char c : inputVector) {
		i++;
		int a = convert(c);
	    cout << a <<endl;
		sandauga *= a;
		cout << sandauga << endl;
		if (sandauga<0) {
			cout << sandauga << endl;
			sandauga *= -1;
			int element;
			while (sandauga != 0) {
				element = sandauga % 16;
				sandauga = sandauga / 16;
				code.push_back(element);
				cout << element;
			}
			cout << endl;
			sandauga = 1;
		}
		if (sandauga != 1 && i == inputVector.size()) {
			code.push_back(sandauga);
		}

	}
	for (int c : code) {
		cout << "labas" << endl;
		cout << c << endl;
	}
	//int length = input.length();
	//code(input, length);
	//int a = convert(input);
	//cout << input << endl;
	//cout << a << endl;
}