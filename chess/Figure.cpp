#include "Figure.h"

using namespace sf;

void Figure::draw(sf::RenderWindow& w) {
	w.draw(s);
};

void Figure::init(sf::Texture* _t, int index, bool color, int x, int y) {

	t = _t;
	_color = color;
	s.setTexture(*t);
	oldPos = sf::Vector2f(x * size, y * size);
	startingPos = oldPos;
	newPos = oldPos;
	s.setTextureRect(sf::IntRect(size * index, size * color, size, size));
	s.setPosition(oldPos);
}

static int next = 125;

void destroy(Figure* f) {
	if (f->oldPos.x >= 0) {
		f->s.setPosition(-1000, -1000 + next);
		f->newPos = sf::Vector2f(-1000, -1000);
		f->oldPos = sf::Vector2f(-1000, -1000);
		next += 125;
	}
}

bool Figure::checkMove(Figure* f[]) {
	for (int i = 0; i < 48; i++)
	{
		if (newPos == f[i]->oldPos && _color == f[i]->_color)
			return false;
	}
	return true;
}
bool Figure::checkDestroy(Figure* f[], bool d) {
	for (int i = 0; i < 48; i++)
	{
		if (newPos == f[i]->oldPos && _color != f[i]->_color && d == true)
		{
			//std::cout << "Destroyed: (" << f[i]->oldPos.x << "," << f[i]->oldPos.y << ")\n";
			f[i]->haveMoved = true;
			destroy(f[i]);	
		}
	}
	return false;
}

void Figure::onMove() {
	if (isMove == true) {
		s.setScale(1.25f, 1.25f);
	}
	else {
		s.setScale(1.f, 1.f);
	}
}

bool Figure::underAttack(Vector2f move, Figure* f, Figure* farr[]) {
	return false;
}

