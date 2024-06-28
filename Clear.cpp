#include <Novice.h>
#include "Clear.h"
#include "Function.h"

Clear::Clear() {
}

void Clear::Update() {
	if (Novice::CheckHitKey(DIK_SPACE)) {
		sceneNo = TITLE;
	}
}

void Clear::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);
}

void Clear::Init() {
}