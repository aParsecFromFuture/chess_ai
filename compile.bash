g++ -c piece.cpp -o piece.o
g++ -c chess_board.cpp -o chess_board.o
g++ -std=c++11 -pthread main.cpp chess_board.o piece.o -o main `pkg-config gtkmm-3.0 --cflags --libs`
