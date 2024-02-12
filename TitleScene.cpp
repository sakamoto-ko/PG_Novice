#include "TitleScene.h"
#include "TextureManager.h"
#include <cassert>

TitleScene::TitleScene() {}
TitleScene::~TitleScene() {}

void TitleScene::Initialize() { 
	titlegazo = Novice::LoadTexture("./title.png"); 
}

void TitleScene::Update(char keys[256], char preKeys[256]) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	Novice::DrawSprite(200, 50, titlegazo, 0.7f, 0.7f, 0.0f, 0xFFFFFFFF);
}
