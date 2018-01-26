#include "Enemy.h"

Enemy::Enemy( const Vector& pos , double radius, int score, bool attack ) :
Character( pos, radius ),
_erase( false ),
_attack( attack ) {
}


Enemy::~Enemy( ) {
}

bool Enemy::isFinished( ) {
	return _erase;
}

void Enemy::erase( ) {
	_erase = true;
}

bool Enemy::isAttackCharacter( ) {
	return _attack;
}
