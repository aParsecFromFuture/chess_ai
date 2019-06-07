#include "piece.h"

Piece::Piece(unsigned int x = 0,unsigned int y = 0,Color c,bool m){
	position_x = x;
	position_y = y;
	color = c;
	is_moved = m;
}

void Piece::setColor(Color c){
	color = c;
}

Color Piece::getColor(){
	return color;
}

void Piece::setPosition(unsigned int x,unsigned int y){
	position_x = x;
	position_y = y;
}

void Piece::setX(unsigned int x){
	position_x = x;
}

unsigned int Piece::getX(){
	return position_x;
}

void Piece::setY(unsigned int y){
	position_y = y;
}

unsigned int Piece::getY(){
	return position_y;
}

Point Piece::getMovement(Type t,Color c,short m){
	switch(t){
		case PAWN :
			switch(c){
				case WHITE : 
					switch(m % 4){
						case 0 : return Point(0,-1);
						case 1 : return Point(0,-2);
						case 2 : return Point(-1,-1);
						case 3 : return Point(1,-1);	 
					}
				case BLACK : 
					switch(m % 4){
						case 0 : return Point(0,1);
						case 1 : return Point(0,2);
						case 2 : return Point(-1,1);
						case 3 : return Point(1,1);	 
					}
			}
		case KNIGHT :
			switch(m % 8){
				case 0 : return Point(-2,-1);
				case 1 : return Point(-1,-2);
				case 2 : return Point(1,-2);
				case 3 : return Point(2,-1);
				case 4 : return Point(2,1);
				case 5 : return Point(1,2);
				case 6 : return Point(-1,2);
				case 7 : return Point(-2,1);
			}
		case BISHOP :
			switch(m % 28){
				case 0 : return Point(-1,-1);
				case 1 : return Point(-2,-2);
				case 2 : return Point(-3,-3);
				case 3 : return Point(-4,-4);
				case 4 : return Point(-5,-5);
				case 5 : return Point(-6,-6);
				case 6 : return Point(-7,-7);
				case 7 : return Point(1,-1);
				case 8 : return Point(2,-2);
				case 9 : return Point(3,-3);
				case 10 : return Point(4,-4);
				case 11 : return Point(5,-5);
				case 12 : return Point(6,-6);
				case 13 : return Point(7,-7);
				case 14 : return Point(1,1);
				case 15 : return Point(2,2);
				case 16 : return Point(3,3);
				case 17 : return Point(4,4);
				case 18 : return Point(5,5);
				case 19 : return Point(6,6);
				case 20 : return Point(7,7);
				case 21 : return Point(-1,1);
				case 22 : return Point(-2,2);
				case 23 : return Point(-3,3);
				case 24 : return Point(-4,4);
				case 25 : return Point(-5,5);
				case 26 : return Point(-6,6);
				case 27 : return Point(-7,7);
			}
		case ROOK :
			switch(m % 28){
				case 0 : return Point(-1,0);
				case 1 : return Point(-2,0);
				case 2 : return Point(-3,0);
				case 3 : return Point(-4,0);
				case 4 : return Point(-5,0);
				case 5 : return Point(-6,0);
				case 6 : return Point(-7,0);
				case 7 : return Point(0,-1);
				case 8 : return Point(0,-2);
				case 9 : return Point(0,-3);
				case 10 : return Point(0,-4);
				case 11 : return Point(0,-5);
				case 12 : return Point(0,-6);
				case 13 : return Point(0,-7);
				case 14 : return Point(1,0);
				case 15 : return Point(2,0);
				case 16 : return Point(3,0);
				case 17 : return Point(4,0);
				case 18 : return Point(5,0);
				case 19 : return Point(6,0);
				case 20 : return Point(7,0);
				case 21 : return Point(0,1);
				case 22 : return Point(0,2);
				case 23 : return Point(0,3);
				case 24 : return Point(0,4);
				case 25 : return Point(0,5);
				case 26 : return Point(0,6);
				case 27 : return Point(0,7);
			}
		case QUEEN : 
			switch(m % 56){
				case 0 : return Point(-1,-1);
				case 1 : return Point(-2,-2);
				case 2 : return Point(-3,-3);
				case 3 : return Point(-4,-4);
				case 4 : return Point(-5,-5);
				case 5 : return Point(-6,-6);
				case 6 : return Point(-7,-7);
				case 7 : return Point(1,-1);
				case 8 : return Point(2,-2);
				case 9 : return Point(3,-3);
				case 10 : return Point(4,-4);
				case 11 : return Point(5,-5);
				case 12 : return Point(6,-6);
				case 13 : return Point(7,-7);
				case 14 : return Point(1,1);
				case 15 : return Point(2,2);
				case 16 : return Point(3,3);
				case 17 : return Point(4,4);
				case 18 : return Point(5,5);
				case 19 : return Point(6,6);
				case 20 : return Point(7,7);
				case 21 : return Point(-1,1);
				case 22 : return Point(-2,2);
				case 23 : return Point(-3,3);
				case 24 : return Point(-4,4);
				case 25 : return Point(-5,5);
				case 26 : return Point(-6,6);
				case 27 : return Point(-7,7);
				case 28 : return Point(-1,0);
				case 29 : return Point(-2,0);
				case 30 : return Point(-3,0);
				case 31 : return Point(-4,0);
				case 32 : return Point(-5,0);
				case 33 : return Point(-6,0);
				case 34 : return Point(-7,0);
				case 35 : return Point(0,-1);
				case 36 : return Point(0,-2);
				case 37 : return Point(0,-3);
				case 38 : return Point(0,-4);
				case 39 : return Point(0,-5);
				case 40 : return Point(0,-6);
				case 41 : return Point(0,-7);
				case 42 : return Point(1,0);
				case 43 : return Point(2,0);
				case 44 : return Point(3,0);
				case 45 : return Point(4,0);
				case 46 : return Point(5,0);
				case 47 : return Point(6,0);
				case 48 : return Point(7,0);
				case 49 : return Point(0,1);
				case 50 : return Point(0,2);
				case 51 : return Point(0,3);
				case 52 : return Point(0,4);
				case 53 : return Point(0,5);
				case 54 : return Point(0,6);
				case 55 : return Point(0,7);


			}
		case KING :
			switch(m % 8){
				case 0 : return Point(-1,0);
				case 1 : return Point(-1,-1);
				case 2 : return Point(0,-1);
				case 3 : return Point(1,-1);
				case 4 : return Point(1,0);
				case 5 : return Point(1,1);
				case 6 : return Point(0,1);
				case 7 : return Point(-1,1);
			}
	}
}

