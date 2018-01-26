#include "EnemyData0.h"


EnemyData0::EnemyData0( ) {
	_data = {
		"                                             C              E                                                                                         "
		"                                             C      A       E         C    B                                                                          "
		"                                             C              E         C                                                                               "
		"                                             C      A  D              C                                                                               "
		"                                             C         D              C                                                                               "
		"                                             C      A       E         CB                                                                              "
		"                                             C              E         C                                                                               "
		"                                             C    A         E         C                                                                               "
		"                                             C         D              C                                                                               "
		"                                             C    A    D              C                                                                               "
		"                                             C              E         C                                                                               "
		"                                             C    A         E    B    C                                                                               "
		"                                             C              E         C                                                                               "
		"                                             C    A    D              C                                                                               "
		"                                             C         D              C                                                                               "
		"                                             C    A         E         C                                                                               "
		"                                             C              E         C                                                                               "
		"                                             C  A           E         CB                                                                              "
		"                                             C         D              C                                                                               "
		"                                             C  A      D              C                                                                               "
		"                                             C              E         C                                                                               "
		"                                             C  A           E         C    B                                                                          "
		"                                             C              E         C                                                                               "
	};
}



EnemyData0::~EnemyData0( ) {

}

std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > EnemyData0::getEnemyData(  ) {
	return _data;
}
