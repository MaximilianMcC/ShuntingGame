#pragma once

#include "track.h"

class RailVehicle
{
protected:
	sf::RectangleShape* shape;

	void FollowTrack(float newPositionOnTrack);
	
public:

	Track* CurrentTrack = nullptr;
	float PositionOnTrack = 0.0f;

	virtual void Update() { }
	virtual void Draw();

	virtual ~RailVehicle() { }
};