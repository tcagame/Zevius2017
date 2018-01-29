#include "EnemyGaruzakato.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"
#include "Player.h"
#include "Time.h"
#include "Military.h"
#include "EnemyGaruzakatoAttack.h"

//ŠÔ‹{
const double GARUZA_VEC = 4;
const int TIMER = 240;


EnemyGaruzakato::EnemyGaruzakato( const Vector& pos, PlayerPtr player, ImagePtr small_1, MilitaryPtr military, ImagePtr attack_img ) :
Enemy( pos, SMALL_GRAPH_SIZE / 4, 30, false ),
_time( TIMER ), 
_player( player ),
_image( small_1 ), 
_attack_img( attack_img ),
_military( military ) {
}


EnemyGaruzakato::~EnemyGaruzakato( ) {
}

void EnemyGaruzakato::act( ) {
	_time--;
	Vector target_pos = _player->getPos( );
	Vector pos = getPos( );
	Vector dir = ( target_pos - pos ).normalize( );
	Vector vec = dir * GARUZA_VEC;


	setVec( vec );
	if ( _time < 0 ) {
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
			_military->addEnemy( EnemyGaruzakatoAttackPtr( new EnemyGaruzakatoAttack( pos, rots[ i ].multiply( Vector( -5, 0 ) ), _attack_img ) ) );
		}
	}
}

void EnemyGaruzakato::draw( int camera_x ) const{
	_image->setRect( SMALL_GRAPH_SIZE * 5, SMALL_GRAPH_SIZE * 3, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE );
	_image->setPos( ( int )getPos( ).x - camera_x, ( int )getPos( ).y );
	_image->draw( );
}
