#include "Enemy.h"

Enemy::Enemy( const Vector& pos , double radius, int score ) :
Character( pos, radius ),
_erase( false ) {
}


Enemy::~Enemy( ) {
}

bool Enemy::isFinished( ) {
	return _erase;
}

void Enemy::erase( ) {
	_erase = true;
}
