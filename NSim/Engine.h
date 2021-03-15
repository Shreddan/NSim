#pragma once
#include <olcPixelGameEngine.h>

enum State
{
	Empty = 0,
	Sand = 1,
	Water = 2

};

struct Particle
{
	Particle() { this->pState = Sand; };
	Particle(int x, int y, int pState) { this->x = x, this->y = y, this->pState = pState; }
	int x = 0;
	int y = 0;
	int pState = 0;
};

class Engine :  public olc::PixelGameEngine
{
public:
	Engine();
	~Engine() { OnUserDestroy(); }

protected:
	bool OnUserCreate();
	bool OnUserUpdate(float fElapsedTime);


public:
	void update_particles(float fElapsedTime);
	void set_Particle(int x, int y, int pState);
	void draw_particles();
	Particle get_Particle(int x, int y);

	std::vector<Particle> particles;
	int ran = 0;
};

