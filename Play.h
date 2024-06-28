#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Function.h"
#include<Novice.h>

class Play:public IScene
{
public:
	Play();

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Player* player_;

	Enemy* enemy_;

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};