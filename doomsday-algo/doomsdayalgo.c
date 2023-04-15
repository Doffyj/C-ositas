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

int	ft_calcdd(int iny, int ancday)
{
	int last2 = iny - ((iny / 100) * 100);
	int	step1 =  last2 / 12;
	int	step2 = last2 - (step1 * 12);
	int	step3 = step2 / 4;
	return (step1 + step2 + step3 + ancday);
}

void	ft_weekday()
{
	char	conwayday[7][9] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int inday, inmonth, iny; //input values
	int monthdd, ancday, lastep, diffdays;
	printf("Introduce the date (dd/mm/yy):\n");
	scanf("%d/%d/%d", &inday, &inmonth, &iny);
	monthdd = ft_getmonthdd(inmonth, iny);
	ancday = ((iny / 100) % 4);
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
	lastep = ft_calcdd(iny, ancday) % 7;
	diffdays = abs(monthdd - inday);
	while (diffdays + lastep > 7)
		diffdays = diffdays - 7;
	printf("The day %d/%d/%d fell on a %s\n", inday,inmonth,iny,conwayday[diffdays + lastep]);
}

int main(void)
{
	int	i = 1;
	while(i == 1)
	{
		ft_weekday();
		printf("Send 1 to calculate another:\n");
		scanf("%d", &i);
	}
	return (0);
}