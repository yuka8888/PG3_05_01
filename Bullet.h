#pragma once
#include "Struct.h"
#include <Novice.h>

class Bullet
{

public:
	Bullet();

	void Update();

	void Draw();

	void SetIsShot(bool isShot) { isShot_ = isShot; }
	void SetBullet(Vector2 bullet) { bullet_.position = bullet; }
	Transform GetBullet() { return bullet_; }
	bool GetIsShot() { return isShot_; }

private:
	Transform bullet_;

	bool isShot_;
};