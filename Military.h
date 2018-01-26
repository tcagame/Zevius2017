#pragma once
#include "smart_ptr.h"
#include "EnemyData.h"
#include <list>

PTR( Image );
PTR( Character );
PTR( Enemy );
PTR( Player );
PTR( EnemyData );
PTR( EnemyTorkan );
PTR( EnemyGaruzakato );
PTR( EnemyBozalogram );
PTR( EnemyBragzakato );
PTR( EnemyWall );
PTR( EnemyToroid );
PTR( EnemyBoss );
PTR( EnemyExplosion );
PTR( Armoury );
PTR( Camera );

class Military {
public:
	Military( PlayerPtr player, CameraPtr camera );
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
	CameraPtr _camera;
	PlayerPtr _player;
	std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > _enemy_data;
	std::list< EnemyPtr > _enemies;
	std::list< EnemyExplosionPtr > _explosions;
	ImagePtr _small_1;
	ImagePtr _small_2;
	ImagePtr _medium;
	ImagePtr _boss;
	int _load_x;
};

