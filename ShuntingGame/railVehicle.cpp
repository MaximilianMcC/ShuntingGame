#include "railVehicle.h"

#include "utils.h"

void RailVehicle::FollowTrack(float newPositionOnTrack)
{
	// Check for if we're moving forwards onto the next bit of track
	if ((newPositionOnTrack >= currentTrack->Length) && (currentTrack->NextTrack != nullptr))
	{
		// Move to the start of the next track
		currentTrack = currentTrack->NextTrack;
		newPositionOnTrack = 0.0f;

		// TODO: Play fishplate sound effect
	}

	// Check for if we're moving backwards onto the previous bit of track
	if ((newPositionOnTrack < 0.0f) && (currentTrack->PreviousTrack != nullptr))
	{;
		// Move to the end of the previous track
		currentTrack = currentTrack->PreviousTrack;
		newPositionOnTrack = currentTrack->Length;
		
		// TODO: Play fishplate sound effect
	}

	// Update our position
	PositionOnTrack = newPositionOnTrack;
}

void RailVehicle::Draw()
{
	shape.setPosition(currentTrack->Position + sf::Vector2f(PositionOnTrack, 0.0f));
	Utils::GetWindow()->draw(shape);
}