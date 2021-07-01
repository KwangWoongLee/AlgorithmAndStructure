#pragma once
#pragma warning(disable: 4996)
#include "stdafx.h"


static char* GetReverseStringBySTL(const char* str)
{
	auto newStr = std::string(str);
	std::reverse(newStr.begin(), newStr.end());

	char* pReturn = new char[newStr.size() + 1];
	
	strcpy(pReturn, newStr.c_str());

	return pReturn;
}

static char* GetReverseString(const char* str)
{
	auto len = strlen(str);

	char* pReturn = new char[len+1];

	for (int i = len - 1; i >= 0; --i)
	{
		pReturn[len -1 - i] = str[i];
	}

	pReturn[len] = '\0';

	return pReturn;
}