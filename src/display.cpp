#include "display.hpp"

#include <memory>

Aeon::DisplayBuff::DisplayBuff( int wit, int hei )
	: data(nullptr)
	, w( wit ), h( hei )
{
	data = (glm::vec3*)malloc( sizeof(glm::vec3) * (w * h) );
}

void Aeon::DisplayBuff::Set( int x, int y, glm::vec3 v )
{
	data[y * w + x] = v;
}

glm::vec3 Aeon::DisplayBuff::At( int x, int y )
{
	return data[y * w + x];
}

Aeon::DisplayBuff::~DisplayBuff()
{
	free( data );
}


Aeon::Display::Display()
{

}

void Aeon::Display::Init( int x, int y )
{
	this->Construct( x, y, 1, 1 );
	mW = x; mH = y;
}

void Aeon::Display::Init( int x, int y, std::string title )
{
	sAppName = title;
	this->Construct( x, y, 1, 1 );
	mW = x; mH = y;
}

void Aeon::Display::SetTitle( std::string title )
{
	sAppName = title;
}

void Aeon::Display::NewFrame( DisplayBuff* buf )
{
	if ( buf->w != mW || buf->h != mH )
		return;
	mNextFrame = buf;
	mNewFrame = true;
}

bool Aeon::Display::OnUserCreate()
{
	return true;
}

bool Aeon::Display::OnUserUpdate( float fElapsedTime )
{
	// Check if theres a more recent framebuffer
	// then apply it

	if ( mNewFrame )
	{
		

		mNextFrame = nullptr;
		mNewFrame = false;
	}

	return true;
}
