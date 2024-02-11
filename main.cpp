// インクルード部 ============================================
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#define PI 3.1415926f

#include "InputHandler.h"

// 構造体定義部 ==============================================

const char kWindowTitle[] = "LC1B_10_サカモトコウスケ_竹取物語Another";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	InputHandler* inputHandler = new InputHandler();
	inputHandler->AssignMoveLeftCommand2PressKeyA();
	inputHandler->AssignMoveRightCommand2PressKeyD();

	ICommand* command_ = nullptr;
	Player* player_ = new Player();
	player_->Initialize();

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		command_ = inputHandler->HandleInput();

		if (command_) {
			command_->Exec(*player_);
		}

		player_->Update();

		player_->Draw();

		Novice::EndFrame();

		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete inputHandler;
	delete command_;
	delete player_;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}