#include "Engine.h"

Engine::Engine()
{
	sAppName = "Falling Sand Simulation";
}

bool Engine::OnUserCreate()
{
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);

	//std::cout << particles.size() << std::endl;

	if (GetMouse(0).bHeld)
	{
		Particle p;
		p.x = GetMouseX();
		p.y = GetMouseY();
		particles.push_back(p);
	}

	if (particles.size() > 0)
	{
		for (size_t i = 0; i < particles.size(); i++)
		{
			//std::cout << particles[i].x << "  " << particles[i].y << std::endl;
			Draw(olc::vi2d(particles[i].x, particles[i].y), olc::DARK_YELLOW);
		}
	}

	if (particles.size() > 0)
	{
		update_particles();
	}


	return true;
}

void Engine::update_particles()
{
	for (size_t i = 0; i < particles.size(); i++)
	{
		if (particles[i].y <= ScreenHeight())
		{
			particles[i].y++;
		}
		else
		{
			particles[i].y = ScreenHeight() - 1;
		}
	}
}

void Engine::particle_order()
{
	std::sort(particles.begin(), particles.end(), [](Particle x, Particle y) {return x.x < y.x; });
}

void Engine::particleneighbours()
{
	for (size_t i = 0; i < particles.size(); i++)
	{
		//if (particles[i].y
	}
}
