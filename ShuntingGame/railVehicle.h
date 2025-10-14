#pragma once

#include "track.h"

class RailVehicle
{
protected:
	sf::RectangleShape shape;

	Track* currentTrack = nullptr;
	void FollowTrack(float newPositionOnTrack);

public:
	float PositionOnTrack = 0.0f;

	virtual void Update() { }
	virtual void Draw();
};