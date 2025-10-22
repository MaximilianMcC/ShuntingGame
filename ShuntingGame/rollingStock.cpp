#include "rollingStock.h"

RollingStock::RollingStock(Track *track)
{
	// Put us on the track
	CurrentTrack = track;
	PositionOnTrack = 0.0f;

	// Make the actual rolling stock
	// shape = sf::RectangleShape(sf::Vector2f(25.0f, 8.0f));
	// shape.setFillColor(sf::Color(0xFFFFB91DFF));
}