#pragma once

#include <SFML/Graphics.hpp>
class Track;

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