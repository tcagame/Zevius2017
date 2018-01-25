#pragma once
#include "Character.h"
class Enemy : public Character {
public:
	Enemy( const Vector& pos, double radius, int score );
	virtual ~Enemy( );
public:
	virtual void draw( int camera_x ) const = 0;
	bool isFinished( );
	void erase( );
private:
	bool _erase;

};

