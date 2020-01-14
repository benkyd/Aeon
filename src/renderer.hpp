#pragma once

#include <glad/glad.h>
#include <vector>

#include "util/filereader.hpp"

class FrameBuffer;

struct FrameBufferRenderable
{
	FrameBuffer* Buffer;
	GLuint TextureID;
	int Layer;
};

class Renderer
{
public:
	Renderer();

	void LoadShader();

	void RegisterBuffer( FrameBuffer* buffer, int layer );


private:

	FileReader mFileReader;

	GLuint mShaderProgram;

};
