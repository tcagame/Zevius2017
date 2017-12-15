#include "Military.h"
#include "Player.h"
#include "PlayerShot.h"
#include "Enemy.h"
#include "EnemyTorkan.h"
#include "EnemyGaruzakato.h"
#include "EnemyBozalogram.h"
#include "EnemyBragzakato.h"

const Vector T_POS( 1200, 400 );
const Vector GARUZAKATO_POS( 1200, 400 );
const Vector BOSA_POS( 1200, 400 );
const Vector B_POS( 1200, 400 );


Military::Military( PlayerPtr player ) {
	_player = player;
	//addEnemy( EnemyTorkanPtr( new EnemyTorkan( T_POS ) ) );
	//addEnemy( EnemyGaruzakatoPtr( new EnemyGaruzakato( GARUZAKATO_POS, _player ) ) );
	//addEnemy( EnemyBozalogramPtr( new EnemyBozalogram( BOSA_POS ) ) );
	addEnemy( EnemyBragzakatoPtr( new EnemyBragzakato( B_POS, _player ) ) );

}



Military::~Military( ) {
}

void Military::update( ) {
	std::list< EnemyPtr >::iterator ite = _enemies.begin( );
	while( ite != _enemies.end( ) ) {
		EnemyPtr enemy = *ite;
		enemy->update( );
		if( enemy->isOverLapped( _player ) ) {
			_enemies.erase( ite );
			continue;
		}
		ite++;
	}
}

void Military::addEnemy( EnemyPtr enemy ) {
	_enemies.push_back( enemy );
}

std::list< EnemyPtr > Military::getEnemylist( ) const {
	return _enemies;
}
