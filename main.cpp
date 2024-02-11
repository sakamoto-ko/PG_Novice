// インクルード部 ============================================
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#define PI 3.1415926f

#include "GameManager.h"

// 構造体定義部 ==============================================

const char kWindowTitle[] = "LC1B_10_サカモトコウスケ_竹取物語Another";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowWHeight);

	GameManager* gameManager = new GameManager();

	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}