#include "locomotive.h"

#include "utils.h"

locomotive::locomotive(Track *track)
{
	// Put us on the track
	currentTrack = track;
	PositionOnTrack = 0;

	// Make the actual loco
	shape = sf::RectangleShape(sf::Vector2f(25.0f, 8.0f));
	shape.setFillColor(sf::Color::Black);
}

void locomotive::Move()
{
	// Check what direction we wanna move
	float direction = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) direction += -1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) direction += 1.0f;
	if (direction == 0) return;

	// Get our new movement
	float newPositionOnTrack = PositionOnTrack + (speed * direction) * Utils::GetDeltaTime();

	// Check for if we're moving forwards onto the next bit of track
	if ((newPositionOnTrack >= currentTrack->Length) && (currentTrack->NextTrack != nullptr))
	{
		printf("moving to next track\n");

		// Move to the start of the next track
		currentTrack = currentTrack->NextTrack;
		newPositionOnTrack = 0.0f;
	}

	// Check for if we're moving backwards onto the previous bit of track
	if ((newPositionOnTrack < 0.0f) && (currentTrack->PreviousTrack != nullptr))
	{
		printf("moving to previous track\n");

		// Move to the end of the previous track
		currentTrack = currentTrack->PreviousTrack;
		newPositionOnTrack = currentTrack->Length;
	}

	// Update our position
	PositionOnTrack = newPositionOnTrack;
}

void locomotive::Update()
{
	Move();

	// Update the sprites position
	// TODO: Do in Move()
	shape.setPosition(currentTrack->Position + sf::Vector2f(PositionOnTrack, 0.0f));
}

void locomotive::Draw()
{
	Utils::GetWindow()->draw(shape);
}
