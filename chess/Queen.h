#pragma once
#include "Figure.h"

class Queen : public Figure {
public:
	Queen(sf::Texture* _t, bool color, int x, int y) {
		init(_t, 1, color, x, y);
	};
	bool underAttack(sf::Vector2f move, Figure* f, Figure* farr[]);
	bool checkMove(Figure* f[]);
};
