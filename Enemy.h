#pragma once
#include "Character.h"
class Enemy : public Character {
public:
	Enemy( const Vector& pos, double radius, int score );
	virtual ~Enemy( );
public:
	bool isFinished( );
	void erase( );
private:
	bool _erase;

};

