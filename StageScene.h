#pragma once
#include "IScene.h"

// キャラクター
typedef struct Character {
	int x;
	int y;
	int scaleX;
	int scaleY;
	int w;
	int h;
	int r;
	int zanki;
	int attack;
	int hitPoint;
	int xSpeed;
	int ySpeed;
} character;

typedef struct Flag {
	int alive;
	int hit;
	int bakuhatu;
	int appear;
	int shot;
} flag;

// 弾
typedef struct Bullet {
	float x;
	float y;
	int scaleX;
	int scaleY;
	int r;
	float speed;
} bullet;

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
	void Update(char keys[256], char preKeys[256]) override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private:
	int playergazo = 0u;
	int playerBulletgazo = 0u;
	int enemygazo = 0u;

	// プレイヤー変数
	Character player{
	    640, 320, 0, 0, 100, 100, 32, 1, 20, 0, 4, 4,
	};
	Flag playerFlag{
	    1, 0, 0, 0, 0,
	};

	// プレイヤーの弾変数
	Bullet playerBullet{
	    0.0f, 0.0f, 0, 0, 16, 8.0f,
	};
	Flag playerBulletFlag{
	    0, 0, 0, 0, 0,
	};

	// 敵変数
	Character enemy{
	    640, 30, 0, 0, 100, 100, 32, 0, 0, 0, 6, 6,
	};
	Flag enemyFlag{
	    0, 0, 0, 0, 0,
	};
	// プレイヤー弾と敵
	int p2eX = (int)playerBullet.x - (int)enemy.x;
	int p2eY = (int)playerBullet.y - (int)enemy.y;
	int p2eR = (int)playerBullet.r + (int)enemy.r;

	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;
	const int kWindowWidthLeft = 240;
	const int kWindowWidthRight = 1080;
};
