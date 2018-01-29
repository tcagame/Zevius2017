#include "Enemy.h"
#include "define.h"

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

int Enemy::getSize( ) const {
	return NORMAL_GRAPH_SIZE;
}

bool Enemy::isAttackCharacter( ) {
	return _attack;
}
