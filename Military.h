#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Character );
PTR( Enemy );
PTR( Player );
PTR( EnemyData );
PTR( EnemyTorkan );
PTR( EnemyGaruzakato );
PTR( EnemyBozalogram );
PTR( EnemyBragzakato );
PTR( Armoury );

class Military {
public:
	Military( PlayerPtr player );
	virtual ~Military( );
public:
	void update( );
	void addEnemy( EnemyPtr enemy );
	EnemyPtr getOverLappedEnemy( CharacterPtr character ) const;
	void clear( );
private:
	PlayerPtr _player;
	EnemyDataPtr _enemy_data;
	std::list< EnemyPtr > _enemies;
};

