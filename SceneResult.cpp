#include "SceneResult.h"
#include "Keyboard.h"



SceneResult::SceneResult( ) {

}


SceneResult::~SceneResult( ) {

}

Scene::NEXT_SCENE SceneResult::update( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isPushKey( "ENTER" ) ) {
		return Scene::NEXT_TITLE;
	}

	return Scene::NEXT_CONTINUE;
}

void SceneResult::draw( ) {

}
