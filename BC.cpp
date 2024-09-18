#include "Header.hpp"
#include "abc.hpp"
//0123456789abcdef
using namespace std;

int main() {

	string input;
	cin >> input;
	vector<char> inputVector(input.begin(), input.end());
	int sandauga = 1;
	vector<char> code;
	for (char c : inputVector) {
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
	}

	//int length = input.length();
	//code(input, length);
	//int a = convert(input);
	//cout << input << endl;
	//cout << a << endl;
}