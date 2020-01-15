#include "filereader.hpp"

#include <iostream>
#include <fstream>

FileReader::FileReader()
{

}

std::string FileReader::LoadTextFromFile( std::string path ) 
{
	std::ifstream t( path );
	std::string text( ( std::istreambuf_iterator<char>( t ) ),
		std::istreambuf_iterator<char>() );
	text += "\0";
	return text;
}
