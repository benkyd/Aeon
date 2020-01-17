#pragma once

#include <string>
#include <glm/glm.hpp>

class FrameBuffer
{
public:

	FrameBuffer( int width, int height );

	void SetPixel( int x, int y, glm::vec3 col );

	// Will clear the framebuffers current state
	void Resize( int width, int height );

	void DumpToFile( std::string file );

	int GetWidth();
	int GetHeight();

	uint32_t* Data;

	~FrameBuffer();

private:

	int mWidth, mHeight;

};
