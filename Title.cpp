#include "Title.h"
#include "Function.h"

Title::Title() {
}

void Title::Update() {
	if (Novice::CheckHitKey(DIK_RETURN)) {
		sceneNo = STAGE;
	}
}

void Title::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid);
}

void Title::Init() {
}