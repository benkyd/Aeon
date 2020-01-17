#include "framebuffer.hpp"

#include <memory>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "thirdparty/stb_image_write.h"

FrameBuffer::FrameBuffer( int width, int height )
	: mWidth(width)
	, mHeight(height) 
{

	size_t size = sizeof( uint32_t ) * mWidth * mHeight;

	Data = (uint32_t*)malloc( size );

	// Initialise the framebuffer
	if ( Data != nullptr )
		memset( Data, 0xFFFFFFFF, size );
}

void FrameBuffer::SetPixel( int x, int y, glm::vec3 p )
{
	int i = y * mWidth + x;
	const static float gamma = 1.0f / 2.2f;
	uint8_t r = (uint8_t)( pow( p.r, gamma ) * 255.0f );
	uint8_t g = (uint8_t)( pow( p.g, gamma ) * 255.0f );
	uint8_t b = (uint8_t)( pow( p.b, gamma ) * 255.0f );
	uint32_t col = r << 24 | g << 16 | b << 8 | 0xFF;
	Data[i] = col;
}

void FrameBuffer::Resize( int width, int height )
{
	mWidth = width; mHeight = height;

	size_t size = sizeof( uint32_t ) * mWidth * mHeight;

	realloc( Data, size );
	memset( Data, 0xFFFFFFFF, size );
}

void FrameBuffer::DumpToFile( std::string file )
{
	// int stbi_write_png(char const* filename, int w, int h, int comp, const void* data, int stride_in_bytes);
	struct P {
		unsigned char r, g, b, a;
	};

	P* imageData = (P*)malloc( ( (int)mWidth * (int)mHeight ) * sizeof( P ) );

	for ( int x = 0; x < mWidth; x++ )
		for ( int y = 0; y < mHeight; y++ ) {
			// Red and Blue channels need to be swapped, no clue why
			// saving the framebuffer just doesnt work
			uint32_t pixel = Data[y * mWidth + x];
			uint8_t er = ( pixel & 0x000000FF );
			uint8_t eg = ( pixel & 0x0000FF00 ) >> 8;
			uint8_t eb = ( pixel & 0x00FF0000 ) >> 16;
			uint8_t ea = ( pixel & 0xFF000000 ) >> 24;

			imageData[y * mWidth + x] = P{ (unsigned char)eb, (unsigned char)eg, (unsigned char)er, (unsigned char)ea };
		}

	stbi_write_png( file.c_str(), mWidth, mHeight, sizeof( P ), imageData, sizeof( P ) * mWidth );
	free( imageData );
}

int FrameBuffer::GetWidth()
{
	return mWidth;
}

int FrameBuffer::GetHeight()
{
	return mHeight;
}

FrameBuffer::~FrameBuffer()
{
	free( Data );
}
