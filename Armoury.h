#pragma once
#include "smart_ptr.h"
#include <list>

PTR( PlayerShot );
PTR( Military );
PTR( Enemy );

class Armoury {
public:
	Armoury( );
	virtual ~Armoury( );
public:
	void update( MilitaryPtr military );
	void draw( ) const;
	void addShot( PlayerShotPtr shot );
private:
	std::list< PlayerShotPtr > _shots;
	MilitaryPtr _military;
};

