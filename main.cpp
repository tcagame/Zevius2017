#include "Application.h"
#include "Game.h"
#include "Drawer.h"
#include "Keyboard.h"

void main( ) {
	ApplicationPtr app( Application::getInstance( ) );

	app->addTask( Drawer::getTag( ), TaskPtr( new Drawer( "resouces" ) ) );
	app->addTask( Keyboard::getTag( ), TaskPtr( new Keyboard( ) ) );

	app->addTask( Game::getTag( ), TaskPtr( new Game( ) ) );
}