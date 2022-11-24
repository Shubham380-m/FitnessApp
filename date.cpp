#include"date.h"
date::date()
{
	this->dates=0;
	this->month=0;
	this->year=0;
}
date::date(int d,int m,int y)
{
	this->dates=d;
	this->month=m;
	this->year=y;
}
void date::setdate(int d)
{
	this->dates=d;
}
void date::setmonth(int m)
{
	this->month=m;
}
void date::setyear(int y)
{
	this->year=y;
}
int date::getdate()
{
	return this->dates;
}
int date::getmonth()
{
	return this->month;
}
int date::getyear()
{
	return this->year;
}
int date::operator-(date d)
{
	date temp;
	temp.year=this->year-d.year;
	temp.month=this->month-d.month;
	this->dates=this->dates+temp.month*30;
	
	temp.dates=this->dates-d.dates;
	int x= temp.dates;
	
}
void  date::operator=(date d)
{
	this->dates=d.dates;
	this->month=d.month;
	this->year=d.year;
}
void date::ddisplay()
{
	cout<<this->dates;
	cout<<"/"<<this->month;
	cout<<"/"<<this->year;
}
