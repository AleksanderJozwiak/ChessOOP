#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Figure{
protected:

	float size = 125;
	Texture _texture;
	int posX;
	int posY;
	bool isMove = false;
	float dx = 0, dy = 0;
	Vector2f oldPos, newPos;
public:
	virtual void Move() {};
};

class Pawn : public Figure, public Sprite {
public:
	Pawn(bool color, int x, int y) {
		_texture.loadFromFile("C:\\Users\\jozwi\\source\\repos\\chess\\x64\\Debug\\img\\Chesspieces.png");
		setTexture(_texture);
		setTextureRect(IntRect(size * 5, size * color, size, size));
		posX = size * x;
		posY = size * y;
		setPosition(posX, posY);

	};

	void Move(Vector2i pos, Event e) {
		//drag and drop
			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
					if (getGlobalBounds().contains(pos.x, pos.y))
					{
						isMove = true;
						dx = pos.x - getPosition().x;
						dy = pos.y - getPosition().y;
						oldPos = getPosition();
					}
			if (e.type == Event::MouseButtonReleased)
				if (e.key.code == Mouse::Left)
				{
					isMove = false;
					Vector2f p = getPosition() + Vector2f(size / 2, size / 2);
					Vector2f newPos = Vector2f(size * int(p.x / size), size * int(p.y / size));
					setPosition(newPos);
				}
			if (isMove) setPosition(pos.x - dx, pos.y - dy);
	}
};

class Tower : public Figure, public Sprite {
public:
	Tower(bool color, int x, int y) {
		_texture.loadFromFile("C:\\Users\\jozwi\\source\\repos\\chess\\x64\\Debug\\img\\Chesspieces.png");
		setTexture(_texture);
		setTextureRect(IntRect(size * 4, size * color, size, size));
		setPosition(size * x, size * y);
		posX = size * x;
		posY = size * y;
	};

	void Move(Vector2i pos, Event e) {
		//drag and drop
		if (e.type == Event::MouseButtonPressed)
			if (e.key.code == Mouse::Left)
				if (getGlobalBounds().contains(pos.x, pos.y))
				{
					isMove = true;
					dx = pos.x - getPosition().x;
					dy = pos.y - getPosition().y;
					oldPos = getPosition();
				}
		if (e.type == Event::MouseButtonReleased)
			if (e.key.code == Mouse::Left)
			{
				isMove = false;
				Vector2f p = getPosition() + Vector2f(size / 2, size / 2);
				Vector2f newPos = Vector2f(size * int(p.x / size), size * int(p.y / size));
				setPosition(newPos);
			}
		if (isMove) setPosition(pos.x - dx, pos.y - dy);
	}
};

class Knight : public Figure, public Sprite {
public:
	Knight(bool color, int x, int y) {
		_texture.loadFromFile("C:\\Users\\jozwi\\source\\repos\\chess\\x64\\Debug\\img\\Chesspieces.png");
		setTexture(_texture);
		setTextureRect(IntRect(size * 3, size * color, size, size));
		setPosition(size * x, size * y);
		posX = size * x;
		posY = size * y;
	};
};

class Bishop : public Figure, public Sprite {
public:
	Bishop(bool color, int x, int y) {
		_texture.loadFromFile("C:\\Users\\jozwi\\source\\repos\\chess\\x64\\Debug\\img\\Chesspieces.png");
		setTexture(_texture);
		setTextureRect(IntRect(size * 2, size * color, size, size));
		setPosition(size * x, size * y);
		posX = size * x;
		posY = size * y;
	};
};

class Queen : public Figure, public Sprite {
public:
	Queen(bool color, int x, int y) {
		_texture.loadFromFile("C:\\Users\\jozwi\\source\\repos\\chess\\x64\\Debug\\img\\Chesspieces.png");
		setTexture(_texture);
		setTextureRect(IntRect(size * 1, size * color, size, size));
		setPosition(size * x, size * y);
		posX = size * x;
		posY = size * y;
	};
};

class King : public Figure, public Sprite {
public:
	King(bool color, int x, int y) {
		_texture.loadFromFile("C:\\Users\\jozwi\\source\\repos\\chess\\x64\\Debug\\img\\Chesspieces.png");
		setTexture(_texture);
		setTextureRect(IntRect(size * 0, size * color, size, size));
		setPosition(size * x, size * y);
		posX = size * x;
		posY = size * y;
	};
};