#include <iostream>

class Table {
public:
    int table[3][3];

    void initialize() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                table[i][j] = 0;
            }
        }
    }

    int newMove(int i, int j, int player) {
        if (table[i][j] == 0) {
            table[i][j] = player;
            return 1;
        } else {
            std::cout << "Wrong. Try again...\n";
            return 0;
        }
    }

    int verifyState() {

        for (int i = 0; i < 3; i++) {
            if (table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
                if (table[i][0] == 1 || table[i][0] == 2) {
                    return table[i][0];
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            if (table[0][i] == table[1][i] && table[1][i] == table[2][i]) {
                if (table[0][i] == 1 || table[0][i] == 2) {
                    return table[0][i];
                }
            }
        }

        if (table[0][0] == table[1][1] && table [2][2] == table[1][1]) {
            if (table[0][0] == 1 || table[0][0] == 2) {
                return table[0][0];
            }
        } else if (table[0][2] == table[1][1] && table [2][0] == table[1][1]) {
            if (table[1][1] == 1 || table[1][1] == 2) {
                return table[1][1];
            }
        }
        return 0;
    }
    int isFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (table[i][j] == 0) {
                    return 0;
                }
            }
        }
        return 1;
    }

    void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (table[i][j] == 1) {
                    std::cout << "X" << " ";
                } else if (table[i][j] == 2) {
                    std::cout << "0" << " ";
                } else {
                    std::cout << "-" << " ";
                }
            }
            std::cout << "\n";
        }
    }
};

class Game {
public:
    int turn = 1;
    char name1[1000];
    char name2[1000];
    void startGame() {
        Table game;
        int state = 0;
        game.initialize();
        std::cout << "Name of the first player:\n";
        std::cin >> name1;
        std::cout << "Name of the second player:\n";
        std::cin >> name2;
        while(true) {
            game.printBoard();
            if (game.isFull()) {
                std::cout << "It's a draw. Game over";
                break;
            } else {
                int row;
                int column;
                if (turn == 1) {
                    std::cout << name1 << ", your move, enter row" << "\n";
                    std::cin >> row;
                    std::cout << name1 << ", enter column" << "\n";
                    std::cin >> column;
                    game.newMove(row-1, column-1, turn);
                    turn = 2;
                } else {
                    std::cout << name2 << ", your move, enter row" << "\n";
                    std::cin >> row;
                    std::cout << name2 << ", enter column" << "\n";
                    std::cin >> column;
                    game.newMove(row-1, column-1, turn);
                    turn = 1;
                }
            }
            state = game.verifyState();
            if (state == 1) {
                std::cout << name1 << ",you won" << "\n";
                break;
            } else if (state == 2) {
                std::cout << name2 << ",you won" << "\n";
                break;
            }
        }
    }
};
int main() {
    Game tictactoe;
    tictactoe.startGame();
    return 0;
}
