#pragma once

#include <glad/glad.h>
#include <vector>

#include "util/filereader.hpp"

class FrameBuffer;

// 3 * 4 each corner vert
// 2 * 4 each corner text
#define FRAMEBUFFER_VERTS 20

struct FrameBufferRenderable
{
	FrameBuffer* Buffer;
	GLuint TextureID;
	int Layer;
	float QuadVerts[20];
	GLuint VAO; GLuint VBO;
};

class Renderer
{
public:
	Renderer();

	void LoadShader();

	// Callee retains ownership of framebuffer
	// Returns buffer ID
	int8_t RegisterBuffer( FrameBuffer* buffer, int layer );

	FrameBuffer* GetBuffer( int8_t ID );

	// Re-uploads buffer to GPU
	void UpdateBuffer( int8_t ID );

	void Render();

	~Renderer();

private:

	// On insertion is sorted by layer
	// TODO: Render by layers
	// reverse referenced lists might be useful
	// to retain ID but update render queues position
	std::vector<FrameBufferRenderable> mRenderQueue;

	FileReader mFileReader;

	// GL Shaders
	void mLoad( std::string path, GLenum type );
	// Used once, are invalid after LoadShader call
	GLuint mVert, mFrag;
	GLuint mShaderProgram;
	GLuint mEBO;

};
