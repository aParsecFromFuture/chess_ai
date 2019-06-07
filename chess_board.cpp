#include "chess_board.h"

Chess_Board::Chess_Board(Style s){
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			data[i][j] = 0;
		}
	}
	status = 0;
	
	switch(s){
		case EMPTY : break;
		case CLASSIC :
			for(int i = 0;i < 8;i++){
				addPiece(new Pawn(i,6,WHITE));
				addPiece(new Pawn(i,1,BLACK));
			}

			addPiece(new Rook(0,7,WHITE));
			addPiece(new Rook(7,7,WHITE));
			addPiece(new Knight(1,7,WHITE));
			addPiece(new Knight(6,7,WHITE));
			addPiece(new Bishop(2,7,WHITE));
			addPiece(new Bishop(5,7,WHITE));
			addPiece(new King(4,7,WHITE));
			addPiece(new Queen(3,7,WHITE));

			addPiece(new Rook(0,0,BLACK));
			addPiece(new Rook(7,0,BLACK));
			addPiece(new Knight(1,0,BLACK));
			addPiece(new Knight(6,0,BLACK));
			addPiece(new Bishop(2,0,BLACK));
			addPiece(new Bishop(5,0,BLACK));
			addPiece(new King(4,0,BLACK));
			addPiece(new Queen(3,0,BLACK));
			break;
		case HORDE_WHITE :
			for(int i = 4;i < 8;i++){
				for(int j = 0;j < 8;j++){
					addPiece(new Pawn(j,i,WHITE));
				}
			}
			addPiece(new Pawn(1,3,WHITE));
			addPiece(new Pawn(2,3,WHITE));
			addPiece(new Pawn(5,3,WHITE));
			addPiece(new Pawn(6,3,WHITE));
			for(int i = 0;i < 8;i++){
				addPiece(new Pawn(i,1,BLACK));
			}
			addPiece(new Rook(0,0,BLACK));
			addPiece(new Rook(7,0,BLACK));
			addPiece(new Knight(1,0,BLACK));
			addPiece(new Knight(6,0,BLACK));
			addPiece(new Bishop(2,0,BLACK));
			addPiece(new Bishop(5,0,BLACK));
			addPiece(new King(3,0,BLACK));
			addPiece(new Queen(4,0,BLACK));
			break;
		case HORDE_BLACK :
			for(int i = 0;i < 4;i++){
				for(int j = 0;j < 8;j++){
					addPiece(new Pawn(j,i,BLACK));
				}
			}
			addPiece(new Pawn(1,4,BLACK));
			addPiece(new Pawn(2,4,BLACK));
			addPiece(new Pawn(5,4,BLACK));
			addPiece(new Pawn(6,4,BLACK));
			for(int i = 0;i < 8;i++){
				addPiece(new Pawn(i,6,WHITE));
			}
			addPiece(new Rook(0,7,WHITE));
			addPiece(new Rook(7,7,WHITE));
			addPiece(new Knight(1,7,WHITE));
			addPiece(new Knight(6,7,WHITE));
			addPiece(new Bishop(2,7,WHITE));
			addPiece(new Bishop(5,7,WHITE));
			addPiece(new King(3,7,WHITE));
			addPiece(new Queen(4,7,WHITE));
			break;	
	}

}

Chess_Board::~Chess_Board(){
	/*for(auto i : white_pieces){
		delete i;
	}
	white_pieces.clear();*/
}

