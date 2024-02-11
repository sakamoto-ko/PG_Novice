#pragma once
#include <Novice.h>
#include "Vector3.h"

// GameSceneクラスの前方宣言
class GameScene;

class Player {
private:
	Vector3 translate_ = {0.0f, 0.0f, 0.0f};

public:
	Player();
	~Player();
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();

	void MoveRight();
	void MoveLeft();
};
