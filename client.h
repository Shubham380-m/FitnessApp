#include"healthCare.h"
class healthClient : public healthCare
{
	double height;
	double weight;
	int count;
	public:
		healthClient();
		healthClient(double,double,char*,int,char* ,char*,char*,int);
		void setweight(double);
		void setheight(double);
		double getweigh();
		double getheight();
		void caloriesCal(double,double,int,char*);
		void heightWeight(double,double,char*);
		void subscribed();
		void registerclient(healthClient&);
		bool login(int);
		void Displayclient();
		void searchClient(int);
		void updateClient(int);
		void deleteclient(int);
		virtual void display();
		
};
