#include "StageScene.h"

StageScene::StageScene() {}

StageScene::~StageScene() {
	delete inputhandler_;
	delete iCommand_;
	delete player_;
}

void StageScene::Initialize() { 
	inputhandler_ = new InputHandler();

	inputhandler_->AssignMoveLeftCommand2PressKeyA();
	inputhandler_->AssignMoveRightCommand2PressKeyD();

	player_ = new Player();
}

void StageScene::Update() {
	iCommand_ = inputhandler_->HandleInput();

	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	}
}

void StageScene::Draw() {}
