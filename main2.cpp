#include <iostream>
#include "chess_board.h"

int main(){
	Chess_Board chess(CLASSIC);

	int level_white = 2;
	int level_black = 2;

	for(int i = 0;i < 1000;i++){
		chess.playAI(WHITE,level_white);
		std::cout << "\033[H\033[J";   //ekrani temizlemek icin
		chess.print();
		chess.playAI(BLACK,level_black);
		std::cout << "\033[H\033[J"; 
		chess.print();
	}
}
