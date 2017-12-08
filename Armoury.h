#pragma once
#include "smart_ptr.h"
#include <list>

PTR( PlayerShot );

class Armoury {
public:
	Armoury(  );
	virtual ~Armoury( );
public:
	void update( );
	void draw( ) const;
	void addShot( PlayerShotPtr shot );
private:
	std::list< PlayerShotPtr > _shots;
};

