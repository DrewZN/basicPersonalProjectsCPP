#include <iostream>
#include <string>
#include <vector>

void updateBoard(std::vector<std::string>&, int, char);
void displayBoard(std::vector<std::string>);
bool checkIfWin(std::vector<std::string>);
bool checkIfAlreadyUsed(std::vector<std::string>, int);

int main() {
	// Variables
	std::cout << "Tic-tac-toe by: Dominic Bernardino\n\n";
	std::vector<std::string> emptyBoard = { "  1 | 2 | 3  ",
										    "-------------",
										    "  4 | 5 | 6  ",
										    "-------------",
										    "  7 | 8 | 9  " };
	while (true) {
		int player1, player2;
		char player1c = 'x', player2c = 'o';
		displayBoard(emptyBoard);
		std::cout << "\nPlayer 1 (x): ";
		std::cin >> player1;
		// Error check if number was not inputted
		while (std::cin.fail()) {
			std::cerr << "\nError: Invalid Input\n\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			displayBoard(emptyBoard);
			std::cout << "\nPlayer 1 (x): ";
			std::cin >> player1;
		}
		// Check if number is [1,9]
		while (!(player1 >= 1 && player1 <= 9)) {
			std::cerr << "\nError: Invalid Option\n\n";
			displayBoard(emptyBoard);
			std::cout << "\nPlayer 1 (x): ";
			std::cin >> player1;
		}
		// Check if Number Already Guessed
		while (checkIfAlreadyUsed(emptyBoard, player1)) {
			std::cerr << "\nError: Invalid Option\n\n";
			displayBoard(emptyBoard);
			std::cout << "\nPlayer 1 (x): ";
			std::cin >> player1;
		}
		updateBoard(emptyBoard, player1, player1c);
		// Check if Win
		if (checkIfWin(emptyBoard)) {
			std::cout << std::endl;
			displayBoard(emptyBoard);
			std::cout << "\nPlayer 1 Wins!\n";
			break;
		}
		std::cout << std::endl;
		displayBoard(emptyBoard);
		std::cout << "\nPlayer 2 (o): ";
		std::cin >> player2;
		// Error check if number was not inputted
		while (std::cin.fail()) {
			std::cerr << "\nError: Invalid Input\n\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			displayBoard(emptyBoard);
			std::cout << "\nPlayer 2 (o): ";
			std::cin >> player1;
		}
		// Check if number is [1,9]
		while (!(player2 >= 1 && player2 <= 9)) {
			std::cerr << "\nError: Invalid Option\n\n";
			displayBoard(emptyBoard);
			std::cout << "\nPlayer 2 (o): ";
			std::cin >> player2;
			continue;
		}
		// Check if Number Already Guessed
		while (checkIfAlreadyUsed(emptyBoard, player2)) {
			std::cerr << "\nError: Invalid Option\n\n";
			displayBoard(emptyBoard);
			std::cout << "\nPlayer 2 (o): ";
			std::cin >> player2;
			continue;
		}
		updateBoard(emptyBoard, player2, player2c);
		// Check if Win
		if (checkIfWin(emptyBoard)) {
			std::cout << std::endl;
			displayBoard(emptyBoard);
			std::cout << "\nPlayer 2 Wins!\n";
			break;
		}
		std::cout << std::endl;
	}


	return 0;
}

void updateBoard(std::vector<std::string>& board, int num, char playerC) {
	if (playerC == 'x') {
		switch (num) {
		case 1: {
			board[0][2] = 'x';
			break;
		}
		case 2: {
			board[0][6] = 'x';
			break;
		}
		case 3: {
			board[0][10] = 'x';
			break;
		}
		case 4: {
			board[2][2] = 'x';
			break;
		}
		case 5: {
			board[2][6] = 'x';
			break;
		}
		case 6: {
			board[2][10] = 'x';
			break;
		}
		case 7: {
			board[4][2] = 'x';
			break;
		}
		case 8: {
			board[4][6] = 'x';
			break;
		}
		case 9: {
			board[4][10] = 'x';
			break;
		}
		}
	}
	else {
		switch (num) {
		case 1: {
			board[0][2] = 'o';
			break;
		}
		case 2: {
			board[0][6] = 'o';
			break;
		}
		case 3: {
			board[0][10] = 'o';
			break;
		}
		case 4: {
			board[2][2] = 'o';
			break;
		}
		case 5: {
			board[2][6] = 'o';
			break;
		}
		case 6: {
			board[2][10] = 'o';
			break;
		}
		case 7: {
			board[4][2] = 'o';
			break;
		}
		case 8: {
			board[4][6] = 'o';
			break;
		}
		case 9: {
			board[4][10] = 'o';
			break;
		}
		}
	}
}

