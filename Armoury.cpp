#include "Armoury.h"
#include "Military.h"
#include "PlayerShot.h"
#include "Enemy.h"


Armoury::Armoury( ) {
}


Armoury::~Armoury( ) {

}

void Armoury::update( MilitaryPtr military ) {
	_military = military;
	std::list< PlayerShotPtr >::iterator ite = _shots.begin( );
	while( ite != _shots.end( ) ) {
		PlayerShotPtr shot = *ite;
		shot->update( );
		EnemyPtr enemy = _military->getOverLappedEnemy( shot );
		if ( enemy != EnemyPtr( )  && !enemy->isAttackCharacter( ) ) {
			ite = _shots.erase( ite );
			enemy->erase( );
			continue;
		}
		ite++;
	}
}

void Armoury::draw( int camera ) const {
	for ( PlayerShotPtr shot : _shots ) {
		shot->draw( camera );
	}
}



void Armoury::addShot( PlayerShotPtr shot ) {
  	_shots.push_back( shot );
}

