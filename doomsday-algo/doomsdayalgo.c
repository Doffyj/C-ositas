#include <stdio.h>

int	main(void)
{
	char	conwayday[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int inday, inmonth, iny;
	printf("Introduce the date (dd/mm/yy):\n");
	scanf("%d/%d/%d", &inday, &inmonth, &iny);
	
	int	ancday = ((iny / 100) % 4);
	switch(ancday)
	{
		case 0:
			ancday = 2;
			break;
		case 1:
			ancday = 0;
			break;
		case 2:
			ancday = 5;
			break;
		case 3:
			break;
	}
	int last2 = iny - ((iny / 100) * 100);
	int	step1 =  last2 / 12;
	int	step2 = last2 - (step1 * 12);
	int	step3 = step2 / 4;
	int lastep = step1 + step2 + step3 + ancday;
	while (lastep > 6)
		lastep = lastep - 7;
	printf("The day %d/%d/%d fell on a %s", inday,inmonth,iny,conwayday[lastep]);
}