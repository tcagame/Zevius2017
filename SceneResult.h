#pragma once
#include "Scene.h"
class SceneResult : public Scene {
public:
	SceneResult( );
	virtual ~SceneResult( );
private:
	NEXT_SCENE update( );
	void draw( );
};

