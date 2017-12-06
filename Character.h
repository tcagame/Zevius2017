#pragma once

#include "mathmatics.h"
#include "smart_ptr.h"

PTR( Character )

class Character {
public:
	Character( const Vector& pos, const double radius );
	virtual ~Character( );
public:
	virtual void act( ) = 0;
	void update( );
	double getRadius( );
	Vector getPos( );
	Vector getVec( );
protected:
	void setVec( const Vector& vec );
	bool isOverLapped( CharacterPtr target );
private:
	Vector _pos;
	Vector _vec;
	int _radius;
};

