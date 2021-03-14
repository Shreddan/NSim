#include "Engine.h"

Engine::Engine()
{
	sAppName = "Falling Sand Simulation";
}

bool Engine::OnUserCreate()
{
	srand(time(NULL));
	for (int x = 0; x < ScreenWidth(); x++)
	{
		for (int y = 0; y < ScreenHeight(); y++)
		{
			Particle p;
			p.x = x;
			p.y = y;
			p.pState = Empty;
			particles.push_back(p);
		}
	}
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);

	if (GetMouse(0).bPressed)
	{
		set_Particle(GetMouseX(), GetMouseY(), Sand);
	}
	update_particles(fElapsedTime);
	draw_particles();
	return true;
}

void Engine::update_particles(float fElapsedTime)
{
	/*int dir = 0;
	ran = rand()% 1;
	if (ran == 0)
	{
		dir = -1;
	}
	else
	{
		dir = 1;
	}*/

	for (int x = 0; x < ScreenWidth(); x++)
	{
		for (int y = ScreenHeight() - 1; y > 0; y--)
		{
			if (get_Particle(x, y).pState == Sand)
			{
				if (get_Particle(x, y + 1).pState == Empty && get_Particle(x, y + 1).y < ScreenHeight() - 1)
				{
					set_Particle(x, y, Empty);
					set_Particle(x, y + 1, Sand);
				}
				/*else if (get_Particle(x + dir, y + 1).pState == Empty)  
				{
					set_Particle(x, y, Empty); 
					set_Particle(x + dir, y + 1, Sand); 
				}*/
			}
		}
	}
}

void Engine::set_Particle(int x, int y, int pState)
{
	particles[y * ScreenWidth() + x].pState = pState;
}

void Engine::draw_particles()
{
	for (size_t i = 0; i < particles.size(); i++)
	{
		switch (particles[i].pState)
		{
			case Empty:
			{
				break;
			}
			case Sand:
			{
				Draw(olc::vi2d(particles[i].x, particles[i].y), olc::YELLOW);
				break;
			}
			case Water:
			{
				Draw(olc::vi2d(particles[i].x, particles[i].y), olc::BLUE);
				break;
			}
		}
	}
}

Particle Engine::get_Particle(int x, int y)
{
	if (x < 0 || x >= ScreenWidth() || y < 0 || y >= ScreenHeight())
	{
		return Particle();
	}
	else
	{
		return particles[x + y * ScreenWidth()];
	}
}


