g++ -c piece.cpp -o piece.o
g++ -c chess_board.cpp -o chess_board.o
g++ chess_board.o piece.o main2.cpp -o main2

