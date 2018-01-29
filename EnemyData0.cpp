#include "EnemyData0.h"


EnemyData0::EnemyData0( ) {
	_data = {
		"                                         C               E         C                     C             E            E                                 "
		"                                          C      A       E       EB C        A        B   C        A   E    A  D   BE        B                        "
		"                                           C        D    E       E   C            D        C           E                                              "
		"                                            C    A           E   E    C  B   A         E    C B    A   E  A            CCCC                           "
		"                                             C               E         C     E         E   E C         E            E              2                  "
		"                                                 A       E              C  B AE            E  C    A     A     D    E    B                            "
		"                                                         E               C     E           E   C     E                                                "
		"                                               A         E       E        C    AE D        E    C   E     A                                           "
		"                                                             E   E         C     E     E   E     C E                E                                 "
		"                                         C     A             E   E          C  A  E    E          C     D  A   D    E                                 "
		"                                          C              E       E           C                     C                               0                  "
		"                                           C   A    D   BE       E            CA  D           B    DC       A      B   CCCC  B                        "
		"                                          C              E       E           C                     C                                                  "
		"                                         C     A             E   E          C  A  E    E          C     D  A        E                                 "
		"                                                             E   E         C     E     E   E     C E           D    E                                 "
		"                                               A         E       E        C    AE D        E    C   E     A                                           "
		"                                                         E               C     E           E   C     E                             3                  "
		"                                                 A       E              C  B AE            E  C    A     A          E    B                            "
		"                                             C               E         C     E         E   E C         E       D    E                                 "
		"                                            C    A           E   E    C  B   A         E    C B    A   E  A            CCCC                           "
		"                                           C        D    E       E   C            D        C           E                                              "
		"                                          C      A       E       EB C        A        B   C        A   E    A      BE        B                        "
		"                                         C               E         C                     C             E       D    E                                 "
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
