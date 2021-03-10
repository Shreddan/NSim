#pragma once
#include <olcPixelGameEngine.h>

struct Particle
{
	int x = 0;
	int y = 0;
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

	void particle_order();

	void particleneighbours();

	std::vector<Particle> particles;
};