Chess_Board Chess_Board::operator=(Chess_Board &b){
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			data[i][j] = 0;
		}
	}
	status = 0;
	for(auto i : white_pieces){
		delete i;
	}
	white_pieces.clear();

	for(auto i : black_pieces){
		delete i;
	}
	black_pieces.clear();

	std::list<Piece*>::iterator i;
       	i = b.white_pieces.begin();
	while(i != b.white_pieces.end()){
		Piece *p = *i;
		switch(p->getType()){
			case PAWN : 
				addPiece(new Pawn(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case KNIGHT :
				addPiece(new Knight(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case BISHOP :
				addPiece(new Bishop(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case ROOK : 
				addPiece(new Rook(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case QUEEN :
				addPiece(new Queen(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case KING :
				addPiece(new King(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
		}
		i++;
	}

	i = b.black_pieces.begin();
	while(i != b.black_pieces.end()){
		Piece *p = *i;
		switch(p->getType()){
			case PAWN : 
				addPiece(new Pawn(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case KNIGHT :
				addPiece(new Knight(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case BISHOP :
				addPiece(new Bishop(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case ROOK : 
				addPiece(new Rook(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case QUEEN :
				addPiece(new Queen(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
			case KING :
				addPiece(new King(p->getX(),p->getY(),p->getColor(),p->isMoved()));
				break;
		}
		i++;
	}
	return *this;
}

int Chess_Board::getStatus(Color c){
	int n = 4*status;
	if(data[3][3])n += 2*data[3][3] / abs(data[3][3]);
	if(data[3][4])n += 2*data[3][4] / abs(data[3][4]);
	if(data[4][4])n += 2*data[4][4] / abs(data[4][4]);
	if(data[4][3])n += 2*data[4][3] / abs(data[4][3]);

	if(data[2][2])n += data[2][2] / abs(data[2][2]);
	if(data[3][2])n += data[3][2] / abs(data[3][2]);
	if(data[4][2])n += data[4][2] / abs(data[4][2]);
	if(data[5][2])n += data[5][2] / abs(data[5][2]);
	if(data[2][3])n += data[2][3] / abs(data[2][3]);
	if(data[5][3])n += data[5][3] / abs(data[5][3]);
	if(data[2][4])n += data[2][4] / abs(data[2][4]);
	if(data[5][4])n += data[5][4] / abs(data[5][4]);
	if(data[2][5])n += data[2][5] / abs(data[2][5]);
	if(data[3][5])n += data[3][5] / abs(data[3][5]);
	if(data[4][5])n += data[4][5] / abs(data[4][5]);
	if(data[5][5])n += data[5][5] / abs(data[5][5]);


	return (c == WHITE)? n : -n;
}

int Chess_Board::getCount(Color c){
	return (c == WHITE)? white_pieces.size() : black_pieces.size();
}

int Chess_Board::getData(unsigned int x,unsigned int y){
	return data[x][y];
}

void Chess_Board::addPiece(Piece *p){
	if(isEmpty(p->getX(),p->getY())){
		switch(p->getColor()){
			case WHITE :
				white_pieces.push_back(p);
				data[p->getX()][p->getY()] = p->getValue();
				status += p->getValue();
				break;
			case BLACK :
				black_pieces.push_back(p);
				data[p->getX()][p->getY()] = -p->getValue();
				status -= p->getValue();
				break;
		}
	}
}

void Chess_Board::removePiece(unsigned int x,unsigned int y){
	if(isInBound(x,y) && !isEmpty(x,y)){
		Piece *piece = getPiece(x,y);
		for(std::list<Piece*>::iterator it = white_pieces.begin();it != white_pieces.end();it++){
			if(piece == *it){
				status -= piece->getValue();
				white_pieces.erase(it);
				data[x][y] = 0;
				return;
			}
		}
	
		for(std::list<Piece*>::iterator it = black_pieces.begin();it != black_pieces.end();it++){
			if(piece == *it){
				status += piece->getValue();
				black_pieces.erase(it);
				data[x][y] = 0;
				return;
			}
		}
	}
}

Piece* Chess_Board::getPiece(unsigned int x,unsigned int y){
	if(data[x][y] == 0){
		return 0;
	}

	for(Piece *p : white_pieces){
		if(p->getX() == x && p->getY() == y){
			return p;
		}
	}

	for(Piece *p : black_pieces){
		if(p->getX() == x && p->getY() == y){
			return p;
		}
	}
	return 0;
}

bool Chess_Board::play(unsigned int x,unsigned int y,short m){
	if(isLegal(x,y,m)){
		Piece *p = getPiece(x,y);
		Point goal = Piece::getMovement(p->getType(),p->getColor(),m);
		removePiece(x + goal.x,y + goal.y);
		data[p->getX()][p->getY()] = 0;
		p->move(m);
		data[p->getX()][p->getY()] = (p->getColor() == WHITE)? p->getValue() : -p->getValue();
		return true;
	}else{
		return false;
	}
}

bool Chess_Board::play(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2){
	if(!isInBound(x1,y1) || isEmpty(x1,y1))return false;
	Piece *piece = getPiece(x1,y1);
	for(int m = 0;m < piece->getMobility();m++){
		Point point = Piece::getMovement(piece->getType(),piece->getColor(),m);
		if(x2 == x1 + point.x && y2 == y1 + point.y){
			if(play(x1,y1,m))return true;
		}
	}
	return false;
}

bool Chess_Board::play(Color c,unsigned int index,short m){
	std::list<Piece*>::iterator i = (c == WHITE)? white_pieces.begin() : black_pieces.begin();
	for(int j = 0;j < index;j++){
		i++;
	}
	Piece *p = *i;
	if(isLegal(p->getX(),p->getY(),m)){
		Point goal = Piece::getMovement(p->getType(),p->getColor(),m);
		
		removePiece(p->getX() + goal.x,p->getY() + goal.y);
		data[p->getX()][p->getY()] = 0;
		p->move(m);
		data[p->getX()][p->getY()] = (p->getColor() == WHITE)? p->getValue() : -p->getValue();
		return true;
	}else{
		return false;
	}
}

bool Chess_Board::playAI(Color c,int level){
	if(getCount(c) == 0)return false;
	Chess_Board board(EMPTY);
       	board = *this;
	Chess_Board board2 = Chess_Board::getMinMax(board,c,level);
	*this = board2;
	return true;	
}

Chess_Board Chess_Board::getMinMax(Chess_Board board,Color c,int level){
	std::list<Piece*>::iterator it;
	Chess_Board best_node;
	int best_status = -1000;
	if(c == WHITE){
		if(level == 0){
			for(auto piece : board.white_pieces){
				int m = 0;
				while(m < piece->getMobility()){
					Chess_Board node(EMPTY);
					node = board;
					if(node.play(piece->getX(),piece->getY(),m)){
					       	int node_status = node.getStatus(c);
						if(best_status < node_status){
							best_status = node_status;
							best_node = node;
						}else if(best_status == node_status && rand() % 2){
							best_status = node_status;
							best_node = node;
						}
						m++;
					}else{
						m = piece->pass(m);
					}
					for(auto i : node.white_pieces){
						delete i;
					}
					node.white_pieces.clear();
					for(auto i : node.black_pieces){
						delete i;
					}
					node.black_pieces.clear();
				}
			}
			return best_node;
		}else{
			for(auto piece : board.white_pieces){
				int m = 0;
				while(m < piece->getMobility()){
					Chess_Board node(EMPTY);
					node = board;
					if(node.play(piece->getX(),piece->getY(),m)){
						Chess_Board max_node = Chess_Board::getMinMax(node,(c == WHITE)? BLACK : WHITE,level - 1);
					       	int node_status = max_node.getStatus(c);
						if(best_status < node_status){
							best_status = node_status;
							best_node = node;
						}else if(best_status == node_status && rand() % 2){
							best_status = node_status;
							best_node = node;
						}
						m++;
					}else{
						m = piece->pass(m);
					}
					for(auto i : node.white_pieces){
						delete i;
					}
					node.white_pieces.clear();
					for(auto i : node.black_pieces){
						delete i;
					}
					node.black_pieces.clear();
				}
			}
			return best_node;
		}

	}else{
		if(level == 0){
			for(auto piece : board.black_pieces){
				int m = 0;
				while(m < piece->getMobility()){
					Chess_Board node(EMPTY);
					node = board;
					if(node.play(piece->getX(),piece->getY(),m)){
					       	int node_status = node.getStatus(c);
						if(best_status < node_status){
							best_status = node_status;
							best_node = node;
						}else if(best_status == node_status && rand() % 2){
							best_status = node_status;
							best_node = node;
						}
						m++;
					}else{
						m = piece->pass(m);
					}
					for(auto i : node.white_pieces){
						delete i;
					}
					node.white_pieces.clear();
					for(auto i : node.black_pieces){
						delete i;
					}
					node.black_pieces.clear();
				}
			}
			return best_node;
		}else{
			for(auto piece : board.black_pieces){
				int m = 0;
				while(m < piece->getMobility()){
					Chess_Board node(EMPTY);
					node = board;
					if(node.play(piece->getX(),piece->getY(),m)){
						Chess_Board max_node = Chess_Board::getMinMax(node,(c == WHITE)? BLACK : WHITE,level - 1);
					       	int node_status = max_node.getStatus(c);
						if(best_status < node_status){
							best_status = node_status;
							best_node = node;
						}else if(best_status == node_status && rand() % 2){
							best_status = node_status;
							best_node = node;
						}
						m++;
					}else{
						m = piece->pass(m);
					}
					for(auto i : node.white_pieces){
						delete i;
					}
					node.white_pieces.clear();

					for(auto i : node.black_pieces){
						delete i;
					}
					node.black_pieces.clear();
				}
			}
			return best_node;
		}
	}
}

void Chess_Board::teleport(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2){
	if(isEmpty(x1,y1))return;
	Piece *p = getPiece(x1,y1);
	if(!isEmpty(x2,y2)){
		removePiece(x2,y2);
	}
	data[x1][y1] = 0;
	p->setX(x2);
	p->setY(y2);
	data[x2][y2] = (p->getColor() == WHITE)? p->getValue() : -p->getValue();
}

bool Chess_Board::isLegal(unsigned int x,unsigned int y,short m){
	if(!isInBound(x,y) || isEmpty(x,y)){
		return false;
	}
	Piece *p = getPiece(x,y);
	Point mov,goal;	
	mov = Piece::getMovement(p->getType(),p->getColor(),m);
	goal = Point(p->getX() + mov.x,p->getY() + mov.y);
	if(!isInBound(goal.x,goal.y)){
		return false;
	}
	if(p->getType() == PAWN){
		if((m % 4) == 0 && isEmpty(goal.x,goal.y)){
			return true;
		}
		if((m % 4) == 1 && !p->isMoved() && isEmpty(goal.x,goal.y) && isEmpty(p->getX() + (mov.x / 2),p->getY() + (mov.y / 2))){
			return true;
		}
		if(((m % 4) == 2 || (m % 4) == 3) && !isEmpty(goal.x,goal.y) && p->getColor() != getPiece(goal.x,goal.y)->getColor()){
			return true;
		}
	}

	if(p->getType() == KNIGHT){
		if(isEmpty(goal.x,goal.y) || (p->getColor() != getPiece(goal.x,goal.y)->getColor())){
			return true;
		}
	}

	if(p->getType() == BISHOP || p->getType() == ROOK || p->getType() == QUEEN){
		int x = p->getX();
		int y = p->getY();
		
		if(x > goal.x){
			x--;
		}else if(x < goal.x){
			x++;
		}
		if(y > goal.y){
			y--;
		}else if(y < goal.y){
			y++;	
		}
		while(x != goal.x || y != goal.y){
			if(!isEmpty(x,y)){
				return false;
			}
			if(x > goal.x){
				x--;
			}else if(x < goal.x){
				x++;
			}
			if(y > goal.y){
				y--;
			}else if(y < goal.y){
				y++;
			}
		}
		if(isEmpty(goal.x,goal.y) || p->getColor() != getPiece(goal.x,goal.y)->getColor()){
			return true;
		}else{
			return false;
		}
	}

	if(p->getType() ==  KING){
		if(isEmpty(goal.x,goal.y) || p->getColor() != getPiece(goal.x,goal.y)->getColor()){
			return true;
		}
	}	
}

bool Chess_Board::isEmpty(unsigned int x,unsigned int y){
	return (isInBound(x,y) && data[x][y] == 0)? true : false;
}

bool Chess_Board::isInBound(unsigned int x,unsigned int y){
	return (x < Chess_Board::width && y < Chess_Board::height)? true : false;
}

void Chess_Board::print(){
	for(int i = 0;i < Chess_Board::height;i++){
		for(int j = 0;j < Chess_Board::width;j++){		
			std::cout << (int)data[j][i] << "\t";
		}
		std::cout << std::endl << std::endl;
	}
}
