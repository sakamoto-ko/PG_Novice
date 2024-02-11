#include "ClearScene.h"
#include "TextureManager.h"
#include <cassert>

ClearScene::ClearScene() {}
ClearScene::~ClearScene() {}

void ClearScene::Initialize() { 
	gamecleargazo = Novice::LoadTexture("./clear.png");
}

void ClearScene::Update(char keys[256], char preKeys[256]) { 
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawSprite(0, 0, gamecleargazo, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF); 
}
