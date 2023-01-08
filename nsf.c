#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define elemental __attribute__((const))

#define NO_PIECE 0b00000000     // 0
#define BLACK_PAWN 0b10000001   // 129
#define BLACK_BISHOP 0b10000010 // 130
#define BLACK_KNIGHT 0b10000100 // 132
#define BLACK_ROOK 0b10001000   // 136
#define BLACK_QUEEN 0b10010000  // 144
#define BLACK_KING 0b10100000   // 160
#define WHITE_PAWN 0b00000001   // 1
#define WHITE_BISHOP 0b00000010 // 2
#define WHITE_KNIGHT 0b00000100 // 4
#define WHITE_ROOK 0b00001000   // 8
#define WHITE_QUEEN 0b00010000  // 16
#define WHITE_KING 0b00100000   // 32

typedef unsigned char byte;

typedef struct {
	byte theBoard[8][8];
	int sideToMove; //1 is white, -1 is black
	bool whiteShort;
	bool whiteLong;
	bool blackShort;
	bool blackLong;
} Board;

elemental inline byte getPiece(Board* board, const int x, const int y) {
	return board->theBoard[y][x];
}
	
elemental inline int getSide(const byte piece) {
	if (piece > 128) return -1;
	else if (piece == 0) return 0;
	else return 1;
}

inline void findPiece(Board* board, const byte piece, int* destination) {
	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++)
		if (getPiece(board, i, j) == piece) { 
			destination[0] = i; destination[1] = j;
		}
}

elemental inline bool inCheck(Board* board) {
	const int turn = board->sideToMove;	

}

inline Board* generateMoves(Board* board) {	
	for (int i = 0; i < 64; i++) {
		const byte piece = getPiece(board, i/8, i%8);
		const int modifer = (board->sideToMove == -1) ? -128 : 0;
		if (getSide(piece) == board->sideToMove) {
			switch (piece - modifer) {
				case 1: /*is pawn */ break;
				case 2: /*is bishop */ break;
				case 4: /*is knight */ break;
				case 8: /*is rook */ break;
				case 16: /*is queen */ break;
				case 32: /*is kign */ break;
			}
		}
	}
}

int main() {
	printf("Hello");
	return 0;
}
