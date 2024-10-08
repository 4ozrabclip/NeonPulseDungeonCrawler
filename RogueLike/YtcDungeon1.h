#pragma once
#include "Map.h"
#include "Actor.h"
#include <memory>

class Pill;
class Door;
class Wood;
class Enemy;

class YtcDungeon1 : public Map
{
public:
	YtcDungeon1();
	virtual void DrawRoom(World* world) override;
	virtual void SetMap(int map[]);
	virtual void InitDungeon(World* world) override;

	void DungeonUpdate(World* world);

	bool bSecretKeyGiven;

private:
	int yurp;
	Actor** YtcDungeon1Actors = new Actor * [22];

};