#pragma once

#include <vector>
#include "track.h"
#include "railVehicle.h"

class TrackHandler
{
public:
	static std::vector<Track*> Railway;
	static std::vector<RailVehicle*> ThingsOnTheTrack;

	static void Add(Track* trackToAdd);
	static void RemoveAll();

	static void Update();

	static void DrawAllTrack();
	static void DrawAllVehicles();
};