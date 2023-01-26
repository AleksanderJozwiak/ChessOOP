#include "Queen.h"

bool Queen::underAttack(sf::Vector2f move, Figure* f, Figure* farr[]) {

	if (f->_color != _color) {
		sf::Vector2f dir;
		dir = move - oldPos;
		for (int i = 0; i < 48; i++)
		{
			
			if (dir.x == 0 && dir.y != 0) {
				for (sf::Vector2f j(0, size); j.y < dir.y; j += sf::Vector2f(0, size)) {
					if (oldPos + j == farr[i]->oldPos && farr[i] != this) {
						//std::cout << "Test\n";
						return false;
					}
				}
				for (sf::Vector2f j(0, -size); j.y > dir.y; j -= sf::Vector2f(0, size)) {
					if (oldPos + j == farr[i]->oldPos && farr[i] != this) {
						//std::cout << "Test2\n";
						return false;
					}
				}
			}
			if (dir.y == 0 && dir.x != 0) {
				for (sf::Vector2f j(size, 0); j.x < dir.x; j += sf::Vector2f(size, 0)) {
					if (oldPos + j == farr[i]->oldPos && farr[i] != this) {
						//std::cout << "Test3\n";
						return false;
					}
				}
				for (sf::Vector2f j(-size, 0); j.x > dir.x; j -= sf::Vector2f(size, 0)) {
					if (oldPos + j == farr[i]->oldPos && farr[i] != this) {
						//std::cout << "Test4\n";
						return false;
					}
				}
			}
			

			if (dir.x > 0 && dir.y > 0) {
				for (sf::Vector2f j(size, size); j.x < dir.x; j += sf::Vector2f(size, size)) {
					if (oldPos + j == farr[i]->oldPos && farr[i] != this) {
						//std::cout << "Test\n";
						return false;
					}
				}
			}
			if (dir.x < 0 && dir.y < 0) {
				for (sf::Vector2f j(-size, -size); j.x > dir.x; j -= sf::Vector2f(size, size)) {
					if (oldPos + j == farr[i]->oldPos && farr[i] != this) {
						//std::cout << "Test2\n";
						return false;
					}
				}
			}
			if (dir.x < 0 && dir.y > 0) {
				for (sf::Vector2f j(-size, size); j.x > dir.x; j += sf::Vector2f(-size, size)) {
					if (oldPos + j == farr[i]->oldPos && farr[i] != this) {
						//std::cout << "Test3\n";
						return false;
					}
				}
			}
			if (dir.x > 0 && dir.y < 0) {
				for (sf::Vector2f j(size, -size); j.x < dir.x; j += sf::Vector2f(size, -size)) {
					if (oldPos + j == farr[i]->oldPos && farr[i] != this) {
						//std::cout << "Test4\n";
						return false;
					}
				}
			}
		}

		for (int j = 0; j < 8; j++) {
			//bishop part
			if (move == oldPos + sf::Vector2f(size * j, size * j))
				return true;
			if (move == oldPos + sf::Vector2f(-size * j, -size * j))
				return true;
			if (move == oldPos + sf::Vector2f(size * j, -size * j))
				return true;
			if (move == oldPos + sf::Vector2f(-size * j, size * j))
				return true;
			//tower part
			if (move == oldPos + sf::Vector2f(0, size * j))
				return true;
			if (move == oldPos + sf::Vector2f(0, -size * j))
				return true;
			if (move == oldPos + sf::Vector2f(size * j, 0))
				return true;
			if (move == oldPos + sf::Vector2f(-size * j, 0))
				return true;
		}
	}

	return false;
}

bool Queen::checkMove(Figure* f[]) {
	sf::Vector2f dir;
	dir = newPos - oldPos;
	if (newPos.x >= 1000 || newPos.x < 0 || newPos.y >= 1000 || newPos.y < 0)
		return false;
	for (int i = 0; i < 48; i++)
	{
		if (newPos == f[i]->oldPos && _color == f[i]->_color)
			return false;
		
		if (dir.x == 0 && dir.y != 0) {
			for (sf::Vector2f j(0, size); j.y < dir.y; j += sf::Vector2f(0, size)) {
				if (oldPos + j == f[i]->oldPos && f[i] != this) {
					//std::cout << "Test\n";
					return false;
				}
			}
			for (sf::Vector2f j(0, -size); j.y > dir.y; j -= sf::Vector2f(0, size)) {
				if (oldPos + j == f[i]->oldPos && f[i] != this) {
					//std::cout << "Test2\n";
					return false;
				}
			}
		}
		if (dir.y == 0 && dir.x != 0) {
			for (sf::Vector2f j(size, 0); j.x < dir.x; j += sf::Vector2f(size, 0)) {
				if (oldPos + j == f[i]->oldPos && f[i] != this) {
					//std::cout << "Test3\n";
					return false;
				}
			}
			for (sf::Vector2f j(-size, 0); j.x > dir.x; j -= sf::Vector2f(size, 0)) {
				if (oldPos + j == f[i]->oldPos && f[i] != this) {
					//std::cout << "Test4\n";
					return false;
				}
			}
		}
		
		if (dir.x > 0 && dir.y > 0) {
			for (sf::Vector2f j(size, size); j.x < dir.x; j += sf::Vector2f(size, size)) {
				if (oldPos + j == f[i]->oldPos && f[i] != this) {
					//std::cout << "Test\n";
					return false;
				}
			}
		}
		if (dir.x < 0 && dir.y < 0) {
			for (sf::Vector2f j(-size, -size); j.x > dir.x; j -= sf::Vector2f(size, size)) {
				if (oldPos + j == f[i]->oldPos && f[i] != this) {
					//std::cout << "Test2\n";
					return false;
				}
			}
		}
		if (dir.x < 0 && dir.y > 0) {
			for (sf::Vector2f j(-size, size); j.x > dir.x; j += sf::Vector2f(-size, size)) {
				if (oldPos + j == f[i]->oldPos && f[i] != this) {
					//std::cout << "Test3\n";
					return false;
				}
			}
		}
		if (dir.x > 0 && dir.y < 0) {
			for (sf::Vector2f j(size, -size); j.x < dir.x; j += sf::Vector2f(size, -size)) {
				if (oldPos + j == f[i]->oldPos && f[i] != this) {
					//std::cout << "Test4\n";
					return false;
				}
			}
		}
	}
	
	for (int j = 0; j < 8; j++) {
		//bishop part
		if (newPos == oldPos + sf::Vector2f(size * j, size * j))
			return true;
		if (newPos == oldPos + sf::Vector2f(-size * j, -size * j))
			return true;
		if (newPos == oldPos + sf::Vector2f(size * j, -size * j))
			return true;
		if (newPos == oldPos + sf::Vector2f(-size * j, size * j))
			return true;
		//tower part
		if (newPos == oldPos + sf::Vector2f(0, size * j))
			return true;
		if (newPos == oldPos + sf::Vector2f(0, -size * j))
			return true;
		if (newPos == oldPos + sf::Vector2f(size * j, 0))
			return true;
		if (newPos == oldPos + sf::Vector2f(-size * j, 0))
			return true;
	}

	return false;
}