#include <iostream>
#include <vector>
#include <string>

enum gameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum players { PLAYER_1 = 'X', PLAYER_2 = 'O', EMPTY = ' ' };

std::vector<std::vector<char>> makeBoard()
{
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

void printBoard(const std::vector<std::vector<char>>& board)
{
	std::cout << "\n";

	for (size_t i = 0; i < board.at(0).size(); ++i)
	{
		std::cout << "   " << i + 1;
	}

	std::cout << "\n";

	for (size_t i = 0; i < board.size(); ++i)
	{
		for (size_t j = 0; j < board.at(i).size(); ++j)
		{
			std::cout << " | " << board.at(i).at(j);
		}
		std::cout << " |\n";
	}
	std::cout << "\n";
}

enum gameState gameStatus(const std::vector<std::vector<char>>& board)
{
	for (size_t i = 0; i < board.size(); ++i)
	{
		for (size_t j = 0; j < board.at(i).size(); ++j)
		{
			if (board.at(i).at(j) != EMPTY)
			{
				//this is where it checks to see if anyone won
				enum players playersPiece = static_cast<enum players>(board.at(i).at(j));
				
				// Up & Down
				for (size_t k = 1; k < 4; ++k)
				{
					// Checking to see if the piece its about to try and check is even in range
					if (static_cast<int>(i-k) >= 0)
					{
						// the first half of the if statement checks to see if the piece is the same as the starting piece
						// the second half checks to see if this is the 4th piece
						if (playersPiece == static_cast<enum players>(board.at(i-k).at(j)) && k == 3)
						{
							//determines who won
							if (playersPiece == PLAYER_1)
							{
								return PLAYER_1_WINS;
							}
							else
							{
								return PLAYER_2_WINS;
							}
						}
						// if the piece isnt the same as the starting piece it just breaks the for loop
						else if (playersPiece != static_cast<enum players>(board.at(i - k).at(j)))
						{
							break;
						}
					}
					else
					{
						break;
					}
				}

				// Left & Right
				for (size_t k = 1; k < 4; ++k)
				{
					// Checking to see if the piece its about to try and check is even in range
					if (static_cast<int>(j - k) >= 0)
					{
						// the first half of the if statement checks to see if the piece is the same as the starting piece
						// the second half checks to see if this is the 4th piece
						if (playersPiece == static_cast<enum players>(board.at(i).at(j - k)) && k == 3)
						{
							//determines who won
							if (playersPiece == PLAYER_1)
							{
								return PLAYER_1_WINS;
							}
							else
							{
								return PLAYER_2_WINS;
							}
						}
						// if the piece isnt the same as the starting piece it just breaks the for loop
						else if (playersPiece != static_cast<enum players>(board.at(i).at(j - k)))
						{
							break;
						}
					}
					else
					{
						break;
					}
				}

				// Top Left & Bottom Right
				for (size_t k = 1; k < 4; ++k)
				{
					// Checking to see if the piece its about to try and check is even in range
					if (static_cast<int>(j - k) >= 0 && static_cast<int>(i - k) >= 0)
					{
						// the first half of the if statement checks to see if the piece is the same as the starting piece
						// the second half checks to see if this is the 4th piece
						if (playersPiece == static_cast<enum players>(board.at(i - k).at(j - k)) && k == 3)
						{
							//determines who won
							if (playersPiece == PLAYER_1)
							{
								return PLAYER_1_WINS;
							}
							else
							{
								return PLAYER_2_WINS;
							}
						}
						// if the piece isnt the same as the starting piece it just breaks the for loop
						else if (playersPiece != static_cast<enum players>(board.at(i - k).at(j - k)))
						{
							break;
						}
					}
					else
					{
						break;
					}
				}

				// Top Right & Bottom Left
				for (size_t k = 1; k < 4; ++k)
				{
					// Checking to see if the piece its about to try and check is even in range
					if (static_cast<int>(j + k) <= board.at(0).size()-1 && static_cast<int>(i - k) >= 0)
					{
						// the first half of the if statement checks to see if the piece is the same as the starting piece
						// the second half checks to see if this is the 4th piece
						if (playersPiece == static_cast<enum players>(board.at(i - k).at(j + k)) && k == 3)
						{
							//determines who won
							if (playersPiece == PLAYER_1)
							{
								return PLAYER_1_WINS;
							}
							else
							{
								return PLAYER_2_WINS;
							}
						}
						// if the piece isnt the same as the starting piece it just breaks the for loop
						else if (playersPiece != static_cast<enum players>(board.at(i - k).at(j + k)))
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	return ONGOING;
}

enum players play(const enum players& player, const int& column, std::vector<std::vector<char>>* board)
{
	if (EMPTY != board->at(0).at(column - 1))
	{
		std::cout << "That column is full, pick a different one.\n";
		return player;
	}

	for (size_t i = board->size()-1; i >= 0; --i)
	{
		if (EMPTY == board->at(i).at(column-1))
		{
			board->at(i).at(column-1) = player;
			if (player == PLAYER_1) 
			{
				return PLAYER_2;
			}
			else
			{
				return PLAYER_1;
			}
		}
	}
}

int main()
{
	std::cout << "\nInstructions:\n";
	std::cout << "This is connect four, the goal of the game is to get 4 of your pieces in a row,\n";
	std::cout << "whether that be vertically, horizontally, or diagonally\n\n";
	
	char exit = 'o';//it really doesnt matter what its set to by default, as long as it isnt 'e'
	while (exit != 'e')
	{
		enum players currentTurn = PLAYER_1;
		auto board = makeBoard();
		while (gameStatus(board) == ONGOING)
		{
			printBoard(board);
			if (currentTurn == PLAYER_1) 
			{
				std::cout << "Player 1, make your move: ";
			}
			else
			{
				std::cout << "Player 2, make your move: ";
			}
			int column;
			std::cin >> column;

			while (std::cin.fail() || column > 7 || column < 1)
			{
				std::cout << "Invalid input. Please try again: ";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> column;
			}

			std::cin.ignore(256, '\n');

			currentTurn = play(currentTurn,column,&board);
			
		}

		switch (gameStatus(board))
		{
		case PLAYER_1_WINS:
			std::cout << "Player 1 Wins!\n";
			break;
		case PLAYER_2_WINS:
			std::cout << "Player 2 Wins!\n";
			break;
		case DRAW:
			std::cout << "The game ended in a draw.\n";
			break;
		default:
			break;
		}
		printBoard(board);
		std::cout << "Would you like to play again? ('e' to exit, anything else to play again): ";
		std::cin >> exit;
	}
	return 0;
}
