#include"trainer.h"
class date
{
	int dates;
	int month;
	int year;
	public:
		date();
		date(int,int,int);
		void setdate(int);
		void setmonth(int);
		void setyear(int);
		int getdate();
		int getmonth();
		int getyear();
		int operator-(date);
		void operator=(date);
		void ddisplay();
};
