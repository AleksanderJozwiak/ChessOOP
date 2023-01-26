#pragma once
#include "Figure.h"

class Pawn : public Figure {
private:
	bool attackLeft = false;
	bool attackRight = false;
public:
	Pawn(sf::Texture* _t, bool color, int x, int y) {
		init(_t, 5, color, x, y);
	};
	bool checkMove(Figure* f[]);
	bool underAttack(sf::Vector2f move, Figure* f, Figure* farr[]);
	void upgradePawn(Figure* f[]);

};