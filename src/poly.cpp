#include "poly.hpp"

using namespace Aeon::Renderer;

Polygon::Polygon()
{

}

Polygon::Polygon( std::vector<Segment> segments )
{
	for ( const auto& segment : segments )
		AddSide( segment );
}

int Polygon::NumSides()
{
	return mSides.size();
}

int Polygon::AddSide( Segment segment )
{
	mIterator++;
	mSides[mIterator] = segment;
}

void Polygon::RemoveSide( int segment )
{
	mSides.erase( segment );
}
