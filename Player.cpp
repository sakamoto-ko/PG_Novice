#include "Player.h"

Player::Player() {}
Player::~Player() {}

// 初期化
void Player::Initialize() { translate_ = {0.0f, 300.0f, 0.0f}; }

// 更新
void Player::Update() {}

// 描画
void Player::Draw() {
	Novice::DrawEllipse(
	    (int)translate_.x, (int)translate_.y, 16, 16, 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

void Player::MoveRight() { 
	this->translate_.x += 3.0f; 
}

void Player::MoveLeft() {
	this->translate_.x -= 3.0f;
}