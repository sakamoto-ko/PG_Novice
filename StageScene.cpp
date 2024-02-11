#include "StageScene.h"

StageScene::StageScene() {}

StageScene::~StageScene() {}

void StageScene::Initialize() {
	/* playergazo = Novice::LoadTexture("./player.png");
	 playerBulletgazo = Novice::LoadTexture("./playerbullet.png");
	 enemygazo = Novice::LoadTexture("./enemy.png");

	 player = {
	     640, 320, 0, 0, 100, 100, 32, 1, 20, 0, 4, 4,
	 };

	 playerBullet = {
	     0.0f, 0.0f, 0, 0, 16, 8.0f,
	 };

	 enemy = {
	     640, 30, 0, 0, 100, 100, 32, 0, 0, 0, 6, 6,
	 };

	 p2eX = (int)playerBullet.x - (int)enemy.x;
	 p2eY = (int)playerBullet.y - (int)enemy.y;
	 p2eR = (int)playerBullet.r + (int)enemy.r;

	playerFlag.alive = true;
	playerBulletFlag.shot = false;
	enemyFlag.alive = true;*/
}

void StageScene::Update(char keys[256], char preKeys[256]) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo = CLEAR;
	}
	/*if (keys[DIK_W]) {
		player.y -= player.ySpeed;
	}
	if (keys[DIK_A]) {
		player.x -= player.xSpeed;
	}
	if (keys[DIK_S]) {
		player.y += player.ySpeed;
	}
	if (keys[DIK_D]) {
		player.x += player.xSpeed;
	}
	if (player.x <= kWindowWidthLeft) {
		player.x = kWindowWidthLeft;
	}
	if (player.x + 50 >= kWindowWidthRight) {
		player.x = kWindowWidthRight - 50;
		if (keys[DIK_A] && preKeys[DIK_A] != 0) {
			player.x = kWindowWidthRight - 50;
		}
	}
	if (player.y <= 0) {
		player.y = 0;
	}
	if (player.y + 50 >= kWindowWHeight) {
		player.y = kWindowWHeight - 50;
		if (keys[DIK_W] && preKeys[DIK_W] != 0) {
			player.y = kWindowWHeight - 50;
		}
	}

	if (!playerBulletFlag.shot) {
		playerBullet.x = 1;
		playerBullet.y = 1;
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 ||
			Novice::IsPressMouse(0)) {
			playerBullet.x = (float)player.x + 16;
			playerBullet.y = (float)player.y;
			playerBulletFlag.shot = true;
		}
	}
	else if (playerBulletFlag.shot) {
		playerBullet.y -= 8;
	}
	if (playerBullet.y <= 0) {
		playerBulletFlag.shot = false;
	}

	p2eX = (int)playerBullet.x - (int)enemy.x;
	p2eY = (int)playerBullet.y - (int)enemy.y;
	p2eR = (int)playerBullet.r + (int)enemy.r;
	if (p2eX * p2eX + p2eY * p2eY <= p2eR * p2eR) {
		sceneNo = CLEAR;
	}*/
}

void StageScene::Draw() {
	//// プレイヤーの描画
	//Novice::DrawSpriteRect(
	//    player.x, player.y, player.scaleX, player.scaleY, 32, 32, playergazo, 0.5f, 2.0f, 0.0f,
	//    0xFFFFFFFF);

	//// プレイヤーの弾の描画
	//if (playerBulletFlag.shot) {
	//	Novice::DrawSpriteRect(
	//	    (int)playerBullet.x, (int)playerBullet.y, (int)playerBullet.scaleX,
	//	    (int)playerBullet.scaleY, 16, 16, playerBulletgazo, 1.0f, 2.0f, 0.0f, 0xFFFFFFFF);
	//}

	//// 敵の描画
	//if (enemyFlag.alive) {
	//	Novice::DrawSpriteRect(
	//	    enemy.x, enemy.y, enemy.scaleX, enemy.scaleY, 32, 32, enemygazo, 0.5f, 2.0f, 0.0f,
	//	    0xFFFFFFFF);
	//}
}
