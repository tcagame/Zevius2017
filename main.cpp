#include "Application.h"
#include "Game.h"

void main( ) {
	ApplicationPtr app( Application::getInstance( ) );

	app->addTask( Game::getTag( ), TaskPtr( new Game( ) ) );
}