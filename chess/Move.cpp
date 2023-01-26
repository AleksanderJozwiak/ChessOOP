#include "Figure.h"

using namespace sf;

void Move(Vector2i pos, Event e, Figure* f) {
	int size = f->getSize();
	if (e.type == Event::MouseButtonPressed)
		if (e.key.code == Mouse::Left)
			if (f->s.getGlobalBounds().contains(pos.x, pos.y))
			{

				f->isMove = true;
				f->dx = pos.x - f->s.getPosition().x;
				f->dy = pos.y - f->s.getPosition().y;
				f->oldPos = f->s.getPosition();
			}
	if (e.type == Event::MouseButtonReleased)
		if (e.key.code == Mouse::Left)
		{
			f->isMove = false;
			Vector2f p = f->s.getPosition() + Vector2f(size / 2, size / 2);
			Vector2f newPos = Vector2f(size * int(p.x / size), size * int(p.y / size));
			f->s.setPosition(newPos);
		}
	if (f->isMove) f->s.setPosition(pos.x - f->dx, pos.y - f->dy);
}