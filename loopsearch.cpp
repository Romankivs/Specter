#include "fModM.cpp"

int looplength(const int firstElement, const int secondElement, const int Key)
{
	if (Key == 1)
		return 1;
	int c = 1;
	int firstTemp = r();
	int secondTemp = r();
	while (firstTemp != firstElement || secondTemp != secondElement)
	{
		firstTemp = secondTemp;
		secondTemp = r();
		c++;
	}
	return c;
}