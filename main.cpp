#include "Application.h"
#include "Game.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "define.h"

void main( ) {
	ApplicationPtr app( Application::getInstance( ) );
	app->setWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	app->addTask( Drawer::getTag( ), TaskPtr( new Drawer( "resouces" ) ) );
	app->addTask( Keyboard::getTag( ), TaskPtr( new Keyboard( ) ) );

	app->addTask( Game::getTag( ), TaskPtr( new Game( ) ) );
}