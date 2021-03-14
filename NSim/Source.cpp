#define OLC_PGE_APPLICATION
#include "Engine.h"

int main()
{
    Engine eng;
    if (eng.Construct(400, 300, 1, 1))
    {
        eng.Start();
    }
    return 0;
}


