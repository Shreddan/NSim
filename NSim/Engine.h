#pragma once
#include <olcPixelGameEngine.h>

enum State
{
	Empty = 0,
	Wood = 1,
	Sand = 2,
	Water = 3,
	Acid = 4,
	AcidVapour = 5
};

struct Particle
{
	Particle() { this->pState = Wood; };
	Particle(int x, int y, int pState) { this->x = x, this->y = y, this->pState = pState; }
	int x = 0;
	int y = 0;
	int pState = 0;
	bool movedRight = false;
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
	std::vector<Particle> particles2;
};

