#pragma once
#include <Novice.h>
#include <memory>

enum SCENE {TITLE,STAGE,CLEAR};
class IScene {
protected:
	static int sceneNo;

public:
	virtual void Initialize() = 0;
	virtual void Update(char keys[256], char preKeys[256]) = 0;
	virtual void Draw() = 0;

	virtual ~IScene();
	int GetSceneNo();
};