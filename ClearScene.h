#pragma once

#include "IScene.h"

/// <summary>
/// タイトルシーン
/// </summary>
class ClearScene  : public IScene{

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	ClearScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~ClearScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(char keys[256], char preKeys[256]) override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

	private:
	int gamecleargazo = 0u;
};