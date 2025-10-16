#pragma once

#include <vector>
#include "track.h"
#include "railVehicle.h"

class TrackHandler
{
public:
	static std::vector<Track> Track;
	static std::vector<RailVehicle> ThingsOnTheTrack;
};