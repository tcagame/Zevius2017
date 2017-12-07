#pragma once
#include <memory>

class Scene : public std::enable_shared_from_this< Scene > {
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

