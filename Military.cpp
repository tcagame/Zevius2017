#include "Military.h"
#include "Player.h"
#include "PlayerShot.h"
#include "Enemy.h"
#include "EnemyData.h"
#include "EnemyData0.h"
#include "EnemyTorkan.h"
#include "EnemyGaruzakato.h"
#include "EnemyBozalogram.h"
#include "EnemyBragzakato.h"
#include "EnemyWall.h"
#include "EnemyBoss.h"

#include <array>


Military::Military( PlayerPtr player ) {
	_player = player;
	_enemy_data = EnemyDataPtr( new EnemyData0 );
	std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > enemy_data = _enemy_data->getEnemyData( );
	for ( int i = 0; i < MAP_WIDTH_NUM * MAP_HEIGHT_NUM; i++ ) {
		int x = i % MAP_WIDTH_NUM * MAP_SIZE;
		int y = i / MAP_WIDTH_NUM * MAP_SIZE;
		switch( enemy_data[ i ] ) {
		case 'A':
			addEnemy( EnemyTorkanPtr( new EnemyTorkan( Vector( x, y ) ) ) );
			break;
		case 'B':
			addEnemy( EnemyGaruzakatoPtr( new EnemyGaruzakato( Vector( x, y ), _player ) ) );
			break;
		case 'C':
			addEnemy( EnemyBozalogramPtr( new EnemyBozalogram( Vector( x, y ) ) ) );
			break;
		case 'D':
			addEnemy( EnemyBragzakatoPtr( new EnemyBragzakato( Vector( x, y ), _player ) ) );
			break;
		case 'E':
			addEnemy( EnemyWallPtr( new EnemyWall( Vector( x, y ) ) ) );
			break;
		case '#':
			addEnemy( EnemyBossPtr( new EnemyBoss( Vector( x, y ) ) ) );
			break;
		}
	}
}



Military::~Military( ) {
}

void Military::update( ) {
	std::list< EnemyPtr >::iterator ite = _enemies.begin( );
	while( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		enemy->update( );
		if( enemy->isFinished( ) == true ) {
			ite = _enemies.erase( ite );
			continue;
		}
		ite++;
	}
}

void Military::addEnemy( EnemyPtr enemy ) {
	_enemies.push_back( enemy );
}

EnemyPtr Military::getOverLappedEnemy( CharacterPtr character ) const {
	for ( EnemyPtr enemy : _enemies ) {
		if( enemy->isOverLapped( character ) ) {
			//あたっている場合エネミーを返す
			return enemy;
		}
	}
	return EnemyPtr( );
}


void Military::clear( ) {
	_enemies.clear( );
}