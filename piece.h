#ifndef PIECE_H
#define PIECE_H

#include <cstdint>

enum Color{WHITE,BLACK};
enum Type{PAWN,KNIGHT,BISHOP,ROOK,QUEEN,KING};

struct Point{
	int8_t x;
	int8_t y;
	Point(int x = 0,int y = 0){
		this->x = x;
		this->y = y;
	}
};

class Piece{
	protected:
	uint8_t position_x;
	uint8_t position_y;
	bool is_moved;
	Color color;
	public:
	Piece(unsigned int,unsigned int,Color=WHITE,bool=false);
	void setColor(Color);
	Color getColor();
	void setPosition(unsigned int,unsigned int);
	void setX(unsigned int);
	unsigned int getX();
	void setY(unsigned int);
	unsigned int getY();
	static Point getMovement(Type,Color,short);
	virtual void move(short) = 0;
	bool isMoved();
	virtual int getValue() = 0;
	virtual int getMobility() = 0;
	virtual int pass(int) = 0; 
	virtual Type getType() = 0;
};

class Pawn : public Piece{
	public:
	const static Type type = PAWN;
	const static int mobility = 4;
	const static int value = 1;
	Pawn(unsigned int,unsigned int,Color=WHITE,bool=false);
	void move(short);
	int getValue();
	int getMobility();
	int pass(int); 
	Type getType();
};

class Knight : public Piece{
	public:
	const static Type type = KNIGHT;;
	const static int mobility = 8;
	const static int value = 2;
	Knight(unsigned int,unsigned int,Color=WHITE,bool=false);
	void move(short);
	int getValue();
	int getMobility();
	int pass(int);
	Type getType();
};

class Bishop : public Piece{
	public:
	const static Type type = BISHOP;
	const static int mobility = 28;
	const static int value = 3;
	Bishop(unsigned int,unsigned int,Color=WHITE,bool=false);
	void move(short);
	int getValue();
	int getMobility();
	int pass(int);
	Type getType();
};

class Rook : public Piece{
	public:
	const static Type type = ROOK;
	const static int mobility = 28;
	const static int value = 5;
	Rook(unsigned int,unsigned int,Color=WHITE,bool=false);
	void move(short);
	int getValue();
	int getMobility();
	int pass(int);
	Type getType();
};

class Queen : public Piece{
	public:
	const static Type type = QUEEN;
	const static int mobility = 56;
	const static int value = 9;
	Queen(unsigned int,unsigned int,Color=WHITE,bool=false);
	void move(short);
	int getValue();
	int getMobility();
	int pass(int);
	Type getType();
};

class King : public Piece{
	public:
	const static Type type = KING;
	const static int mobility = 8;
	const static int value = 64;
	King(unsigned int,unsigned int,Color=WHITE,bool=false);
	void move(short);
	int getValue();
	int getMobility();
	int pass(int);
	Type getType();
};
#endif
