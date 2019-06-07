#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <iostream>
#include <list>
#include "piece.h"

enum Style{EMPTY,CLASSIC,HORDE_WHITE,HORDE_BLACK};

class Chess_Board{
	private:
	int status;
	int8_t data[8][8];
	std::list<Piece*>white_pieces;
	std::list<Piece*>black_pieces;
	public:
	const static int width = 8;
	const static int height = 8;
	Chess_Board(Style=EMPTY);
	~Chess_Board();
	Chess_Board operator=(Chess_Board&);
	int getStatus(Color);
	int getCount(Color);
	int getData(unsigned int,unsigned int);
	void addPiece(Piece*);
	void removePiece(unsigned int,unsigned int);
	Piece* getPiece(unsigned int,unsigned int);

	bool play(unsigned int,unsigned int,short);
	bool play(unsigned int,unsigned int,unsigned int,unsigned int);
	bool play(Color,unsigned int,short);
	bool playAI(Color,int);
	static Chess_Board getMinMax(Chess_Board,Color,int);
	void teleport(unsigned int,unsigned int,unsigned int,unsigned int);

	bool isLegal(unsigned int,unsigned int,short);
	bool isEmpty(unsigned int,unsigned int);
	bool isInBound(unsigned int,unsigned int);
	void print();
};

#endif
