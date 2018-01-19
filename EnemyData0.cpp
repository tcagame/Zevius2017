#include "EnemyData0.h"



EnemyData0::EnemyData0( ) {
	_data = {
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
		"              B           A                                                                                                                           "
		"              C           A                                                                                                                           "
		"              D           A                                                                                                                           "
		"              E           A                                                                                                                           "
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
		"                          A                                                                                                                           "
	};
}


EnemyData0::~EnemyData0( ) {

}

std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > EnemyData0::getEnemyData(  ) {
	return _data;
}
