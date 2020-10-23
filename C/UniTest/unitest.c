#define _GNU_SOURCE

#include "unitest.h"
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "formatio.h"

/*
 * Utils
 */
static int labeledPrintLn(const char* label, const char* value)
{
	return printf("%s : %s\n", label, value);
}

static void printTestSetHeader(const char* setLabel)
{
	setFormat(BOLD, CYAN);
	int length = labeledPrintLn(setLabel, "");
	printUnderline(length-1, '-');
}

static void printTestSetFooter(TestResult globalResult)
{
	char testSetScore[MAX_TEST_SET_SCORE_LENGTH];
	unsigned int passedTests = globalResult.passed;
	unsigned int totalTests = passedTests + globalResult.failed;
	bool allTestsPassed = unsignedIntegerEquals(passedTests, totalTests);
	
	sprintf(testSetScore, "%3u/%-3u", passedTests, totalTests);
	setFormat(DEFAULT_STYLE, allTestsPassed ? GREEN : RED);
	labeledPrintLn(testSetScore, allTestsPassed ? PASSED_STRING : FAILED_STRING);
	printEmptyLine();
}

static void signalHandler(int signalId)
{
	setFormat(BOLD, RED);
	fflush(stdout);
	SIG_DFL(signalId);
}

static unsigned int standardSignalCount = 6;
static int signals[] = {SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM};

static void setHandlerForAllSignal(void (*handler)(int))
{
	for(unsigned int i = 0; i < standardSignalCount; i++)
	{
		signal(signals[i], handler);
	}
}

/*
 * Tests
 */
void testSet(const char* setLabel, int count, ...)
{	
	setHandlerForAllSignal(signalHandler);
	printTestSetHeader(setLabel);
	
	TestResult globalResult = {0, 0};

	va_list args;	
	va_start(args, count);
	
	for(int i = 0; i < count; i++)
	{
		TestResult currentResult = va_arg(args, TEST_CALLBACK())();
		globalResult.passed += currentResult.passed;
		globalResult.failed += currentResult.failed;
	}
	
	va_end(args);
	
	printTestSetFooter(globalResult);
	setHandlerForAllSignal(SIG_DFL);
}

bool test(const char* label, bool assertion)
{
	setFormat(DEFAULT_STYLE, assertion ? GREEN : RED);
	labeledPrintLn(label, assertion ? PASSED_STRING : FAILED_STRING);
	return assertion;
}

bool arrayEquals(const void* array1, const void* array2, size_t length, size_t elementSize)
{
	bool allEquals = true;
	unsigned int i = 0;
	
	while(i < length * elementSize && allEquals)
	{
		allEquals &= ((const char*) array1)[i] == ((const char*) array2)[i];
		i++;
	}
	
	return allEquals;
}

bool unsignedIntegerEquals(unsigned long uint1, unsigned long uint2)
{
	return uint1 == uint2;
}

bool integerEquals(long int1, long int2)
{
	return int1 == int2;
}

bool floatingEquals(double float1, double float2)
{
	return float1 == float2;
}
