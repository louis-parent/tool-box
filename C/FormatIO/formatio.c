#include "formatio.h"
#include <stdio.h>

void setFormat(const char* style, const char* color)
{
	printf("%s%c%s%c%s%c", FORMAT_ESCAPE_STRING, 
						   FORMAT_START_CHAR, 
						   style, 
						   FORMAT_SPLITTER_CHAR, 
						   color, 
						   FORMAT_END_CHAR);
}

void resetFormat()
{
	printf("%s%c%s%c", FORMAT_ESCAPE_STRING, 
					   FORMAT_START_CHAR, 
					   DEFAULT_COLOR, 
					   FORMAT_END_CHAR);
}

int println(const char* str)
{
	return printf("%s\n", str);
}

int printUnderline(size_t length, char lineStyle)
{
	char line[length+1];
	
	for(size_t i = 0; i < length; i++)
	{
		line[i] = lineStyle;
	}
	line[length] = '\0';
	
	return printf("%s\n", line);
}

int printEmptyLine()
{
	return printf("\n");
}
