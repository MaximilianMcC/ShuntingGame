#pragma once

#include "track.h"

class locomotive
{
private:
	sf::RectangleShape shape;

	Track* currentTrack;
	float speed = 100.0f;
	void Move();

public:
	float PositionOnTrack;

	locomotive(Track* track);
	void Update();
	void Draw();
};