#ifndef __FORMAT_IO__
#define __FORMAT_IO__

#include <stdlib.h>

#define FORMAT_ESCAPE_STRING "\033"
#define FORMAT_START_CHAR '['
#define FORMAT_SPLITTER_CHAR ';'
#define FORMAT_END_CHAR 'm'

#define DEFAULT_STYLE "0"
#define BOLD "1"

#define DEFAULT_COLOR "0"
#define RED "31"
#define GREEN "32"
#define YELLOW "33"
#define BLUE "34"
#define MAGENTA "35"
#define CYAN "36"

void setFormat(const char* style, const char* color);
void resetFormat();

int println(const char* str);
int printUnderline(size_t length, char lineStyle);
int printEmptyLine();

#endif
