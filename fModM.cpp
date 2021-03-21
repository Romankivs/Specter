#include "fModM.h"

static int F0;
static int F1;
static int M;

void InitFmodM(const int firstElement, const int secondElement, const int Key)
{
	F0 = firstElement;
	F1 = secondElement;
	M = Key;
}

int r()
{
	int t = F0 + F1;
	F0 = F1 % M;
	F1 = t;
	return F0;
}