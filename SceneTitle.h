#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Image )

class SceneTitle : public Scene {
public:
	SceneTitle( );
	virtual ~SceneTitle( );
private:
	NEXT_SCENE update( );
	void draw( );
private:
	ImagePtr _image;
	ImagePtr _push;
};

