#pragma once
#include <olcPixelGameEngine.h>

struct Particle
{
	int x = 0;
	int y = 0;
	int pState = 0;
	std::vector<Particle*> neigh;
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
	void update_particles();
	void draw_particles();
	void particleNeighbour();

	std::vector<Particle> particles;
};

