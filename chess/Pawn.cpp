#include "Pawn.h"
#include "Queen.h"

extern sf::Vector2f lastMovePos;

bool Pawn::underAttack(sf::Vector2f move, Figure* f, Figure* farr[]) {
	if (f->_color == true && _color == false) {
		if (oldPos + sf::Vector2f(-size, -size) == move || oldPos + sf::Vector2f(size, -size) == move) {
			return true;
		}
	}
	if (f->_color == false && _color == true) {
		if (oldPos + sf::Vector2f(-size, size) == move || oldPos + sf::Vector2f(size, size) == move) {
			return true;
		}
	}
	return false;
}

bool Pawn::checkMove(Figure* f[]) {
	sf::Vector2f dir;
	dir = newPos - oldPos;
	int n = 99;
	for (int i = 0; i < 48; i++)
	{
		n = i;
		if (newPos == f[i]->oldPos && _color == f[i]->_color)
			return false;
		if (dir.x == 0) {
			if (!_color && oldPos + sf::Vector2f(0, -size) == f[i]->oldPos)
				return false;
			if(_color && oldPos + sf::Vector2f(0, size) == f[i]->oldPos)
				return false;
		}
		if (dir.x > 0) {
			
			if (!_color && oldPos + sf::Vector2f(size, -size) == f[i]->oldPos || !_color && f[i]->oldPos == oldPos + sf::Vector2f(size, 0) && f[i]->lastPos == f[i]->oldPos + sf::Vector2f(0, -size * 2) && i >= 8 && i <= 15 && lastMovePos == f[i]->lastPos) {
				goto rightw;
			}

			if (_color && oldPos + sf::Vector2f(size, size) == f[i]->oldPos || _color && f[i]->oldPos == oldPos + sf::Vector2f(size, 0) && f[i]->lastPos == f[i]->oldPos + sf::Vector2f(0, size * 2) && i >= 32 && i <= 39 && lastMovePos == f[i]->lastPos) {
				goto leftb;
			}
				
		}
		if (dir.x < 0) {
			if (!_color && oldPos + sf::Vector2f(-size, -size) == f[i]->oldPos || !_color && f[i]->oldPos == oldPos + sf::Vector2f(-size, 0) && f[i]->lastPos == f[i]->oldPos + sf::Vector2f(0, -size * 2) && i >= 8 && i <= 15 && lastMovePos == f[i]->lastPos)
				goto leftw;
			if (_color && oldPos + sf::Vector2f(-size, size) == f[i]->oldPos || _color && f[i]->oldPos == oldPos + sf::Vector2f(-size, 0) && f[i]->lastPos == f[i]->oldPos + sf::Vector2f(0, size * 2) && i >= 32 && i <= 39 && lastMovePos == f[i]->lastPos)
				goto rightb;
		}
	}
	//bia³e
	if (!_color && !attackLeft && !attackRight) {
		if (!haveMoved && newPos == oldPos + sf::Vector2f(0, -size * 2)) {
			haveMoved = true;
			return true;
		}
		if (newPos == oldPos + sf::Vector2f(0, -size)) {
			if(!haveMoved)
				haveMoved = true;
			upgradePawn(f);
			return true;
		}
	}
	if (!_color && attackLeft) {
		leftw:
		if (newPos == oldPos + sf::Vector2f(-size, -size)) {
			if (!haveMoved)
				haveMoved = true;
			upgradePawn(f);
			destroy(f[n]);
			return true;
		}
	}
	if (!_color && attackRight) {
		rightw:
		if (newPos == oldPos + sf::Vector2f(size, -size)) {
			if (!haveMoved)
				haveMoved = true;
			upgradePawn(f);
			destroy(f[n]);
			return true;
		}
	}

	
	//czarne
	if (_color && !attackLeft && !attackRight) {
		if (!haveMoved && newPos == oldPos + sf::Vector2f(0, size * 2)) {
			haveMoved = true;
			return true;
		}
		if (newPos == oldPos + sf::Vector2f(0, size)) {
			if (!haveMoved)
				haveMoved = true;
			upgradePawn(f);
			return true;
		}
	}
	if (_color && attackLeft) {
	leftb:
		if (newPos == oldPos + sf::Vector2f(size, size)) {
			if (!haveMoved)
				haveMoved = true;
			upgradePawn(f);
			destroy(f[n]);
			return true;
		}
	}
	if (_color && attackRight) {
	rightb:
		if (newPos == oldPos + sf::Vector2f(-size, size)) {
			if (!haveMoved)
				haveMoved = true;;
			upgradePawn(f);
			destroy(f[n]);
			return true;
		}
	}
	return false;
}

//ulepsza siê do królowej, ale mo¿naby zrobiæ wybór dowolnej figury
void Pawn::upgradePawn(Figure* f[]) {
	int index;
	for (int i = 0; i < 48; i++) {
		if (f[i] == this)
			index = i + 8;
	}
	//std::cout << "Index to upgrade: " << index << "\n";
	if (!_color && newPos.y == 0) {
		int tempx = newPos.x;
		int tempy = newPos.y;
		destroy(this);
		
		//std::cout << "Pawn moved to death\n";
		f[index]->s.setPosition(tempx, tempy);
		f[index]->oldPos.y = tempy;
		f[index]->oldPos.x = tempx;
		for (int i = 0; i < 48; i++) {
			if (f[index]->oldPos == f[i]->oldPos && f[index] != f[i])
				destroy(f[i]);
		}
	}
	if (_color && newPos.y == size * 7) {
		int tempx = newPos.x;
		int tempy = newPos.y;
		destroy(this);
		//std::cout << "Pawn moved to death\n";
		f[index]->s.setPosition(tempx, tempy);
		f[index]->oldPos.y = tempy;
		f[index]->oldPos.x = tempx;
		for (int i = 0; i < 48; i++) {
			if (f[index]->oldPos == f[i]->oldPos && f[index] != f[i])
				destroy(f[i]);
		}
	} 
}

