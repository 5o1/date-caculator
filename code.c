#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int time0,second,minute,hour,day,month,year,week;
	int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char *wd[7]={"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednsday"};
	
	while(1)
	{
		time0=time(0);
		
		//除法计算时间 
		second=time0%60;
		minute=time0/60%60;
		hour=(time0/3600+8)%24;
		day=time0/86400;
		
		//除法计算星期,1970年1月1日是周四	
		week=day%7;
		
		//模拟除法计算年份 
		year=1970;	
		while(day/365!=0)
		{
			if(year%400==0||(year%100!=0&&year%4==0))
				day-=366;
			else
				day-=365;
			year++;
		}
			
		//模拟除法计算月份&日期 
		month=1;
		while((day+1)>(md[month-1]))
		{
			if(month==2&&(year%400==0||(year%100!=0&&year%4==0)))
				day-=md[month-1]-1;
			else
				day-=md[month-1];
			month++;
		}
		//输出，变量day表示“从1970年1月1日【过了】day天“，因此day+1 
		system("cls");
		printf("%.4d/%.2d/%.2d %.2d:%.2d:%.2d Today is %s.",year,month,day+1,hour,minute,second,wd[week]);
		while(time(0)-time0<1);
	}
}
