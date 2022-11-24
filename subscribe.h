#include"date.h"
class subscribe
{
	date subscDate;
	date endDate;
	char Cname[20];
	char tname[20];
	int tid;
	int cid;
	double tfees;
	int totaldays;
	int totalfees;
	int count;
	public:
		subscribe();
		void setstartDate(date);
		void setEndDate(date);
		void setcname(char*);
		void settname(char*);
		void settid(int);
		void setcid(int);
		void setfees(double);
		date getEndDate();
		date getStartDate();
		char* getcname();
		char* gettname();
		int gettid();
		int getcid();
		double getfees();
		int gettrainingdays();
		int gettotalfees();
		void trainerList(int);
		void subTrainer(subscribe&);
		void trainingdays(int);
		void trainingfees(int);
		void unsubTrainer(int);
		void displayallsub();
		void displaySub(int);
		void display();
	
};
