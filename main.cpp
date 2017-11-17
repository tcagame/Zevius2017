#include "Application.h"
#include "Game.h"
#include "Drawer.h"

void main( ) {
	ApplicationPtr app( Application::getInstance( ) );

	app->addTask( Drawer::getTag( ), TaskPtr( new Drawer( "resouces" ) ) );

	app->addTask( Game::getTag( ), TaskPtr( new Game( ) ) );
}