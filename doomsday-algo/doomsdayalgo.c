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
		case '0':
			ancdayz = 
	}
}