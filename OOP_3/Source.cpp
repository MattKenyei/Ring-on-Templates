#include "Ring.h"
void loopRing()
{
	Ring<double> myr;
	int choise;
	while (true)
	{
		printf("1 - add element; 2 - delete element; 3 - go right; 4 - go left; 5 - find element; 6- exit: ");
		do
		{
			scanf_s("%i", &choise);

		} while (choise < 1 || choise>6);
		double tmp;
		switch (choise)
		{
		case 1:
			printf("Input a new element: ");
			scanf_s("%lf", &tmp);
			myr.push(tmp);
			break;
		case 2:
			tmp = myr.pull();
			printf("Deleted element: %lf\n", tmp);
			break;
		case 3:
			myr.onRight();
			break;
		case 4:
			myr.onLeft();
			break;
		case 5:
			printf("Input wanted element: ");
			scanf_s("%lf", &tmp);
			myr.find(tmp);
			break;
		case 6:
			myr.clr();
			return;
		}
		myr.print();
		printf("\n");
	}
}

int main()
{
	loopRing();
	return 0;
}