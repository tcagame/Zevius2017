#pragma once
#include "smart_ptr.h"
#include "EnemyData.h"
#include <list>

PTR( Character );
PTR( Enemy );
PTR( Player );
PTR( EnemyData );
PTR( EnemyTorkan );
PTR( EnemyGaruzakato );
PTR( EnemyBozalogram );
PTR( EnemyBragzakato );
PTR( EnemyWall );
PTR( EnemyBoss );
PTR( EnemyExplosion );
PTR( Armoury );

class Military {
public:
	Military( PlayerPtr player );
	virtual ~Military( );
public:
	void update( );
	void addEnemy( EnemyPtr enemy );
	void addExplosion( EnemyExplosionPtr enemy );
	EnemyPtr getOverLappedEnemy( CharacterPtr character ) const;
	void clear( );
	void draw( );
private:
	void loadEnemy( );
	void updateEnemy( );
private:
	PlayerPtr _player;
	std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > _enemy_data;
	std::list< EnemyPtr > _enemies;
	std::list< EnemyExplosionPtr > _explosions;
	int _load_x;
};

