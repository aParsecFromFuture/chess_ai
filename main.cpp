#include <iostream>
#include <ctime>
#include <thread>
#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>
#include <gdkmm/general.h>
#include <giomm/resource.h>
#include "chess_board.h"

class MyApp : public Gtk::Application{
	protected:
	void on_open(const Gio::Application::type_vec_files& files,const Glib::ustring& hint)override{
		std::cout << "ok" << std::endl;
	}

	void on_activate()override{
		std::cout << "ok" << std::endl;
	}
};

class Game : public Gtk::DrawingArea{
	public:
		Glib::RefPtr<Gdk::Pixbuf> board_image,pieces_image;
		Chess_Board chess = Chess_Board(CLASSIC);
		double p_width,p_height,block_x,block_y;
		Game(){
			try{
				board_image = Gdk::Pixbuf::create_from_file("image/board.jpg");
				pieces_image = Gdk::Pixbuf::create_from_file("image/pieces.png");
			}catch(const Gio::ResourceError& ex){
				std::cerr << "ResourceError : " << ex.what() << std::endl;
			}catch(const Gdk::PixbufError& ex){
				std::cerr << "PixbufError : " << ex.what() << std::endl;
			}
			if(board_image){
				set_size_request(board_image->get_width()/2,board_image->get_height()/2);
				p_width = pieces_image->get_width() / 6;
				p_height = pieces_image->get_height() / 2;
			}
			if(pieces_image){
				block_x = ((board_image->get_width() / 8) / 0.5);
				block_y = ((board_image->get_height() / 8) / 0.30);
			}
		}
	protected:
		bool on_draw(const Cairo::RefPtr<Cairo::Context>&cr)override{
			if(!board_image || !pieces_image){
				return false;
			}
			Gtk::Allocation allocation = get_allocation();	
			
			cr->scale(0.5,0.5);
			Gdk::Cairo::set_source_pixbuf(cr,board_image,0,0);
			cr->paint();

			cr->scale(0.5,0.3);

			int order_x,order_y,coord_x,coord_y;

			for(int i = 0;i < 8;i++){
				for(int j = 0;j < 8;j++){
					int data = chess.getData(i,j);
					switch(data){
						case 0 : continue;
						case 1 : order_x = 0;order_y = 0;break;
						case 2 : order_x = 2;order_y = 0;break;
						case 3 : order_x = 3;order_y = 0;break;
						case 5 : order_x = 1;order_y = 0;break;
						case 9 : order_x = 4;order_y = 0;break;
						case 64 : order_x = 5;order_y = 0;break;
						case -1 : order_x = 5;order_y = 1;break;
						case -2 : order_x = 3;order_y = 1;break;
						case -3 : order_x = 2;order_y = 1;break;
						case -5 : order_x = 4;order_y = 1;break;
						case -9 : order_x = 1;order_y = 1;break;
						case -64 : order_x = 0;order_y = 1;break;
					}
					coord_x = i;
					coord_y = j;

					int set_x = coord_x * block_x - (p_width * order_x) + (30 * order_x / 6);
					int set_y = coord_y * block_y - (p_height * order_y);
					int fill_x = coord_x * block_x + (30 * order_x / 6);
					int fill_y = coord_y * block_y;
					Gdk::Cairo::set_source_pixbuf(cr,pieces_image,set_x,set_y);
					cr->rectangle(fill_x,fill_y,p_width,p_height);
					cr->fill();
				}
			}
			return true;
		}
	public:
		void foo(){
			int x,y,z,w;
			srand(time(0));
			for(int i = 0;i < 200;i++){
				if(!chess.playAI(WHITE,2))break;
				queue_draw();
				if(!chess.playAI(BLACK,2))break;
				queue_draw();
			}
		}
};

int main(int argc,char *argv[]){
	auto app = MyApp::create();

	Gtk::Window window;
	Game g;

	window.set_default_size(300,300);
	window.set_border_width(10);
	window.set_title("Chess AI v1.0");
	
	window.add(g);
	window.show_all_children();
	std::thread th1(&Game::foo,&g);
	
	return app->run(window);
}
