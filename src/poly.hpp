#pragma once

#include <unordered_map>

#include <glm/vec2.hpp>

namespace Aeon::Renderer
{

struct Segment
{
	glm::vec2 P1;
	glm::vec2 P2;
	// Perhaps material / surface properties?
};

// Does no checks to see if sides are touching / connecting
class Polygon
{
public:

	Polygon();
	Polygon(std::vector<Segment> segments);

	int NumSides();

	// Returns local ID for the segment
	int AddSide( Segment segment );
	// Remove by ID
	void RemoveSide( int segment );

private:
	std::unordered_map<int, Segment> mSides;

	int mIterator = 0;
};

};
