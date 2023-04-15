#include <stdio.h>
#include <stdlib.h>

int	ft_isleapy(int y)
{
	if (y % 4 == 0)
	{
		if (y % 400 == 0 || y % 100 != 0)
			return (1);
		
	}
	return (0);
}

int	ft_getmonthdd(int month, int year)
{
	if (month != 1 && month != 2)
	{
		if (month % 2 == 0)
			return month;
		else if (month > 6)
			return (month - 4);
		else
			return (month + 4);
	}
	if (month == 1)
		return (3 + ft_isleapy(year));
	return (28 + ft_isleapy(year));
}

int	main(void)
{
	char	conwayday[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int inday, inmonth, iny;
	printf("Introduce the date (dd/mm/yy):\n");
	scanf("%d/%d/%d", &inday, &inmonth, &iny);
	int monthdd = ft_getmonthdd(inmonth, iny);
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
	int diffdays = abs(monthdd - inday);
	while (diffdays + lastep > 7)
		diffdays = diffdays - 7;
	printf("The day %d/%d/%d fell on a %s", inday,inmonth,iny,conwayday[diffdays + lastep]);
}