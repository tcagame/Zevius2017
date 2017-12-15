#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Player );
PTR( EnemyTorkan );
PTR( EnemyGaruzakato );

class Military {
public:
	Military( PlayerPtr player );
	virtual ~Military( );
public:
	void update( );
	void addEnemy( EnemyPtr enemy );
	std::list< EnemyPtr > getEnemylist( ) const;
private:
	PlayerPtr _player;
	std::list< EnemyPtr > _enemies;
};

