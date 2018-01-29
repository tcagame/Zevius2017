#include "Enemy.h"
#include "define.h"

Enemy::Enemy( const Vector& pos , double radius, int score, bool attack ) :
Character( pos, radius ),
_erase( false ),
_attack( attack ),
_boss_finished( 3 ){
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

void Enemy::deadBoss( ) {
	_boss_finished--;
}

bool Enemy::isBossFinished( ) {
	if ( _boss_finished == 0 ) {
		return true;
	}
	return false;
}

