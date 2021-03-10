#include "Engine.h"

Engine::Engine()
{
	sAppName = "Falling Sand Simulation";
}

bool Engine::OnUserCreate()
{
	for (size_t x = 0; x < ScreenWidth(); x++)
	{
		for (size_t y = 0; y < ScreenHeight(); y++)
		{
			Particle p;
			p.x = x;
			p.y = y;
			p.pState = 0;
			particles.push_back(p);
		}
	}

	particleNeighbour();
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);

	

	if (GetMouse(0).bHeld)
	{
		particles[];
	}

	draw_particles();

	update_particles();
	
	return true;
}

void Engine::update_particles()
{
	for (size_t i = 0; i < particles.size(); i++)
	{
		if (particles[i].neigh[1]->pState == 0)
		{
			particles[i].neigh[1]->pState = particles[i].pState;
			particles[i].pState = 0;
		}
		if (particles[i].neigh[5]->pState == 0 && particles[i].neigh[1]->pState == 1)
		{
			particles[i].neigh[5]->pState = particles[i].pState;
			particles[i].pState = 0;
		}
	}
}

void Engine::draw_particles()
{
	for (size_t i = 0; i < particles.size(); i++)
	{
		switch (particles[i].pState)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			Draw(olc::vi2d(particles[i].x, particles[i].y), olc::YELLOW);
			break;
		}
		}
	}
}

void Engine::particleNeighbour()
{
	for (int x = 0; x < ScreenWidth(); x++)
	{
		for (int y = 0; y < ScreenHeight(); y++)
		{
			if (y > 0)
			{
				particles[y * ScreenWidth() + x].neigh.push_back(&particles[(y - 1) * ScreenWidth() + (x + 0)]);
			}
			if (y < ScreenHeight() - 1)
			{
				particles[y * ScreenWidth() + x].neigh.push_back(&particles[(y + 1) * ScreenWidth() + (x + 0)]);
			}
			if (x > 0)
			{
				particles[y * ScreenWidth() + x].neigh.push_back(&particles[(y + 0) * ScreenWidth() + (x - 1)]);
			}
			if (x < ScreenWidth() - 1)
			{
				particles[y * ScreenWidth() + x].neigh.push_back(&particles[(y + 0) * ScreenWidth() + (x + 1)]);
			}
			if (y > 0 && x > 0)
			{
				particles[y * ScreenWidth() + x].neigh.push_back(&particles[(y - 1) * ScreenWidth() + (x - 1)]);
			}
			if (y < ScreenHeight() && x > 0)
			{
				particles[y * ScreenWidth() + x].neigh.push_back(&particles[(y + 1) * ScreenWidth() + (x - 1)]);
			}
			if (y > 0 && x < ScreenWidth() - 1)
			{
				particles[y * ScreenWidth() + x].neigh.push_back(&particles[(y - 1) * ScreenWidth() + (x + 1)]);
			}
			if (y < ScreenHeight() - 1 && x < ScreenWidth() - 1)
			{
				particles[y * ScreenWidth() + x].neigh.push_back(&particles[(y + 1) * ScreenWidth() + (x + 1)]);
			}
		}
	}
}
