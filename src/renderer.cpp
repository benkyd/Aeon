#include "renderer.hpp"

#include <iostream>

Renderer::Renderer()
	: mFileReader() 
{

}

bool checkShader( GLuint uid ) {

	GLint status = GL_TRUE;

	glGetShaderiv( uid, GL_COMPILE_STATUS, &status );

	if ( status == GL_FALSE ) {
		char buf[512];
		glGetShaderInfoLog( uid, 512, NULL, buf );
		std::cout << "ERROR: " << buf << std::endl;
		delete buf;
		return false;
	}

	return true;
}


void Renderer::LoadShader()
{

	std::string path = std::string( RESOURCES ) + "/2d";

	GLuint vert, frag;

	auto Load = [&]( std::string path, GLenum type )
	{
		GLuint activeShader = 0;

		if ( type == GL_VERTEX_SHADER )
			vert = activeShader = glCreateShader( type );

		if ( type == GL_FRAGMENT_SHADER )
			frag = activeShader = glCreateShader( type );

		std::string loadedShaderSource = mFileReader.LoadTextFromFile( path );
		const char* shaderSource = loadedShaderSource.c_str();
		int shaderSourceLength = loadedShaderSource.length();

		glShaderSource( activeShader, 1, &shaderSource, &shaderSourceLength );
	};

	std::string vertexLocation = path + ".vert";
	Load( vertexLocation, GL_VERTEX_SHADER );
	std::cout << "Vertex shader at '" << vertexLocation << "' loaded..." << std::endl;


	std::string fragmentLocation = path + ".frag";
	Load( fragmentLocation, GL_FRAGMENT_SHADER );
	std::cout << "Fragment shader at '" << fragmentLocation << "' loaded..." << std::endl;


	if ( vert == 0 || frag == 0 ) {
		std::cout << "Failed to link programs: Both programs not present" << std::endl;
		return;
	}

	glCompileShader( vert );
	if ( checkShader( vert ) ) {
		std::cout << "Vertex shader '" << vert << "' compiled..." << std::endl;
	}

	glCompileShader( frag );
	if ( checkShader( frag ) ) {
		std::cout << "Fragment shader '" << frag << "' compiled..." << std::endl;
	}

	mShaderProgram = glCreateProgram();

	glAttachShader( mShaderProgram, vert );
	glAttachShader( mShaderProgram, frag );

	glLinkProgram( mShaderProgram );

	glDeleteShader( vert );
	glDeleteShader( frag );

	glUseProgram( mShaderProgram );

}
