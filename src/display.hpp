#pragma once

#include <olcPixelGameEngine.hpp>

#include <string>
#include <mutex>

#include <glm/vec3.hpp>

namespace Aeon
{

struct DisplayBuff
{
	DisplayBuff( int w, int h );
	glm::vec3* data;
	int w, h;
	void Set( int x, int y, glm::vec3 v );
	glm::vec3 At( int x, int y );
	~DisplayBuff();
};

// Can be replaced with literally anything
// for the time being NEEDS to run on main thread
class Display : public olc::PixelGameEngine
{
public:
	Display();
	void Init( int x, int y );
	void Init( int x, int y, std::string title );

	void SetTitle( std::string title );

	void NewFrame( DisplayBuff* buf );

private:
	// Cleared every swap
	std::mutex mFrameMutex;
	DisplayBuff* mNextFrame = nullptr;
	bool mNewFrame = false;


	int mW, mH;

protected:
	bool OnUserCreate() override;
	bool OnUserUpdate( float fElapsedTime ) override;

};

}
