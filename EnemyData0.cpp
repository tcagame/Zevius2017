#include "EnemyData0.h"


EnemyData0::EnemyData0( ) {
	_data = {
		"                                         C               E         C     C        D              C    C        D    E         C                       "
		"                                          C      A       E        BC     C   A    D   B          C    C     A  D   BE        BC                       "
		"                                           C             E    A    C     C        D         A    C    C                       C                       "
		"                                            C    A  D         A    C     C   A         E         C    C   A                   C                       "
		"                                             C      D         A    C     C             E    A    C    C        D    E         C    2                  "
		"                                                 A       E    B    C     C   A    D         B    C    C  A     D    E    B    C                       "
		"                                                         E         C     C        D         A    C    C                       C                       "
		"                                               A         E         C     C     A  D              C    C   A                   C                       "
		"                                                    D              C     C             E    A    C    C        D    E         C                       "
		"                                         C     A    D              C     C     A       E         C    C    A   D    E         C                       "
		"                                          C              E    A    C     C        D         A    C    C                       C    0                  "
		"                                           C   A        BE    A    C     C     A  D             BC    C     A      B         BC                       "
		"                                          C              E    A    C     C        D         A    C    C                       C                       "
		"                                         C     A    D              C     C     A       E         C    C    A   D    E         C                       "
		"                                                    D              C     C             E    A    C    C        D    E         C                       "
		"                                               A         E         C     C     A  D              C    C   A                   C                       "
		"                                                         E         C     C        D         A    C    C                       C    3                  "
		"                                                 A       E    B    C     C   A    D         B    C    C  A     D    E    B    C                       "
		"                                             C      D         A    C     C             E    A    C    C        D    E         C                       "
		"                                            C    A  D         A    C     C   A         E         C    C   A                   C                       "
		"                                           C             E    A    C     C        D         A    C    C                       C                       "
		"                                          C      A       E        BC     C   A    D   B          C    C     A  D   BE        BC                       "
		"                                         C               E         C     C        D              C    C        D    E         C                       "
	};
}
//EnemyData0::EnemyData0( ) {
//	_data = {
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                           2                                                                                                          "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                           0                                                                                                          "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                           3                                                                                                          "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//		"                                                                                                                                                      "
//	};
//}



EnemyData0::~EnemyData0( ) {

}

std::array< char, MAP_WIDTH_NUM * MAP_HEIGHT_NUM + 1 > EnemyData0::getEnemyData(  ) {
	return _data;
}
