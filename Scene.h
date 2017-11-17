#pragma once
class Scene {
public:
	enum NEXT_SCENE {
		NEXT_TITLE,
		NEXT_PLAY,
		NEXT_RESULT,
		NEXT_CONTINUE
	};
public:
	Scene( );
	virtual ~Scene( );
	virtual NEXT_SCENE update( ) = 0;
	virtual void draw( ) = 0;
};

