#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#endif

#if defined( _WIN32) || defined(_WIN64)  
#define _WIN
#define CLOSE 0
#else
#define CLOSE 1
#endif
#define OPEN 1

#define _RESORT_ARRAY_				CLOSE
#define _CYCLE_CROSS_LINK_			CLOSE
#define _BINARY_SEARCH_				CLOSE
#define _IS_BIG_ENDIAN_				CLOSE
#define _FIND_CON_NUM_				CLOSE
#define _LESS_CODE_BEAUT_PIC_		CLOSE
#define _TEST_EXPLICIT_				CLOSE
#define _TEST_STRTOK_				CLOSE
#define _SUM_NUM_BIN_1_				CLOSE
#define _SECOND_NUM_				CLOSE
#define _TEST_SIZEOF_				CLOSE
#define _FIND_SECOND_NUM_			CLOSE
#define _DECOMPOSE_SUCCESSIVE_NUM_	CLOSE
#define _FIND_X_IN_ARR_				CLOSE
#define _NUMSTR_TO_NUMARRAY_		CLOSE
#define _EXCHANGE_A_B_POS_			CLOSE
#define _JOSEPH_					CLOSE	
#define _EIGHT_QUEEN_				CLOSE
#define _HORSE_						1

#endif //_MAIN_H_