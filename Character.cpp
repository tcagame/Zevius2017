#include "Character.h"



Character::Character( const Vector& pos, const double radius ) :
_pos( pos ),
_radius( radius ) {

}


Character::~Character( ) {

}

void Character::update( ) {
	act( );
	_pos += _vec;
}

Vector Character::getPos( ) const{
	return _pos;
}

Vector Character::getVec( ) const{
	return _vec;
}

double Character::getRadius( ) const{
	return _radius;
}


void Character::setVec( const Vector& vec ) {
	_vec = vec;
}

bool Character::isOverLapped( CharacterPtr target ) const{
	bool result = false;
	
	Vector self_pos = _pos + Vector( 1, 1 ) * _radius;
	Vector target_pos = target->getPos( ) + Vector( 1, 1 ) * target->getRadius( );

	if ( ( self_pos - target_pos ).getLength( ) < _radius + target->getRadius( ) ) {
		result = true;
	}

	return result;
}

