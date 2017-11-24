#pragma once

#include "Task.h"
#include <string>
#include "Scene.h"

PTR( Game );
PTR( Scene );

class Game : public Task {
public:
	Game( );
	virtual ~Game( );
public:
	static std::string getTag( ) { return "GAME"; };
	static GamePtr getTask( );
public:
	void update( );
	void changeScene( );
	int getGameCount( );
private:
	void initialize( );
private:
	ScenePtr _scene;
	Scene::NEXT_SCENE _next;
	int _count;
};

