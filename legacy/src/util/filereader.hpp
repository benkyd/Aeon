#pragma once

#include <string>

class FileReader 
{
public:
	FileReader();

	std::string LoadTextFromFile( std::string path );

};
