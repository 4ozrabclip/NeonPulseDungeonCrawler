#pragma once
#include "Character.h"
#include <memory>

class Sythe;
class Player : public Character
{
public:
	Player(int x, int y);
	virtual ~Player();

	virtual void Update(World* world, float fElapsedTime) override;
	virtual void Move(float fElapsedTime) override;

	virtual void SetXY(float InX, float InY) override;
	virtual olc::vi2d GetXY();

	virtual void SetMoveSpeed(int InMoveSpeed);
	virtual int GetMoveSpeed();
	void SetWeapon(bool HoldingWeapon);
	bool GetWeapon();

	bool GetHasKey();
	void SetHasKey(bool InbHasKey);

	bool GetAttacking();
	void SetAttacking(bool InIsAttacking);
	void TakeDamage();
	void YouDie();
	int SytheHealth;
	void SetHasSecretKey(bool InbHasSecretKey);
	bool GetHasSecretKey();

	bool FacingLeft;
protected:
	float fPlayer_ElapsedTime;
	MoveDirection Direction;
private:
	int Health;
	bool IsAttacking;
	bool bHasSecretKey;
	bool bHasKey;
	int MoveSpeed;
	bool HoldingWeapon;
	Player(const Player& other);
};