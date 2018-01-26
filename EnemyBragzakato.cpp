#include "EnemyBragzakato.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"
#include "Player.h"
#include "EnemyGaruzakatoAttack.h"
#include "Military.h"

//ŽRˆü
const double BRAGZAKATO_VEC = 3;
const double ATTACK_RANGE = 100;

PTR( EnemyGaruzakatoAttack );

EnemyBragzakato::EnemyBragzakato( const Vector& pos, PlayerPtr player, ImagePtr small_1, MilitaryPtr military ) :
Enemy( pos, SMALL_GRAPH_SIZE / 2, 500, false ),
_attack( false ),
_count( 0 ),
_image( small_1 ),
_player( player ),
_military( military ) {

}

   
EnemyBragzakato::~EnemyBragzakato( ) {

}

void EnemyBragzakato::act( ) {
	Vector target_pos = _player->getPos( );
	Vector pos = getPos( );
	Vector dir = ( target_pos - pos ).normalize( );
	Vector vec = dir * BRAGZAKATO_VEC;

	setVec( vec );
	if ( ( target_pos - pos ).getLength( ) < ATTACK_RANGE ) {
		_attack = true;
		//ày—ô‚·‚é‚æ
	}
	if ( _attack ) {
		_count++;
		setVec( Vector( ) );
		DrawerPtr drawer = Drawer::getTask( );
		if ( _count % 120 == 0 ) {
			erase( );
			Vector axis( 0, 0, 1 );
			Matrix rots[ ] = {
				Matrix::makeTransformRotation( axis, 0 ),
				Matrix::makeTransformRotation( axis, PI / 4 ),
				Matrix::makeTransformRotation( axis, PI / 6 ),
				Matrix::makeTransformRotation( axis * -1, PI / 4 ),
				Matrix::makeTransformRotation( axis * -1, PI / 6 )
			};
			for ( int i = 0; i < 5; i++ ) {
				_military->addEnemy( EnemyGaruzakatoAttackPtr( new EnemyGaruzakatoAttack( pos, rots[ i ].multiply( Vector( -5, 0 ) ) ) ) );
			}
		}
	}
}


void EnemyBragzakato::draw( int camera_x ) const{
	_image->setRect( SMALL_GRAPH_SIZE * 0, SMALL_GRAPH_SIZE * 3, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE );
	_image->setPos( ( int )getPos( ).x - camera_x, ( int )getPos( ).y );
	_image->draw( );
}