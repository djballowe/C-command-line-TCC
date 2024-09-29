#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void board();
int player_choice();
void start_game(int player);
bool check_winner(int *moves);
bool check_move(int move);

// test

int boardArr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {

    // get player choice

    int playerChoice = player_choice();

    // init board
    board();

    // game logic
    start_game(playerChoice);

    for (int i = 0; i < 9; i++) {
        printf("%d, ", boardArr[i]);
    }

    return 0;
}

void board() {
    printf("   |   |   ");
    printf("\n");
    printf("   |   |   ");
    printf("\n");
    printf("---|---|---");
    printf("\n");
    printf("   |   |   ");
    printf("\n");
    printf("---|---|---");
    printf("\n");
    printf("   |   |   ");
    printf("\n");
    printf("   |   |   ");
    printf("\n");
}

int player_choice() {
    char choice;

    while (choice != 'x' && choice != 'o' && choice != 'X' && choice != 'O') {
        printf("Please choose X's or O's: ");
        scanf("%c", &choice);
        printf("\n");
    }

    return choice == 'x' ? 1 : 2;
}

void start_game(int player) {
    bool gameOver = check_winner(boardArr);

    while (!gameOver) {
        int move;
        printf("please select a move: ");
        scanf("%d", &move);
        printf("\n");
        bool isValidMove = check_move(move);
        while (!isValidMove) {
            printf("Invalid move please select an open space from 1-9: ");
            scanf("%d", &move);
            isValidMove = check_move(move);
            printf("\n");
        }
        boardArr[move - 1] = player;
    }
}

bool check_move(int move) {
    if (move > 9 || move < 1) {
        return false;
    }

    return boardArr[move] == 0;
}

bool check_winner(int *moves) {}
