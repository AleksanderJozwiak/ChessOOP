#include<SFML/Graphics.hpp>
#include<iostream>
#include<Windows.h>
#include "Pawn.h"
#include "Bishop.h"
#include "Tower.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"


using namespace sf;

bool whiteMove = true;


Vector2f lastMovePos;

bool MouseOver(int MouseX, int MouseY, Sprite btn)
{

	if (MouseX - btn.getPosition().x > btn.getTextureRect().left && MouseX - btn.getPosition().x < btn.getTextureRect().width)
	{
		if (MouseY - btn.getPosition().y > btn.getTextureRect().top && MouseY - btn.getPosition().y < btn.getTextureRect().height)
			return true;
	}
	return false;
}

std::string toChessNote(Vector2f p) {
	std::string s = "";
	s += char(p.x / 125 + 97);
	s += char(7 - p.y / 125 + 49);
	return s;
}

void inGame(RenderWindow& window) {

	Texture ww, bw;
	ww.loadFromFile("img\\ww.png");
	bw.loadFromFile("img\\bw.png");
	ww.setSmooth(true);
	bw.setSmooth(true);

	Sprite wWin(ww);
	Sprite bWin(bw);
	wWin.setPosition(0, 250);
	bWin.setPosition(0, 250);

	Texture texture, t2;
	texture.loadFromFile("img\\Chesspieces.png");
	t2.loadFromFile("img\\Checkerboard.png");
	texture.setSmooth(true);
	t2.setSmooth(true);

	Figure* f[] = {
			//czarne
			new King(&texture, true, 4, 0),				//0
			new Queen(&texture, true, 3, 0),			//1
			new Tower(&texture, true, 0, 0),			//2
			new Tower(&texture, true, 7, 0),			//3
			new Knight(&texture, true, 1, 0),			//4	
			new Knight(&texture, true, 6, 0),			//5
			new Bishop(&texture, true, 2, 0),			//6
			new Bishop(&texture, true, 5, 0),			//7
			new Pawn(&texture, true, 0, 1),				//8
			new Pawn(&texture, true, 1, 1),				//9
			new Pawn(&texture, true, 2, 1),				//10
			new Pawn(&texture, true, 3, 1),				//11
			new Pawn(&texture, true, 4, 1),				//12
			new Pawn(&texture, true, 5, 1),				//13
			new Pawn(&texture, true, 6, 1),				//14
			new Pawn(&texture, true, 7, 1),				//15
			new Queen(&texture, true, 30, 1),			//16
			new Queen(&texture, true, 30, 2),			//17
			new Queen(&texture, true, 30, 3),			//18
			new Queen(&texture, true, 30, 4),			//19
			new Queen(&texture, true, 30, 5),			//20
			new Queen(&texture, true, 30, 6),			//21
			new Queen(&texture, true, 30, 7),			//22
			new Queen(&texture, true, 30, 8),			//23
			//biale
			new King(&texture, false, 4, 7),			//24
			new Queen(&texture, false, 3, 7),			//25
			new Tower(&texture, false, 0, 7),			//26
			new Tower(&texture, false, 7, 7),			//27
			new Knight(&texture, false, 1, 7),			//28
			new Knight(&texture, false, 6, 7),			//29
			new Bishop(&texture, false, 2, 7),			//30
			new Bishop(&texture, false, 5, 7),			//31
			new Pawn(&texture, false, 0, 6),			//32
			new Pawn(&texture, false, 1, 6),			//33
			new Pawn(&texture, false, 2, 6),			//34
			new Pawn(&texture, false, 3, 6),			//35
			new Pawn(&texture, false, 4, 6),			//36
			new Pawn(&texture, false, 5, 6),			//37
			new Pawn(&texture, false, 6, 6),			//38
			new Pawn(&texture, false, 7, 6),			//39
			new Queen(&texture, false, 31, 1),			//40
			new Queen(&texture, false, 31, 2),			//41
			new Queen(&texture, false, 31, 3),			//42
			new Queen(&texture, false, 31, 4),			//43
			new Queen(&texture, false, 31, 5),			//44
			new Queen(&texture, false, 31, 6),			//45
			new Queen(&texture, false, 31, 7),			//46
			new Queen(&texture, false, 31, 8)			//47
	};

	Sprite sBoard(t2);
	int n = 0;
	bool figureSelected = false;

	while (window.isOpen()) {

		Vector2i pos = Mouse::getPosition(window);
		Event e;

		std::string str;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Backspace)) {

					whiteMove = true;
					window.clear();
					window.draw(sBoard);
					
					system("cls");
					for (int i = 0; i < 48; i++)
					{
						f[i]->s.setPosition(f[i]->startingPos);
						f[i]->oldPos = f[i]->startingPos;
						f[i]->newPos = f[i]->startingPos;
						f[i]->haveMoved = false;
						f[i]->draw(window);
					}
			}

			//ruch bia³e
			if (whiteMove) {
				if (e.type == Event::MouseButtonPressed)
					if (e.key.code == Mouse::Left)
						for (int i = 24; i < 48; i++)
							if (f[i]->s.getGlobalBounds().contains(pos.x, pos.y))
							{
								f[i]->isMove = true;
								f[i]->onMove();
								n = i;
								f[i]->dx = pos.x - f[i]->s.getPosition().x;
								f[i]->dy = pos.y - f[i]->s.getPosition().y;
								f[i]->oldPos = f[i]->s.getPosition();
							}
				if (e.type == Event::MouseButtonReleased)
					if (e.key.code == Mouse::Left)
					{
						f[n]->isMove = false;
						f[n]->onMove();
						Vector2f p = f[n]->s.getPosition() + Vector2f(f[n]->size / 2, f[n]->size / 2);
						f[n]->newPos = Vector2f(f[n]->size * int(p.x / f[n]->size), f[n]->size * int(p.y / f[n]->size));
						if (f[n]->checkMove(f) == true) {
							f[n]->checkDestroy(f, f[n]->checkMove(f));
							f[n]->s.setPosition(f[n]->newPos);
							std::cout << toChessNote(f[n]->oldPos);
							std::cout << toChessNote(f[n]->newPos) << "\n";
							f[n]->lastPos = f[n]->oldPos;
							lastMovePos = f[n]->oldPos;
							f[n]->oldPos = f[n]->newPos;
							whiteMove = false;
						}
						else {
							f[n]->s.setPosition(f[n]->oldPos);
						}
					}
				if (f[n]->isMove) {
					f[n]->s.setPosition(pos.x - f[n]->dx, pos.y - f[n]->dy);
				}
				
			}
			//ruch czarne
			if (!whiteMove) {
				if (e.type == Event::MouseButtonPressed)
					if (e.key.code == Mouse::Left)
						for (int i = 0; i < 24; i++)
							if (f[i]->s.getGlobalBounds().contains(pos.x, pos.y))
							{
								f[i]->isMove = true;
								f[i]->onMove();
								n = i;
								f[i]->dx = pos.x - f[i]->s.getPosition().x;
								f[i]->dy = pos.y - f[i]->s.getPosition().y;
								f[i]->oldPos = f[i]->s.getPosition();
							}
				if (e.type == Event::MouseButtonReleased)
					if (e.key.code == Mouse::Left)
					{
						f[n]->isMove = false;
						f[n]->onMove();
						Vector2f p = f[n]->s.getPosition() + Vector2f(f[n]->size / 2, f[n]->size / 2);
						f[n]->newPos = Vector2f(f[n]->size * int(p.x / f[n]->size), f[n]->size * int(p.y / f[n]->size));
						if (f[n]->checkMove(f) == true) {
							f[n]->checkDestroy(f, f[n]->checkMove(f));
							f[n]->s.setPosition(f[n]->newPos);
							std::cout << toChessNote(f[n]->oldPos);
							std::cout << toChessNote(f[n]->newPos) << "\n";
							f[n]->lastPos = f[n]->oldPos;
							lastMovePos = f[n]->oldPos;
							f[n]->oldPos = f[n]->newPos;
							whiteMove = true;
						}
						else {
							f[n]->s.setPosition(f[n]->oldPos);
						}
					}
				if (f[n]->isMove) {
					f[n]->s.setPosition(pos.x - f[n]->dx, pos.y - f[n]->dy);
				}
			}
		}
		
		window.clear();
		window.draw(sBoard);


		//zmieniæ na mata, a nie, ¿e wygrana po zbiciu króla (co oznacza to samo co mat)
		if (f[0]->oldPos.x < -100) {
			window.clear();
			window.draw(sBoard);
			window.draw(wWin);
			
		}
		if (f[24]->oldPos.x < -100) {
			window.clear();
			window.draw(sBoard);
			window.draw(bWin);
		}
		if (f[0]->oldPos.x > -100 && f[24]->oldPos.x > -100) {
			
			for (int i = 0; i < 48; i++)
			{
				f[i]->draw(window);
			}
		}
		window.display();
		
	}
}

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	RenderWindow window(VideoMode(1000, 1000), "Szachy");

	Texture m, pb, pbS, qb, qbS;
	m.loadFromFile("img\\menu.png");
	pb.loadFromFile("img\\playbtn.png");
	pbS.loadFromFile("img\\playbtnS.png");	
	qb.loadFromFile("img\\quitbtn.png");
	qbS.loadFromFile("img\\quitbtnS.png");
	Sprite menu(m);
	Sprite quitBtn(qb);
	Sprite playBtn(pb);
	playBtn.setPosition(312.5, 300);
	quitBtn.setPosition(312.5, 600);

	while (window.isOpen()) {

		Vector2i pos = Mouse::getPosition(window);
		Event e;

		std::string str;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			if (MouseOver(pos.x, pos.y, playBtn)) {
				playBtn.setTexture(pbS);
			} 
			else if(!MouseOver(pos.x, pos.y, playBtn))
			{
				playBtn.setTexture(pb);
			}

			if (MouseOver(pos.x, pos.y, quitBtn)) {
				quitBtn.setTexture(qbS);
			}
			else if (!MouseOver(pos.x, pos.y, quitBtn))
			{
				quitBtn.setTexture(qb);
			}

			if (Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (playBtn.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					inGame(window);
				}
				if (quitBtn.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					window.close();
				}

			}
		}

		window.clear();
		window.draw(menu);
		
		window.draw(playBtn);
		window.draw(quitBtn);
		window.display();
	}
	return 0;
}

