#pragma once

#include <memory>

/// <summary>
/// タイトルシーン
/// </summary>
class ClearScene {

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
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
};