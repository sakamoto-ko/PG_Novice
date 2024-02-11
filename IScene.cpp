#include "IScene.h"

int IScene::sceneNo = STAGE;

IScene::~IScene() {}

int IScene::GetSceneNo() { return sceneNo; }
