#include "Armoury.h"
#include "Military.h"
#include "PlayerShot.h"


Armoury::Armoury( ) {
}


Armoury::~Armoury( ) {

}

void Armoury::update( ) {
	std::list< PlayerShotPtr >::iterator ite = _shots.begin( );
	while( ite != _shots.end( ) ) {
		PlayerShotPtr shot = *ite;
		shot->update( );
		ite++;
	}
}

void Armoury::draw( ) const {
	for ( PlayerShotPtr shot : _shots ) {
		shot->draw( );
	}
}



void Armoury::addShot( PlayerShotPtr shot ) {
  	_shots.push_back( shot );
}

