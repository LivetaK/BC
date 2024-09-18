#include "Header.hpp"
#include "abc.hpp"
//0123456789abcdef
using namespace std;

int main() {
	string input;
	cin >> input;
	vector<char> inputVector(input.begin(), input.end());
	for (char c : inputVector) {
		int a = convert(c);
	    cout << a << endl;
	}

	//int length = input.length();
	//code(input, length);
	//int a = convert(input);
	//cout << input << endl;
	//cout << a << endl;
}