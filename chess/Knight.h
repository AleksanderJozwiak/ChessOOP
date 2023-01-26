#pragma once
#include "Figure.h"

class Knight : public Figure {
public:
	Knight(sf::Texture* _t, bool color, int x, int y) {
		init(_t, 3, color, x, y);
	};
	bool underAttack(sf::Vector2f move, Figure* f, Figure* farr[]);
	bool checkMove(Figure* f[]);
};
