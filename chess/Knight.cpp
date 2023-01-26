#include "Knight.h"

bool Knight::underAttack(sf::Vector2f move, Figure* f, Figure* farr[]) {
	if (f->_color == true && _color == false) {
		if (move == oldPos + sf::Vector2f(size, size * 2))
			return true;
		if (move == oldPos + sf::Vector2f(-size, size * 2))
			return true;
		if (move == oldPos + sf::Vector2f(size, -size * 2))
			return true;
		if (move == oldPos + sf::Vector2f(-size, -size * 2))
			return true;
		if (move == oldPos + sf::Vector2f(size * 2, size))
			return true;
		if (move == oldPos + sf::Vector2f(size * 2, -size))
			return true;
		if (move == oldPos + sf::Vector2f(-size * 2, size))
			return true;
		if (move == oldPos + sf::Vector2f(-size * 2, -size))
			return true;
	}
	if (f->_color == false && _color == true) {
		if (move == oldPos + sf::Vector2f(size, size * 2))
			return true;
		if (move == oldPos + sf::Vector2f(-size, size * 2))
			return true;
		if (move == oldPos + sf::Vector2f(size, -size * 2))
			return true;
		if (move == oldPos + sf::Vector2f(-size, -size * 2))
			return true;
		if (move == oldPos + sf::Vector2f(size * 2, size))
			return true;
		if (move == oldPos + sf::Vector2f(size * 2, -size))
			return true;
		if (move == oldPos + sf::Vector2f(-size * 2, size))
			return true;
		if (move == oldPos + sf::Vector2f(-size * 2, -size))
			return true;
	}
	return false;
}

bool Knight::checkMove(Figure* f[]) {

	for (int i = 0; i < 48; i++)
	{
		if (newPos == f[i]->oldPos && _color == f[i]->_color)
			return false;
	}
	if (newPos.x >= 1000 || newPos.x < 0 || newPos.y >= 1000 || newPos.y < 0)
		return false;

	if (newPos == oldPos + sf::Vector2f(size, size * 2))
		return true;
	if (newPos == oldPos + sf::Vector2f(-size, size * 2))
		return true;
	if (newPos == oldPos + sf::Vector2f(size, -size * 2))
		return true;
	if (newPos == oldPos + sf::Vector2f(-size, -size * 2))
		return true;
	if (newPos == oldPos + sf::Vector2f(size * 2, size))
		return true;
	if (newPos == oldPos + sf::Vector2f(size * 2, -size))
		return true;
	if (newPos == oldPos + sf::Vector2f(-size * 2, size))
		return true;
	if (newPos == oldPos + sf::Vector2f(-size * 2, -size))
		return true;
	
	return false;

}