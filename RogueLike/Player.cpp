#include "Player.h"
#include "World.h"
#include "Enemy.h"
#include <iostream>
#include <random>
#include "Sythe.h"

Player::Player(int x, int y)
{
    this->Pos.coords.x = x;
    this->Pos.coords.y = y;
    Tileset = World::Instance->Tileset;
    AnimSeq.WhichSprite = Actor::SpritePosition(RABCLIP);
    AnimSeq.NumberOfFrames = 4;
    AnimSeq.SpriteSize = World::Instance->TileSize;
    MoveSpeed = 100;
    
    AnimSeq.AnimationDuration = 1.f;

    AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
    FacingLeft = false;
    HoldingWeapon = false;
     
    Health = 100000;

    SytheHealth = 100;
}
Player::~Player()
{
}

void Player::Update(World* World, float fElapsedTime)
{
    Move(fElapsedTime);
    Draw(World, fElapsedTime);
    BorderStopper({ 228-10,228-10 }, { 10, 10 });
    std::cout << "Sythe Health: " << SytheHealth << std::endl;
    if (HoldingWeapon)
    {
        AnimSeq.WhichSprite = Actor::SpritePosition(RABCLIP_SWORD);
    }
    else {
        AnimSeq.WhichSprite = Actor::SpritePosition(RABCLIP);
    }
    if (IsAttacking)
    {
        SytheHealth--;
    }
    if (SytheHealth <= 0)
    {
        HoldingWeapon = false;
        SytheHealth = 100;
    }
}

void Player::Move(float fElapsedTime)
{
    float x = 0, y = 0;

    if (World::Instance->GetKey(olc::Key::LEFT).bPressed ||
        World::Instance->GetKey(olc::Key::RIGHT).bPressed ||
        World::Instance->GetKey(olc::Key::UP).bPressed ||
        World::Instance->GetKey(olc::Key::DOWN).bPressed)
    {
        AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::LOOP_FOREVER, AnimSeq);
    }
    if (World::Instance->GetKey(olc::Key::LEFT).bHeld)
    {
        SetDirection(LEFT);
        FacingLeft = true;
        Pos.coords.x -= MoveSpeed * fElapsedTime;
    }
    else if (World::Instance->GetKey(olc::Key::RIGHT).bHeld)
    {
        SetDirection(RIGHT);
        FacingLeft = false;
        Pos.coords.x += MoveSpeed * fElapsedTime;
    }
    if (World::Instance->GetKey(olc::Key::UP).bHeld)
    {
        SetDirection(UP);
        Pos.coords.y -= MoveSpeed * fElapsedTime;
    }
    else if (World::Instance->GetKey(olc::Key::DOWN).bHeld)
    {
        SetDirection(DOWN);
        Pos.coords.y += MoveSpeed * fElapsedTime;
    }
    //SetXY(x, y);
    if (World::Instance->GetKey(olc::Key::LEFT).bReleased ||
        World::Instance->GetKey(olc::Key::RIGHT).bReleased ||
        World::Instance->GetKey(olc::Key::UP).bReleased ||
        World::Instance->GetKey(olc::Key::DOWN).bReleased)
    {
        AnimatedSpritePtr = std::make_shared<AnimatedSprite>(Tileset, EAnimationType::STILL, AnimSeq);
    }
}

void Player::SetXY(float InX, float InY)
{
    Pos.coords.x += InX;
    Pos.coords.y += InY;
}

olc::vi2d Player::GetXY()
{
    return olc::vi2d(Pos.coords.x, Pos.coords.y);
}

void Player::SetMoveSpeed(int InMoveSpeed)
{
    MoveSpeed = InMoveSpeed;
}

int Player::GetMoveSpeed()
{
    return MoveSpeed;
}

void Player::SetWeapon(bool bHoldingWeapon)
{
    HoldingWeapon = bHoldingWeapon;
}

bool Player::GetWeapon()
{
    return HoldingWeapon;
}

bool Player::GetHasKey()
{
    return bHasKey;
}

void Player::SetHasKey(bool InbHasKey)
{
    bHasKey = InbHasKey;
}

bool Player::GetAttacking()
{
    return IsAttacking;
}

void Player::SetAttacking(bool InIsAttacking)
{
    IsAttacking = InIsAttacking;
}

void Player::TakeDamage()
{
    if (Health > 0)
    {
        Health--;
        World::Instance->DrawRect(olc::vf2d(Pos.coords.x, Pos.coords.y), AnimSeq.SpriteSize, olc::RED);
    }
    else 
    {
        YouDie();
    }
    Health--;
}

void Player::YouDie()
{
    World::Instance->LevelSwitch(true, 7);
}

void Player::SetHasSecretKey(bool InbHasSecretKey)
{
    bHasSecretKey = InbHasSecretKey;
}

bool Player::GetHasSecretKey()
{
    return bHasSecretKey;
}
