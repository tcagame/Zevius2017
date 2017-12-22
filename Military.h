#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Enemy );
PTR( Player );
PTR( EnemyTorkan );
PTR( EnemyGaruzakato );
PTR( EnemyBozalogram );
PTR( EnemyBragzakato );
PTR( EnemyWall );

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

