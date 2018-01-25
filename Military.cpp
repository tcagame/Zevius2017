#include "Military.h"
#include "Player.h"
#include "PlayerShot.h"
#include "Enemy.h"
#include "EnemyData0.h"
#include "EnemyTorkan.h"
#include "EnemyGaruzakato.h"
#include "EnemyBozalogram.h"
#include "EnemyBragzakato.h"
#include "EnemyWall.h"
#include "EnemyBoss.h"
#include "EnemyExplosion.h"
#include "Drawer.h"
#include "Game.h"

#include <array>

const int LOAD_RANGE_X = 2000;

Military::Military( PlayerPtr player ) :
_load_x( 0 ),
_player( player ) {
	EnemyDataPtr enemy_data = EnemyDataPtr( new EnemyData0 );
	_enemy_data = enemy_data->getEnemyData( );
}



Military::~Military( ) {
}

void Military::update( ) {
	loadEnemy( );
	updateEnemy( );
	Drawer::getTask( )->drawString( 0, 0, "%d", _enemies.size( ) );
}

void Military::loadEnemy( ) {
	GamePtr game = Game::getTask( );
	while ( _load_x < MAP_WIDTH_NUM ) {
		int x = _load_x * MAP_SIZE;
		if ( x > game->getGameCount( ) + LOAD_RANGE_X ) {
			//プレイヤーから遠い場合ロードしない
			break;
		}
		for ( int i = 0; i < MAP_HEIGHT_NUM; i++ ) {
			int y = i * MAP_SIZE;
			int idx = _load_x + i * MAP_WIDTH_NUM;
			switch( _enemy_data[ idx ] ) {
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
		_load_x++;
	}
}


void Military::updateEnemy( ) {
	std::list< EnemyPtr >::iterator ite = _enemies.begin( );
	while( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		enemy->update( );
		if ( getOverLappedEnemy( _player ) != EnemyPtr( ) ) {
			_player->setFinished( true );
		}
		if( enemy->isFinished( ) ) {
			addExplosion( EnemyExplosionPtr( new EnemyExplosion( enemy->getPos( ) ) ) );
			ite = _enemies.erase( ite );
			continue;
		}
		ite++;
	}
}

void Military::addEnemy( EnemyPtr enemy ) {
	_enemies.push_back( enemy );
}

void Military::addExplosion( EnemyExplosionPtr explosion ) {
	_explosions.push_back( explosion );
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

void Military::draw( ) {
	GamePtr game = Game::getTask( );
	int camera_x = game->getGameCount( );
	for ( EnemyPtr enemy : _enemies ) {
		enemy->draw( camera_x );
	}
	for ( EnemyExplosionPtr explosion : _explosions ) {
		explosion->draw( camera_x );
	}
}


void Military::clear( ) {
	_enemies.clear( );
}