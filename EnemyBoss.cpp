#include "EnemyBoss.h"
#include "Camera.h"
#include "Image.h"
#include "Military.h"
#include "define.h"
#include "EnemyBossAttack.h"

const int BOSS_GRAPH_SIZE = 96;
const int ANIM_NUM = 7;
const int HP = 30;
const int MY_POSITION = 1000;

const int ATTACK_TIME = 60;

EnemyBoss::EnemyBoss( const Vector& pos, ImagePtr boss, CameraPtr camera, MilitaryPtr military, ImagePtr attack_img ) :
Enemy( pos, 48, 5000, false ),
_image( boss ),
_attack_img( attack_img ),
_camera( camera ),
_military( military ),
_pos( pos ),
_hp( HP ) {
}


EnemyBoss::~EnemyBoss( ) {
}

void EnemyBoss::act( ) {
	Vector vec = Vector( _camera->getCameraPos( ) + MY_POSITION, getPos( ).y ) - getPos( );
	setVec( vec.normalize( ) );
	_count++;
	if ( _count % ATTACK_TIME == 0 ) {
		Vector axis( 0, 0, 1 );
			Matrix rots[ ] = {
				Matrix::makeTransformRotation( axis, 0 ),
				Matrix::makeTransformRotation( axis, PI / 4 ),
				Matrix::makeTransformRotation( axis, PI / 6 ),
				Matrix::makeTransformRotation( axis * -1, PI / 4 ),
				Matrix::makeTransformRotation( axis * -1, PI / 6 )
			};
			for ( int i = 0; i < 5; i++ ) {
				_military->addEnemy( EnemyBossAttackPtr( new EnemyBossAttack( Vector( getPos( ).x, getPos( ).y + BOSS_GRAPH_SIZE / 2 - 12 ), rots[ i ].multiply( Vector( -5, 0 ) ), _attack_img ) ) );
			}
	}
}

void EnemyBoss::draw( int camera_x ) const {
	_image->setRect( BOSS_GRAPH_SIZE * ( _count % ANIM_NUM ), 0, BOSS_GRAPH_SIZE, BOSS_GRAPH_SIZE );
	_image->setPos( getPos( ).x - camera_x, getPos( ).y );
	_image->draw( );
}

void EnemyBoss::erase( ) {
	_hp--;
	if ( _hp <= 0 ) {
		Enemy::deadBoss( );
		Enemy::erase( );
	}
}

int EnemyBoss::getSize( ) const {
	return BOSS_GRAPH_SIZE;
}
