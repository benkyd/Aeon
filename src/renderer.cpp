#include "renderer.hpp"

#include "framebuffer.hpp"

#include <iostream>

Renderer::Renderer()
	: mFileReader() 
{
	
	// So DrawElements works, EBO can be lost as it should remain bound
	GLuint indices[] = {
		0, 1, 3, 1, 2, 3 
	};
	glGenBuffers( 1, &mEBO );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mEBO );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mEBO );

}

bool checkShader( GLuint uid ) {

	GLint status = GL_TRUE;

	glGetShaderiv( uid, GL_COMPILE_STATUS, &status );

	if ( status == GL_FALSE ) {
		char buf[512];
		glGetShaderInfoLog( uid, 512, NULL, buf );
		std::cout << "ERROR: " << buf << std::endl;
		// buf gets leaked here but it was crashing
		// the program so i removed the delete
		return false;
	}

	return true;
}	


void Renderer::LoadShader()
{

	std::string path = std::string( RESOURCES ) + "/2d";

	std::string vertexLocation = path + ".vert";
	mLoad( vertexLocation, GL_VERTEX_SHADER );
	std::cout << "Vertex shader at '" << vertexLocation << "' loaded..." << std::endl;

	std::string fragmentLocation = path + ".frag";
	mLoad( fragmentLocation, GL_FRAGMENT_SHADER );
	std::cout << "Fragment shader at '" << fragmentLocation << "' loaded..." << std::endl;

	if ( mVert == 0 || mFrag == 0 ) {
		std::cout << "Failed to link programs: Both programs not present" << std::endl;
		return;
	}

	glCompileShader( mVert );
	if ( checkShader( mVert ) ) {
		std::cout << "Vertex shader '" << mVert << "' compiled..." << std::endl;
	}

	glCompileShader( mFrag );
	if ( checkShader( mFrag ) ) {
		std::cout << "Fragment shader '" << mFrag << "' compiled..." << std::endl;
	}

	mShaderProgram = glCreateProgram();

	glAttachShader( mShaderProgram, mVert );
	glAttachShader( mShaderProgram, mFrag );

	glLinkProgram( mShaderProgram );

	glDeleteShader( mVert );
	glDeleteShader( mFrag );

	glUseProgram( mShaderProgram );

}

void Renderer::mLoad( std::string path, GLenum type )
{
	GLuint activeShader = 0;

	if ( type == GL_VERTEX_SHADER )
		mVert = activeShader = glCreateShader( type );

	if ( type == GL_FRAGMENT_SHADER )
		mFrag = activeShader = glCreateShader( type );

	std::string loadedShaderSource = mFileReader.LoadTextFromFile( path );
	const char* shaderSource = loadedShaderSource.c_str();
	GLint shaderSourceLength = loadedShaderSource.length();

	glShaderSource( activeShader, 1, &shaderSource, &shaderSourceLength );
}

int8_t Renderer::RegisterBuffer( FrameBuffer* buffer, int layer )
{
	if ( buffer == nullptr )
		return -1;

	// Load buffer as a texture into OpenGL
	GLuint texture;
	glGenTextures( 1, &texture );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, buffer->GetWidth(), buffer->GetHeight(), 0, GL_RGB, GL_RGBA32UI, buffer->Data );

	
	FrameBufferRenderable fb =
	{
			buffer,
			texture,
			layer,
		{
			// positions          // texture coords
			 1.0f,  1.0f, 0.0f,   1.0f, 1.0f,   // top right
			 1.0f, -1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			-1.0f, -1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
			-1.0f,  1.0f, 0.0f,   0.0f, 1.0f    // top left 
		}
	};

	glGenVertexArrays( 1, &fb.VAO );
	glBindVertexArray( fb.VAO );

	glGenBuffers( 1, &fb.VBO );
	glBindBuffer( GL_ARRAY_BUFFER, fb.VBO );

	glBufferData( GL_ARRAY_BUFFER, 20 * sizeof( float ), &fb.QuadVerts, GL_STATIC_DRAW );

	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof( float ), (void*)( 0 * sizeof( float ) ) );

	glEnableVertexAttribArray( 1 );
	glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof( float ), (void*)( 3 * sizeof( float ) ) );

	glBindVertexArray( 0 );

	mRenderQueue.push_back( fb );

	return mRenderQueue.size();
}

FrameBuffer* Renderer::GetBuffer( int8_t id )
{
	return mRenderQueue[id].Buffer;
}

void Renderer::UpdateBuffer( int8_t id )
{
	if ( id > mRenderQueue.size() )
		return;

	FrameBuffer* buffer = mRenderQueue[id].Buffer;
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, buffer->GetWidth(), buffer->GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, buffer->Data );
}

void Renderer::Render()
{
	glUseProgram( mShaderProgram );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mEBO );

	for ( size_t i = 0; i < mRenderQueue.size(); i++ )
	{
		FrameBufferRenderable* fb = &mRenderQueue[i];
		glBindTexture( GL_TEXTURE_2D, fb->TextureID );
		glBindVertexArray( fb->VAO );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
	}
}

Renderer::~Renderer()
{
	glDeleteProgram( mShaderProgram );
	glDeleteShader( mVert );
	glDeleteShader( mFrag );
}
