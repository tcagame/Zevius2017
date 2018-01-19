#include "EnemyData0.h"


EnemyData0::EnemyData0( ) {
	_data = {
		"                          A         C              CB                                                                                                 "
		"                           A         C              CB                                                                                                "
		"                            A         C              CB                                                                                               "
		"                             A         C              CB                                                                                              "
		"                              A         C              CB                                                                                             "
		"                               A         C              CB                                                                                            "
		"                                A         C              CB                                                                                           "
		"                                 A         C              CB                                                                                          "
		"                                  A         C             BC                                                                                          "
		"                                   A         C           B  C                                                                                         "
		"                                    A         C         B    C                                                                                        "
		"                                     A         C       B      C                                                                                       "
		"                                      A         C     B        C                                                                                      "
		"                                       A         C   B          C                                                                                     "
		"                                        A         C B            C                                                                                    "
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
