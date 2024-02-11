#pragma once

#include "IScene.h"

/// <summary>
/// タイトルシーン
/// </summary>
class TitleScene : public IScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	TitleScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene();

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
	int titlegazo = 0u;
	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;
	const int kWindowWidthLeft = 240;
	const int kWindowWidthRight = 1080;
};