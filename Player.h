#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include"Input.h"
#include"ViewProjection.h"

//GameSceneクラスの前方宣言
class GameScene;

class Player {
private:
	//ワールド変換データ
	WorldTransform worldTransform_;

	//モデル
	Model* model_ = nullptr;

	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	//キーボード入力
	Input* input_ = nullptr;

public:
	Player();
	~Player();
	//初期化
	void Initialize(Model* model);
	//更新
	void Update(const ViewProjection viewProjection);
	//描画
	void Draw(ViewProjection viewProjection);
};
