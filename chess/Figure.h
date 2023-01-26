#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

class Figure {
public:
	sf::Vector2f startingPos;
	bool haveMoved = false;
	bool isMove = false;
	float dx = 0, dy = 0;
	sf::Vector2f oldPos, newPos, lastPos;
	sf::Texture* t;
	const int size = 125;
	bool _color;
	sf::Sprite s;
	void init(sf::Texture* _t, int index, bool color, int x, int y);
	virtual ~Figure() {};
	void draw(sf::RenderWindow &w);
	virtual bool checkMove(Figure* f[]);
	virtual bool checkDestroy(Figure* f[], bool d);
	virtual bool underAttack(sf::Vector2f move, Figure* f, Figure* farr[]);
	virtual void onMove();
	friend void destroy(Figure* f);
};


