#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkForWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkForDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // There is an empty cell, the game is not a draw
            }
        }
    }
    return true; // All cells are filled, the game is a draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    do {
        // Display the current state of the board
        std::cout << "Tic-Tac-Toe Board:\n";
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the chosen cell is valid and update the board
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check for a win
            if (checkForWin(board, currentPlayer)) {
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check for a draw
            if (checkForDraw(board)) {
                std::cout << "The game is a draw!\n";
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Please try again.\n";
        }

    } while (true);

    return 0;
}
