#pragma once
#include "IScene.h"
#include"Struct.h"
#include <Novice.h>

class Title:public IScene
{
public:
	Title();


	void Init() override;
	void Update() override;
	void Draw() override;

private:

};