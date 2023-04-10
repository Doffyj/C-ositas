#include <stdio.h>

int	main(void)
{
	char	conwayday[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int inday, inmonth, iny;
	printf("Introduce the date (dd/mm/yy):\n");
	scanf("%d/%d/%d", &inday, &inmonth, &iny);
	int	ancdayz = ((iny / 100) % 4);
	switch(ancdayz)
	{
		case 0:
			ancdayz = 2;
			break;
		case 1:
			ancdayz = 0;
			break;
		case 2:
			ancdayz = 5;
			break;
		case 3:
			ancdayz = 3;
			break;
	}
	int last2 = iny - ((iny / 100) * 100);
	int	step1 =  last2 / 12;
}