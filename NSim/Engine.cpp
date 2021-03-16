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

	for (int x = 0; x < ScreenWidth(); x++)
	{
		for (int y = 0; y < ScreenHeight(); y++)
		{
			Particle p;
			p.x = x;
			p.y = y;
			p.pState = Empty;
			particles2.push_back(p);
		}
	}
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);

	particles = particles2;

	if (GetMouse(0).bHeld)
	{
		if (GetKey(olc::SHIFT).bHeld)
		{
			set_Particle(GetMouseX(), GetMouseY(), Water);
			set_Particle(GetMouseX() + 1, GetMouseY(), Water);
		}
		else if (GetKey(olc::CTRL).bHeld)
		{
			set_Particle(GetMouseX(), GetMouseY(), Acid);
			set_Particle(GetMouseX() + 1, GetMouseY(), Acid);
		}
		else
		{
			set_Particle(GetMouseX(), GetMouseY(), Sand);
			set_Particle(GetMouseX() + 1, GetMouseY(), Sand);
		}
		
	}
	update_particles(fElapsedTime);
	draw_particles();
	return true;
}

void Engine::update_particles(float fElapsedTime)
{
	for (int x = 0; x < ScreenWidth(); x++)
	{
		for (int y = ScreenHeight() - 1; y > 0; y--)
		{
			int dir = (rand() % 2) * 2 - 1;

			if (get_Particle(x, y).pState == Sand)
			{
				if (get_Particle(x, y + 1).pState == Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x, y + 1, Sand);
				}
				else if (get_Particle(x + dir, y + 1).pState == Empty)  
				{
					set_Particle(x, y, Empty); 
					set_Particle(x + dir, y + 1, Sand); 
				}
				else if (get_Particle(x, y + 1).pState == Water)
				{
					set_Particle(x, y, Water);
					set_Particle(x, y + 1, Sand);
				}
				else if (get_Particle(x, y + 1).pState == Wood)
				{
					set_Particle(x, y, Sand);
				}
			}
			else if (get_Particle(x, y).pState == Water)
			{
				if (get_Particle(x, y + 1).pState == Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x, y + 1, Water);
				}
				else if (get_Particle(x + dir, y + 1).pState == Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x + dir, y + 1, Water);
				}
				else if (get_Particle(x + dir, y).pState == Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x + dir, y, Water);
				}
				else if (get_Particle(x, y + 1).pState == Wood)
				{
					set_Particle(x, y, Water);
				}
			}
			else if (get_Particle(x, y).pState == Acid)
			{
				if (get_Particle(x, y + 1).pState == Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x, y + 1, Acid);
				}
				else if (get_Particle(x + dir, y + 1).pState == Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x + dir, y + 1, Acid);
				}
				else if (get_Particle(x, y + 1).pState != Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x, y + 1, AcidVapour);
				}
				else if (get_Particle(x + dir, y + 1).pState != Empty && get_Particle(x + dir, y + 1).pState != Acid)
				{
					set_Particle(x, y, Empty);
					set_Particle(x + dir, y + 1, AcidVapour);
				}
			}
			else if (get_Particle(x, y).pState == AcidVapour)
			{
				if (get_Particle(x, y - 1).pState == Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x, y - 1, AcidVapour);
				}
				else if (get_Particle(x + dir, y - 1).pState == Empty)
				{
					set_Particle(x, y, Empty);
					set_Particle(x + dir, y - 1, AcidVapour);
				}
			}
		}
	}
}

void Engine::set_Particle(int x, int y, int pState)
{
	particles2[y + x * ScreenHeight()].pState = pState;
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
			case Acid:
			{
				Draw(olc::vi2d(particles[i].x, particles[i].y), olc::GREEN);
				break;
			}
			case AcidVapour:
			{
				Draw(olc::vi2d(particles[i].x, particles[i].y), olc::DARK_GREEN);
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
		return particles[y + x * ScreenHeight()];
	}
}


