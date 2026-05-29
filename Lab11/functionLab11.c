#include <stdio.h>
#include <stdarg.h>
#include "functionLab11.h"

int sum(int count, ...)
{
	int result = 0;
	va_list arg;
	va_start(arg, count);
	int i;
	for(i = 0; i < count; i++)
	{
		result += va_arg(arg, int);
	}
	va_end(arg);
	return result;
}

int max(int count, ...)
{
	va_list arg;
	va_start(arg, count);
	int result = va_arg(arg, int);
	int i;
	for (i = 1; i < count; i++)
	{
		int a = va_arg(arg, int);
		if (a > result)
		{
			result = a;
		}
	}
	va_end(arg);
	return result;
}

int min(int count, ...)
{
	va_list arg;
	va_start(arg, count);
	int result = va_arg(arg, int);
	int i;
	for (i = 1; i < count; i++)
	{
		int a = va_arg(arg, int);
		if (a < result)
		{
			result = a;
		}
	}
	va_end(arg);
	return result;
}

double average(int count, ...)
{
	double summ = 0;
	va_list arg;
	va_start(arg, count);
	int i;
	for(i = 0; i < count; i++)
	{
		summ += va_arg(arg, int);
	}
	va_end(arg);
	double result = summ/count;
	return result;
}
