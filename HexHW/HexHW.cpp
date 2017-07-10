/* HexHW.cpp : This is a simulation of the game Hex. The program will create a 7x7 hex board (size set by hex_size) and players (R and B) can 
   place their coin by entering the move (i,j). The logic to find winner hasn't been implemented yet (will be done in the future). The nodes are
   currently represented by a vector of strings. The logic to update the display with the move, and reject invalid moves has been implemented.
*/


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
		hex_size = size;
		x_pos = 0; y_pos = 0;
		my_turn = false;	//R plays first
		board.resize(hex_size * hex_size);
		for (int n = 0; n < board.size(); n++) {
			board[n] = ".";
		}
	}

	// updatePos(input)
	// Return 0 if success, -1 if failure
	int updatePos(string pos_input) {
		if (pos_input.length() > 3) {
			return -1;
		}
		stringstream pos(pos_input);
		pos >> x_pos >> c >> y_pos;
		cout << "You entered (" << x_pos << "," << y_pos << ")" << endl;
		// Array offset -1
		x_pos--; y_pos--;
		if (!validMove(x_pos, y_pos)) return -1;
		board[y_pos + (hex_size * (x_pos))] = (my_turn ? "B":"R");
		my_turn = !my_turn;
		return 0;
	}

	// validMove(x, y)
	// If (x,y) represent valid co-ordinates, return true
	// else return false
	bool validMove(int x, int y) {
		if ((x >= hex_size) || (y >= hex_size)) return false;
		if ((x < 0) || (y < 0)) return false;
		if (board[y_pos + (hex_size * (x_pos))] != ".") return false;

		return true;
	}

	// drawBoard(void)
	// Draws the hex board on screen. Call after updating the move.
	void drawBoard() {
		string dashes(" - ");
		string edges("\\ / ");
		string spaces(" ");

		for (int i = 0; i < hex_size * 2 - 1; i++) {
			for (int j = 0; j < hex_size; j++) {
				if (i % 2) {
					if (j < hex_size - 1)
						cout << edges;
					else
						cout << "\\";
				}
				else {
					if (j < hex_size - 1)
						cout << board[j + (hex_size * (i / 2))] << dashes;
					//cout << dots << dashes;
					else
						//cout << dots;
						cout << board[j + (hex_size * (i / 2))];
				}
			}
			cout << endl;
			for (int k = 0; k <= i; k++)
				cout << spaces;
		}
	}

	int get_size() {
		return hex_size;
	}

	~Hex() {

	}
private:
	int hex_size;
	vector<string> board;
	bool my_turn;
	unsigned int x_pos, y_pos;
	char c;
};
int main()
{
	//Create a 7x7 board to play Hex
	Hex board(hex_size);
	bool done = false;
	bool my_turn = false;
	cout << "Hex board is " << board.get_size() << " x " << board.get_size() << endl;
	board.drawBoard();
	string tmp = "";
	while (!done) {
		cout << " \nEnter co-ordinate X,Y. For example you can enter \"5,2\" without the quotes: (" << (my_turn ? "B":"R" ) << ")" << endl;
		getline(cin, tmp);
		if (board.updatePos(tmp) == 0) {
			cin.clear();
			fflush(stdin);
			board.drawBoard();
			my_turn = !my_turn; //R goes first (my_turn false)
		}
		else {
			cout << "Not a valid move!";
		}
	}
	
	cin.get();
	cin.get();
    return 0;
}

