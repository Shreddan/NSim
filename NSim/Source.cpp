#define OLC_PGE_APPLICATION
#include "Engine.h"

int main()
{
    Engine eng;
    if (eng.Construct(400, 300, 3, 3))
    {
        eng.Start();
    }
    return 0;
}


