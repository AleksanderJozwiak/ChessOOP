#include "King.h"

bool King::underAttack(sf::Vector2f move, Figure* f, Figure* farr[]) {
	if (f->_color != _color) {
		if (move == oldPos + sf::Vector2f(size, size))
			return true;
		if (move == oldPos + sf::Vector2f(size, 0))
			return true;
		if (move == oldPos + sf::Vector2f(size, -size))
			return true;
		if (move == oldPos + sf::Vector2f(0, -size))
			return true;
		if (move == oldPos + sf::Vector2f(0, size))
			return true;
		if (move == oldPos + sf::Vector2f(-size, -size))
			return true;
		if (move == oldPos + sf::Vector2f(-size, 0))
			return true;
		if (move == oldPos + sf::Vector2f(-size, size))
			return true;
	}
	return false;
}

bool King::checkMove(Figure* f[]) {

	for (int i = 0; i < 48; i++)
	{
		if (newPos == f[i]->oldPos && _color == f[i]->_color)
			return false;
		if (f[i]->underAttack(newPos, this, f))
			return false;
	}

	if (newPos.x >= 1000 || newPos.x < 0 || newPos.y >= 1000 || newPos.y < 0)
		return false;
	//roszada bia³e
	if (!_color) {
		//roszada krotka
		if (!haveMoved && newPos == oldPos + sf::Vector2f(size * 2, 0) && f[27]->haveMoved == false) {
			for (int i = 0; i < 48; i++) {
				if (newPos == f[i]->oldPos && f[i] != this)
					return false;
				if (newPos + sf::Vector2f(-size , 0) == f[i]->oldPos && f[i] != this)
					return false;
			}
			f[27]->s.setPosition(size * 5, size * 7);
			f[27]->oldPos = sf::Vector2f(size * 5, size * 7);
			haveMoved = true;
			return true;
		}
		//roszada dluga
		if (!haveMoved && newPos == oldPos + sf::Vector2f(-size * 2, 0) && f[26]->haveMoved == false) {
			for (int i = 0; i < 48; i++) {
				if (newPos == f[i]->oldPos && f[i] != this)
					return false;
				if (newPos + sf::Vector2f(size, 0) == f[i]->oldPos && f[i] != this)
					return false;
				if (newPos + sf::Vector2f(-size, 0) == f[i]->oldPos && f[i] != this)
					return false;
			}
			f[26]->s.setPosition(size * 3, size * 7);
			f[26]->oldPos = sf::Vector2f(size * 3, size * 7);
			haveMoved = true;
			return true;
		}
	}
	//roszada czarne
	if (_color) {
		//roszada krotka
		if (!haveMoved && newPos == oldPos + sf::Vector2f(size * 2, 0) && f[3]->haveMoved == false) {
			for (int i = 0; i < 48; i++) {
				if (newPos == f[i]->oldPos && f[i] != this)
					return false;
				if (newPos + sf::Vector2f(-size, 0) == f[i]->oldPos && f[i] != this)
					return false;
			}
			f[3]->s.setPosition(size * 5, 0);
			f[3]->oldPos = sf::Vector2f(size * 5, size * 7);
			haveMoved = true;
			return true;
		}
		//roszada dluga
		if (!haveMoved && newPos == oldPos + sf::Vector2f(-size * 2, 0) && f[2]->haveMoved == false) {
			for (int i = 0; i < 48; i++) {
				if (newPos == f[i]->oldPos && f[i] != this)
					return false;
				if (newPos + sf::Vector2f(size, 0) == f[i]->oldPos && f[i] != this)
					return false;
				if (newPos + sf::Vector2f(-size, 0) == f[i]->oldPos && f[i] != this)
					return false;
			}
			f[2]->s.setPosition(size * 3, 0);
			f[2]->oldPos = sf::Vector2f(size * 3, size * 7);
			haveMoved = true;
			return true;
		}
	}

	if (newPos == oldPos + sf::Vector2f(size, size)) {
		haveMoved = true;
		return true;
	}
	if (newPos == oldPos + sf::Vector2f(-size, -size)) {
		haveMoved = true;
		return true;
	}
	if (newPos == oldPos + sf::Vector2f(-size, size)) {
		haveMoved = true;
		return true;
	}
	if (newPos == oldPos + sf::Vector2f(size, -size)) {
		haveMoved = true;
		return true;
	}
	if (newPos == oldPos + sf::Vector2f(0, size)) {
		haveMoved = true;
		return true;
	}
	if (newPos == oldPos + sf::Vector2f(0, -size)) {
		haveMoved = true;
		return true;
	}
	if (newPos == oldPos + sf::Vector2f(size, 0)) {
		haveMoved = true;
		return true;
	}
	if (newPos == oldPos + sf::Vector2f(-size, 0)) {
		haveMoved = true;
		return true;
	}

	return false;
}
