#pragma once
#include "IScene.h"
#include"Struct.h"

class Clear :public IScene 
{
public:
	Clear();

	void Init() override;
	void Update() override;
	void Draw() override;

private:

};