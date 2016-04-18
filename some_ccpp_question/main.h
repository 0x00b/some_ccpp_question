#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef _WIN32  
#define CLOSE 0
#else
#define CLOSE 1
#endif
#define OPEN 1

#define _RESORT_ARRAY_			CLOSE
#define _CYCLE_CROSS_LINK_		CLOSE
#define _BINARY_SEARCH_			CLOSE
#define _IS_BIG_ENDIAN_			CLOSE
#define _FIND_CON_NUM_			CLOSE
#define _LESS_CODE_BEAUT_PIC_	CLOSE
#define _TEST_EXPLICIT_			CLOSE
#define _TEST_STRTOK_			CLOSE
#define _SUM_NUM_BIN_1_			CLOSE
#define _SECOND_NUM_			CLOSE
#define _TEST_SIZEOF_			OPEN
#define _FIND_SECOND_NUM_		CLOSE


#endif //_MAIN_H_