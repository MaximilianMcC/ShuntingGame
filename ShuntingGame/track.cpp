#include "track.h"

#include <sstream>
#include "utils.h"
#include "assetManager.h"

Track::Track(float length, sf::Vector2f position)
{
	// Set its length
	// TODO: Make this based on texture/type or something
	Length = length;

	// Make the rectangle
	// TODO: Use textures
	shape = sf::RectangleShape(sf::Vector2f(Length, 10.0f));
	shape.setFillColor(Utils::GetRandomColor());

	// Make the debug text
	{
		// Get the pointer as a string
		std::stringstream stream;
		stream << this;
		std::string address = stream.str();

		// Make the actual text
		debugText = new sf::Text(*AssetManager::GetFont("debug"), address, 16u);
	}

	// Set the position if we supplied one
	SetPosition(position);
}

sf::Vector2f Track::GetEndPosition()
{
	return Position + sf::Vector2f(Length, 0.0f);
}

void Track::SetPosition(sf::Vector2f newPosition)
{
	Position = newPosition;

	shape.setPosition(Position);
	debugText->setPosition(Position);
}

void Track::Draw()
{
	Utils::GetWindow()->draw(shape);

	Utils::GetWindow()->draw(*debugText);
}