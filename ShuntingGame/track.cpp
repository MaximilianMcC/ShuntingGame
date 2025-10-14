#include "track.h"

#include "utils.h"

Track::Track(sf::Vector2f position, float length)
{
	// Assign stuff
	Position = position;
	Length = length;

	// TODO: Use the position of the previous bit of track

	// Make the rectangle
	// TODO: Use textures
	shape = sf::RectangleShape(sf::Vector2f(Length, 10.0f));
	shape.setPosition(Position);
	shape.setFillColor(Utils::GetRandomColor());
	shape.setOutlineColor(Utils::GetRandomColor());
}

void Track::Draw()
{
	Utils::GetWindow()->draw(shape);
}