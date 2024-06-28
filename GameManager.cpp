#include "GameManager.h"

GameManager::GameManager()
{
	//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<Title>();
	sceneArr_[STAGE] = std::make_unique<Play>();
	sceneArr_[CLEAR] = std::make_unique<Clear>();

	//初期シーンの設定
	currentSceneNo_ = TITLE;
}

GameManager::~GameManager()
{
}

int GameManager::Run()
{
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame(); //フレームの開始

		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		//シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		//シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		//更新処理
		sceneArr_[currentSceneNo_]->Update(); //シーンごとの更新処理
		
		//描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame(); //フレームの終了

		//ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}