bool Piece::isMoved(){
	return is_moved;
}

Pawn::Pawn(unsigned int x = 0,unsigned int y = 0,Color c,bool m):Piece(x,y,c,m){
	
}

void Pawn::move(short m){
	Point p = Piece::getMovement(type,color,m);
	position_x += p.x;
	position_y += p.y;	
	is_moved = true;
}

int Pawn::getValue(){
	return Pawn::value;
}

int Pawn::getMobility(){
	return Pawn::mobility;
}

int Pawn::pass(int n){
	return n + 1;
}

Type Pawn::getType(){
	return Pawn::type;
}

Knight::Knight(unsigned int x = 0,unsigned int y = 0,Color c,bool m):Piece(x,y,c,m){

}

void Knight::move(short m){
	Point p = Piece::getMovement(type,color,m);
	position_x += p.x;
	position_y += p.y;
	is_moved = true;	
}

int Knight::getValue(){
	return Knight::value;
}

int Knight::getMobility(){
	return Knight::mobility;
}

int Knight::pass(int n){
	return n + 1;
}

Type Knight::getType(){
	return Knight::type;
}

Bishop::Bishop(unsigned int x = 0,unsigned int y = 0,Color c,bool m):Piece(x,y,c,m){

}

void Bishop::move(short m){
	Point p = Piece::getMovement(type,color,m);
	position_x += p.x;
	position_y += p.y;
	is_moved = true;
}

int Bishop::getValue(){
	return Bishop::value;
}

int Bishop::getMobility(){
	return Bishop::mobility;
}

int Bishop::pass(int n){
	return n + 7 - n % 7;
}

Type Bishop::getType(){
	return Bishop::type;
}

Rook::Rook(unsigned int x = 0,unsigned int y = 0,Color c,bool m):Piece(x,y,c,m){

}

void Rook::move(short m){
	Point p = Piece::getMovement(type,color,m);
	position_x += p.x;
	position_y += p.y;
	is_moved = true;
}

int Rook::getValue(){
	return Rook::value;
}

int Rook::pass(int n){
	return n + 7 - n % 7;
}

int Rook::getMobility(){
	return Rook::mobility;
}

Type Rook::getType(){
	return Rook::type;
}

Queen::Queen(unsigned int x = 0,unsigned int y = 0,Color c,bool m):Piece(x,y,c,m){

}

void Queen::move(short m){
	Point p = Piece::getMovement(type,color,m);
	position_x += p.x;
	position_y += p.y;
	is_moved = true;
}

int Queen::getValue(){
	return Queen::value;
}

int Queen::getMobility(){
	return Queen::mobility;
}

int Queen::pass(int n){
	return  n + 7 - n % 7;
}

Type Queen::getType(){
	return Queen::type;
}

King::King(unsigned int x = 0,unsigned int y = 0,Color c,bool m):Piece(x,y,c,m){
	is_moved = false;
}

void King::move(short m){
	Point p = Piece::getMovement(type,color,m);
	position_x += p.x;
	position_y += p.y;
	is_moved = true;
}

int King::getValue(){
	return King::value;
}

int King::getMobility(){
	return King::mobility;
}

int King::pass(int n){
	return n + 1;
}

Type King::getType(){
	return King::type;
}

