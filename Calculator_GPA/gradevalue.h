#ifndef gradevalue
#define gradevalue

#include "global.h"

float getGradeValue(int nilai){
	switch (nilai){
		case A :
			return 4.0;
		case Am :
			return 3.7;
		case Bp :
			return 3.3;
		case B :
			return 3.0;
		case Bm :
			return 2.7;
		case Cp :
			return 2.3;
		case C :
			return 2.0;
		case D :
			return 1.0;
		case E :
			return 0.0;
	}
	return -1;
}

#endif
