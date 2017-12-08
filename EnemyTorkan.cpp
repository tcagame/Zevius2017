#include "EnemyTorkan.h"
#include "Image.h"
#include "Drawer.h"


EnemyTorkan::EnemyTorkan( const Vector& pos ) :
Enemy( pos, 32, 500 ){
	DrawerPtr drawer = Drawer::getTask( );
	_image = drawer->createImage( "enemy/enemy.png" );
}


EnemyTorkan::~EnemyTorkan( ) {
}

void EnemyTorkan::act( ) {
	draw( );
}

void EnemyTorkan::draw( ) {
	_image->setPos( 0, 0 );
	_image->draw( );
}