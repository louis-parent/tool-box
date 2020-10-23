#ifndef __UNIT_TEST__
#define __UNIT_TEST__

#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#define TEST_CALLBACK(name) TestResult (*name)(void)

#define PASSED_STRING "PASSED"
#define FAILED_STRING "FAILED"

#define MAX_TEST_SET_SCORE_LENGTH 8

typedef struct TestResult
{
	unsigned int passed;
	unsigned int failed;
} TestResult;

void testSet(const char* setLabel, int count, ...);
bool test(const char* label, bool assertion);

bool arrayEquals(const void* array1, const void* array2, size_t length, size_t elementSize);
bool unsignedIntegerEquals(unsigned long uint1, unsigned long uint2);
bool integerEquals(long int1, long int2);
bool floatingEquals(double float1, double float2);

#endif
