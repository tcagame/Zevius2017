#pragma once

#include "Task.h"
#include <string>

#include "ScenePlay.h"

PTR( Game );
PTR( ScenePlay );

class Game : public Task {
public:
	Game( );
	virtual ~Game( );
public:
	static std::string getTag( ) { return "GAME"; };
	static GamePtr getTask( );
public:
	void update( );
	void run( );
private:
	ScenePlayPtr _scene_play;
};

