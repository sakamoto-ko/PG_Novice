#include <Novice.h>

const char kWindowTitle[] = "LE2A_06_サカモト_コウスケ";
struct Vector2 {
	float x;
	float y;
};
struct Character {
	Vector2 pos;
	Vector2 speed;
	float radius;
	float diameter;
	Vector2 scale;
	int color;
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int kWindowWidth = 800;
	int kWindowWidthHalf = 400;
	int kWindowHeight = 400;
	int kWindowHeightHalf = 200;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// 変数
	int x, y;

	int color1 = 0xFFFF00FF;
	// int color2 = 0xAC3232FF;

	// ワールド座標
	//int worldX = kWindowWidthHalf;
	int worldY = kWindowHeightHalf;

	// プレイヤー変数
	Character player = {};
	player.pos.x = 0.0f;
	player.pos.y = 0.0f;
	player.speed.x = 2.0f * 0.7f;
	player.speed.y = 2.0f * 0.7f;
	player.radius = 32.0f;
	player.diameter = 64.0f;
	player.scale.x = 1.0f;
	player.scale.y = 2.0f;
	player.color = color1;

	player.pos.y = player.radius;
	float moniterPlayerY = 0.0f;

	// エネミー変数
	Character enemy = {};
	enemy.pos.x = 0.0f;
	enemy.pos.y = 0.0f;
	enemy.speed.x = 0.0f;
	enemy.speed.y = 0.0f;
	enemy.radius = 16.0f;
	enemy.diameter = 32.0f;
	enemy.scale.x = 2.0f;
	enemy.scale.y = 2.0f;
	enemy.color = color1;

	enemy.pos.y = enemy.radius;
	float moniterEnemyY = 0.0f;

	// 画像変数
	int circleGazo = Novice::LoadTexture("./Circle.png");
	int circleHit = Novice::LoadTexture("./CircleHit.png");
	int circleW = Novice::LoadTexture("./CircleW.png");
	int circleWHit = Novice::LoadTexture("./CircleWHit.png");
	int circle = circleW;
	int isWhitePlayer = true;

	// 衝突変数
	float playerLeftTopX = 0.0f;
	float playerLeftTopY = 0.0f;
	float playerRightBottomX = 0.0f;
	float playerRightBottomY = 0.0f;

	float enemyLeftTopX = 0.0f;
	float enemyLeftTopY = 0.0f;
	float enemyRightBottomX = 0.0f;
	float enemyRightBottomY = 0.0f;

	int isHitPlayer = false;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		/*プレイヤー*/

		// プレイヤーのマウス処理
		Novice::GetMousePosition(&x, &y);
		if (Novice::IsPressMouse(0)) {
			player.pos.x = x - player.radius;
			player.pos.y = worldY - y + player.radius;
		}

		moniterPlayerY = worldY - player.pos.y;

		// プレイヤーの移動処理
		if (keys[DIK_W]) {
			player.pos.y += player.speed.y;
		} else if (keys[DIK_S]) {
			player.pos.y -= player.speed.y;
		} else if (keys[DIK_A]) {
			player.pos.x -= player.speed.x;
		} else if (keys[DIK_D]) {
			player.pos.x += player.speed.x;
		}

		// プレイヤーの拡縮処理
		if (keys[DIK_Q]) {
			player.scale.x -= 0.01f;
		} else if (keys[DIK_E]) {
			player.scale.x += 0.01f;
		} else if (player.scale.x <= 0.02f) {
			player.scale.x = 0.02f;
		}

		if (keys[DIK_Z]) {
			player.scale.y -= 0.01f;
		} else if (keys[DIK_C]) {
			player.scale.y += 0.02f;
		} else if (player.scale.y <= 0.02f) {
			player.scale.y = 0.02f;
		}

		// プレイヤーの色の処理
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			if (!isHitPlayer) {
				if (isWhitePlayer) {
					circle = circleW;
					isWhitePlayer = false;
				} else if (!isWhitePlayer) {
					circle = circleGazo;
					isWhitePlayer = true;
				}
			} else if (isHitPlayer) {
				if (isWhitePlayer) {
					circle = circleWHit;
					isWhitePlayer = false;
				} else if (!isWhitePlayer) {
					circle = circleHit;
					isWhitePlayer = true;
				}
			}
		}
		if (!isHitPlayer) {
			if (isWhitePlayer) {
				circle = circleW;
			} else if (!isWhitePlayer) {
				circle = circleGazo;
			}
		} else if (isHitPlayer) {
			if (isWhitePlayer) {
				circle = circleWHit;
			} else if (!isWhitePlayer) {
				circle = circleHit;
			}
		}

		/*エネミー*/
		enemy.pos.x = kWindowWidth / 2 - enemy.diameter;
		moniterEnemyY = worldY - enemy.pos.y - enemy.radius;

		/*衝突処理*/
		playerLeftTopX = player.pos.x;
		playerLeftTopY = moniterPlayerY;
		playerRightBottomX = player.pos.x + player.diameter;
		playerRightBottomY = moniterPlayerY + player.diameter;

		enemyLeftTopX = enemy.pos.x;
		enemyLeftTopY = moniterEnemyY;
		enemyRightBottomX = enemy.pos.x + enemy.diameter;
		enemyRightBottomY = moniterEnemyY + player.diameter;

		if (enemyLeftTopX < playerRightBottomX && playerLeftTopX < enemyRightBottomX) {
			if (enemyLeftTopY < playerRightBottomY && playerLeftTopY < enemyRightBottomY) {
				isHitPlayer = true;
			} else {
				isHitPlayer = false;
			}
		} else {
			isHitPlayer = false;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 背景の描画
		Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0f, 0x0000FFFF, kFillModeSolid);

		// 線の描画
		Novice::DrawLine(0, kWindowHeightHalf, kWindowWidth, kWindowHeightHalf, 0xFFFFFFFF);
		Novice::DrawLine(kWindowWidthHalf, 0, kWindowWidthHalf, kWindowHeight, 0xFFFFFFFF);

		// 文字の描画
		Novice::ScreenPrintf(0, 0, "WASD :   mouse :");
		Novice::ScreenPrintf(0, 15, "QE :    ZC :");
		Novice::ScreenPrintf(0, 30, "space :");

		// エネミーの描画
		Novice::DrawSprite(
		    (int)enemy.pos.x, (int)moniterEnemyY, circle, enemy.scale.x, enemy.scale.y, 0.0f,
		    0xFFFFFFFF);

		// プレイヤーの描画
		Novice::DrawSprite(
		    (int)player.pos.x, (int)moniterPlayerY, circle, player.scale.x, player.scale.y,
		    0.0f,
		    0xFFFFFFFF);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}