#include "Actor.h"
#include "World.h"

void Actor::Tick()
{
}

olc::vi2d Actor::SpritePosition(InitialSprite sprite) const
{
    switch (sprite)
    {
    case BORDER:
        return olc::vi2d(0, 0) 
            * World::Instance->TileSize;
    case BRICKS:
        return olc::vi2d(0, 5) 
            * World::Instance->TileSize;
    case DOOR:
        return olc::vi2d(0, 1) 
            * World::Instance->TileSize;
    case RABCLIP:
        return olc::vi2d(16, 2) 
            * World::Instance->TileSize;
    case FERG:
        return olc::vi2d(2, 16) 
            * World::Instance->TileSize;
    case WOOD:
        return olc::vi2d(0, 3)
            * World::Instance->TileSize;
    case ALIEN:
        return olc::vi2d(12, 2)
            * World::Instance->TileSize;
    case SPEAKER:
        return olc::vi2d(0, 8)
            * World::Instance->TileSize;
    default:
        return olc::vi2d(-1, -1); 
    }
}