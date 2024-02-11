#pragma once
#include "IScene.h"
#include "InputHandler.h"

/// <summary>
/// ゲームシーン
/// </summary>
class StageScene : public IScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	StageScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~StageScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private:
	InputHandler* inputhandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_ = nullptr;

	int playergazo = 0u;
	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;
	const int kWindowWidthLeft = 240;
	const int kWindowWidthRight = 1080;
};
