﻿#pragma once

#include <memory>
#include<Novice.h>
#include "Iscene.h"
#include "play.h"
#include "Title.h"
#include "Clear.h"

class GameManager
{
private: 
	//シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	//度のシーンを呼び出すかを管理する変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_; //前のシーン

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

public:
	GameManager();
	~GameManager();


	int Run(); //この関数でゲームループを呼び出す
};

