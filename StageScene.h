#pragma once
#include <sstream>

/// <summary>
/// ゲームシーン
/// </summary>
class StageScene {

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
