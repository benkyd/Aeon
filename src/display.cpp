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

		if ( mNextFrame == nullptr )
		{
			mNewFrame = false;
			return true;
		}

		for ( int x = 0; x < mNextFrame->w; x++ )
		for ( int y = 0; y < mNextFrame->w; y++ )
		{
			// tonemap, gamma correct and write
			// colours are assumed to input as HDR

			auto Clamp = []( glm::vec3 p, float max, float min ) -> glm::vec3
			{
				glm::vec3 ret;
				ret.r = std::max( min, std::min( p.r, max ) );
				ret.g = std::max( min, std::min( p.g, max ) );
				ret.b = std::max( min, std::min( p.b, max ) );
				return ret;
			};

			// Just clamping now
			glm::vec3 p = Clamp( mNextFrame->At( x, y ), 1.0f, 0.0f );

			// Gamma correction
			static const float Gamma = 1.0f / 2.2f;

			olc::Pixel pix(
				(uint8_t)( pow( p.r, Gamma ) * 255.0f ),
				(uint8_t)( pow( p.g, Gamma ) * 255.0f ),
				(uint8_t)( pow( p.b, Gamma ) * 255.0f ) );

			DrawRect( x, y, 1, 1, pix );
		}

		mNextFrame = nullptr;
		mNewFrame = false;
	}

	return true;
}
