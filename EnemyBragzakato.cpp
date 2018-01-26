#include "EnemyBragzakato.h"
#include "Image.h"
#include "Drawer.h"
#include "define.h"
#include "Player.h"

//山蔭
const double BRAGZAKATO_VEC = 3;
const double ATTACK_RANGE = 100;

EnemyBragzakato::EnemyBragzakato( const Vector& pos, PlayerPtr player, ImagePtr small_1 ) :
	Enemy( pos, SMALL_GRAPH_SIZE / 2, 500 ),
_attack( false ),
_count( 0 ),
_image( small_1 ),
_player( player ){

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
		//炸裂するよ
	}
	if ( _attack ) {
		_count++;
		setVec( Vector( ) );
		DrawerPtr drawer = Drawer::getTask( );
		if ( _count % 120 == 0 ) {
			drawer->drawString( 0, 0, "どおおおおおおおん" );//デバッグメッセージ
		}
	}

}

void EnemyBragzakato::draw( int camera_x ) const{
	_image->setRect( SMALL_GRAPH_SIZE * 0, SMALL_GRAPH_SIZE * 3, SMALL_GRAPH_SIZE, SMALL_GRAPH_SIZE );
	_image->setPos( ( int )getPos( ).x - camera_x, ( int )getPos( ).y );
	_image->draw( );
}