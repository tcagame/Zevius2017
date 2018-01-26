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
#include "EnemyToroid.h"
#include "EnemyBoss.h"
#include "EnemyExplosion.h"
#include "Drawer.h"
#include "Image.h"
#include "Game.h"
#include "Camera.h"

#include <array>

const int LOAD_RANGE_X = 2000;

Military::Military( PlayerPtr player, CameraPtr camera ) :
_load_x( 0 ),
_player( player ),
_camera( camera ) {
	EnemyDataPtr enemy_data = EnemyDataPtr( new EnemyData0 );
	_enemy_data = enemy_data->getEnemyData( );
	DrawerPtr drawer = Drawer::getTask( );
	_small_1 = drawer->createImage( "enemy/enemy_small1.png" );
	_small_2 = drawer->createImage( "enemy/enemy_small2.png" );
	_medium = drawer->createImage( "enemy/enemy_medium.png" );
	_boss = drawer->createImage( "enemy/enemy_boss.png" );
}



Military::~Military( ) {
}

void Military::update( ) {
	loadEnemy( );
	updateEnemy( );
	Drawer::getTask( )->drawString( 0, 0, "%d", _enemies.size( ) );
}

void Military::loadEnemy( ) {
	while ( _load_x < MAP_WIDTH_NUM ) {
		int x = _load_x * MAP_SIZE;
		if ( x > _camera->getCameraPos( ) + LOAD_RANGE_X ) {
			//プレイヤーから遠い場合ロードしない
			break;
		}
		for ( int i = 0; i < MAP_HEIGHT_NUM; i++ ) {
			int y = i * MAP_SIZE;
			int idx = _load_x + i * MAP_WIDTH_NUM;
			switch( _enemy_data[ idx ] ) {
			case 'A':
				addEnemy( EnemyTorkanPtr( new EnemyTorkan( Vector( x, y ), _small_2 ) ) );
				break;
			case 'B':
				addEnemy( EnemyGaruzakatoPtr( new EnemyGaruzakato( Vector( x, y ), _player, _small_1 ) ) );
				break;
			case 'C':
				addEnemy( EnemyBozalogramPtr( new EnemyBozalogram( Vector( x, y ), _medium ) ) );
				break;
			case 'D':
				addEnemy( EnemyBragzakatoPtr( new EnemyBragzakato( Vector( x, y ), _player, _small_1 ) ) );
				break;
			case 'E':
				addEnemy( EnemyWallPtr( new EnemyWall( Vector( x, y ), _medium ) ) );
				break;
			case 'F':
				addEnemy( EnemyToroidPtr( new EnemyToroid( Vector( x, y ), _small_2 ) ) );
				break;
			case '#':
				addEnemy( EnemyBossPtr( new EnemyBoss( Vector( x, y ), _boss ) ) );
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
	for ( EnemyPtr enemy : _enemies ) {
		enemy->draw( _camera->getCameraPos( ) );
	}
	for ( EnemyExplosionPtr explosion : _explosions ) {
		explosion->draw( _camera->getCameraPos( ) );
	}
}


void Military::clear( ) {
	_enemies.clear( );
}