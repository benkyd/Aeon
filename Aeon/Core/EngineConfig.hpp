#ifndef AEON_CORE_ENGINECONFIG_H_
#define AEON_CORE_ENGINECONFIG_H_

namespace Aeon::Core
{

// TODO: this
struct AppProperties
{
	std::string Name;
};

struct DisplayProperties
{
	std::string Name;
	int Width, Height;
	bool VSync;

	DisplayProperties( std::string name, int width = 1200, int height = 900, bool vSync = true )
		: Name( name ),
		Width( width ),
		Height( height ),
		VSync( vSync ) { }
};

}

#endif
