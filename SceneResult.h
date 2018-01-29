#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Image );

class SceneResult : public Scene {
public:
	SceneResult( );
	virtual ~SceneResult( );
private:
	NEXT_SCENE update( );
	void draw( );
private:
	ImagePtr _image;
	ImagePtr _push;
};

