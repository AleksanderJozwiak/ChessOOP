#pragma once
#include "Figure.h"

class Tower : public Figure {
public:
	Tower(sf::Texture* _t, bool color, int x, int y) {
		init(_t, 4, color, x, y);
	};
	bool underAttack(sf::Vector2f move, Figure* f, Figure* farr[]);
	bool checkMove(Figure* f[]);
};