void displayBoard(std::vector<std::string> board) {
	for (int i = 0; i < board.size(); i++) {
		std::cout << board[i] << std::endl;
	}
}

bool checkIfWin(std::vector<std::string> board) {
	bool ret = false;

	// Combinations for 'x'
	// Horizontal Rows
	if (board[0][2] == 'x' && board[0][6] == 'x' && board[0][10] == 'x') {
		ret = true;
	}
	else if (board[2][2] == 'x' && board[2][6] == 'x' && board[2][10] == 'x') {
		ret = true;
	}
	else if (board[4][2] == 'x' && board[4][6] == 'x' && board[4][10] == 'x') {
		ret = true;
	}
	// Vertical Columns
	else if (board[0][2] == 'x' && board[2][2] == 'x' && board[4][2] == 'x') {
		ret = true;
	}
	else if (board[0][6] == 'x' && board[2][6] == 'x' && board[4][6] == 'x') {
		ret = true;
	}
	else if (board[0][10] == 'x' && board[2][10] == 'x' && board[4][10] == 'x') {
		ret = true;
	}
	// Diagonals
	else if (board[0][2] == 'x' && board[2][6] == 'x' && board[4][10] == 'x') {
		ret = true;
	}
	else if (board[0][10] == 'x' && board[2][6] == 'x' && board[4][2] == 'x') {
		ret = true;
	}

	// Combinations for 'o'
	// Horizontal Rows
	else if (board[0][2] == 'o' && board[0][6] == 'o' && board[0][10] == 'o') {
		ret = true;
	}
	else if (board[2][2] == 'o' && board[2][6] == 'o' && board[2][10] == 'o') {
		ret = true;
	}
	else if (board[4][2] == 'o' && board[4][6] == 'o' && board[4][10] == 'o') {
		ret = true;
	}
	// Vertical Rows
	else if (board[0][2] == 'o' && board[2][2] == 'o' && board[4][2] == 'o') {
		ret = true;
	}
	else if (board[0][6] == 'o' && board[2][6] == 'o' && board[4][6] == 'o') {
		ret = true;
	}
	else if (board[0][10] == 'o' && board[2][10] == 'o' && board[4][10] == 'o') {
		ret = true;
	}
	// Diagonals
	else if (board[0][2] == 'o' && board[2][6] == 'o' && board[4][10] == 'o') {
		ret = true;
	}
	else if (board[0][10] == 'o' && board[2][6] == 'o' && board[4][2] == 'o') {
		ret = true;
	}

	else {
		ret = false;
	}
	return ret;
}

bool checkIfAlreadyUsed(std::vector<std::string> board, int playedNum) {
	bool ret = false;

	switch (playedNum) {
	case 1: {
		if (board[0][2] == 'x' || board[0][2] == 'o') {
			ret = true;
		}
		break;
	}
	case 2: {
		if (board[0][6] == 'x' || board[0][6] == 'o') {
			ret = true;
		}
		break;
	}
	case 3: {
		if (board[0][10] == 'x' || board[0][10] == 'o') {
			ret = true;
		}
		break;
	}
	case 4: {
		if (board[2][2] == 'x' || board[2][2] == 'o') {
			ret = true;
		}
		break;
	}
	case 5: {
		if (board[2][6] == 'x' || board[2][6] == 'o') {
			ret = true;
		}
		break;
	}
	case 6: {
		if (board[2][10] == 'x' || board[2][10] == 'o') {
			ret = true;
		}
		break;
	}
	case 7: {
		if (board[4][2] == 'x' || board[4][2] == 'o') {
			ret = true;
		}
		break;
	}
	case 8: {
		if (board[4][6] == 'x' || board[4][6] == 'o') {
			ret = true;
		}
		break;
	}
	case 9: {
		if (board[4][10] == 'x' || board[4][10] == 'o') {
			ret = true;
		}
		break;
	}
	}

	return ret;
}