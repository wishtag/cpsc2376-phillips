#include <iostream>
#include <vector>

std::vector<std::vector<char>> makeBoard() {
	//Im aware i could just give it a preset size and tell it to
	// set every value to a space but i wanted to do it this way so
	std::vector<std::vector<char>> board = {
		{' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' '}
	};
	return board;
}

void printBoard(const std::vector<std::vector<char>>& board) {
	for (size_t i = 0; i < board.size(); ++i) {
		for (size_t j = 0; j < board.at(i).size(); ++j) {
			std::cout << " | " << board.at(i).at(j);
		}
		std::cout << " |\n";
	}
}

int main() {
	std::cout << "\nInstructions:\n";
	std::cout << "This is connect four, the goal of the game is to get 4 of your pieces in a row,\n";
	std::cout << "whether that be vertically, horizontally, or diagonally\n\nPress enter to start a game\n";

	auto board = makeBoard();
	std::cout << "\nHello, World!" << std::endl;
	printBoard(board);
	return 0;
}
