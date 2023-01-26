#pragma once
#include "Figure.h"

class King : public Figure {
public:
	King(sf::Texture* _t, bool color, int x, int y) {
		init(_t, 0, color, x, y);
	};
	bool isCheck = false;
	bool isMate = false;
	bool underAttack(sf::Vector2f move, Figure* f, Figure* farr[]);
	bool checkMove(Figure* f[]);
};
