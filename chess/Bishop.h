#pragma once
#include "Figure.h"

class Bishop : public Figure {
public:
	Bishop(sf::Texture* _t, bool color, int x, int y) {
		init(_t, 2, color, x, y);
	};
	bool checkMove(Figure* f[]);
	bool underAttack(sf::Vector2f move, Figure* f, Figure* farr[]);
	friend void destroy(Figure* f);
	
};

