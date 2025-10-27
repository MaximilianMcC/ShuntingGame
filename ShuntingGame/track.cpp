#include "track.h"

#include <sstream>
#include "utils.h"
#include "assetManager.h"

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

	// Make the debug text
	{
		// Get the pointer as a string
		std::stringstream stream;
		stream << this;
		std::string address = stream.str();

		// Make the actual text
		debugText = new sf::Text(*AssetManager::GetFont("debug"), address, 16u);
		debugText->setPosition(Position);
	}
}

void Track::Draw()
{
	Utils::GetWindow()->draw(shape);

	Utils::GetWindow()->draw(*debugText);
}