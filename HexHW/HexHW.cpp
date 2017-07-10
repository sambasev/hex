// HexHW.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <queue>
#include <tuple>
#include <sstream>

using namespace std;
// HEX Board game size (7x7)
const unsigned int hex_size = 7;

class Hex {
public:
	Hex(unsigned int size) {

	}
	~Hex() {

	}
};
int main()
{
	cout << "Hex board is " << hex_size << " x " << hex_size << endl;
	bool edge = false;
	string tmp;
	char c;
	int x_pos = 0, y_pos = 0;
	string dots(".");
	string dashes(" - ");
	string edges("\\ / ");
	string spaces(" ");
	vector <string> board(hex_size * hex_size);
	for (int n = 0; n < board.size(); n++) {
		board[n] = ".";
	}
	int row = 0, col = 0;
label:
	for (int i = 0; i < hex_size*2-1; i++) {
		col = i / 2;
		for (int j = 0; j < hex_size; j++) {
			row = j;
			if (i % 2) {
				if (j < hex_size - 1)
					cout << edges;
				else
					cout << "\\";
			} 
			else {
				if (j < hex_size - 1)
					cout<< board[j + (hex_size * (i/2))] << dashes;
					//cout << dots << dashes;
				else
					//cout << dots;
					cout << board[j + (hex_size * (i/2))];
			}		
		}
		cout << endl;
		for (int k = 0; k <= i; k++)
			cout << spaces;
	}
	cout << " \nEnter co-ordinate X,Y. For example you can enter \"5,2\" without the quotes: " << endl;
	cin >> tmp;
	stringstream pos(tmp);
	pos >> x_pos >> c >> y_pos;
	cout << "You entered (" << x_pos << ", " << y_pos << ")" << endl;
	// Array offset -1
	x_pos--; y_pos--; 
	board[y_pos + (hex_size * (x_pos))] = "X";
	goto label;

	cin.get();
	cin.get();
    return 0;
}

