#include "Play.h"

Play::Play() {
	player_ = new Player;
	enemy_ = new Enemy;
}

void Play::Update() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	player_->Update(keys, preKeys);
	enemy_->Update();

	//敵とプレイヤーの弾の当たり判定

	if (HitCheck(enemy_->GetEnemy(), player_->bullet_->GetBullet()) && enemy_->GetIsAlive() == true) {
		enemy_->SetRemain(enemy_->GetRemain() - 1);
		enemy_->SetIsAlive(false);
	}

	//プレイヤーと敵の当たり判定

	if (HitCheck(player_->GetPlayer(), enemy_->GetEnemy())) {
		player_->SetIsAlive(false);
	}

	//敵かプレイヤーが死んだらシーン切り替え

	if (enemy_->GetRemain() <= 0) {
		sceneNo = CLEAR;
	}

}

void Play::Draw() {
	player_->Draw();
	enemy_->Draw();
}

void Play::Init() {
	delete player_;
	delete enemy_;

	player_ = new Player;
	enemy_ = new Enemy;
}