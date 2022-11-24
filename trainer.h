#include"admin.h"
class trainer : public healthCare
{
	double fees;
	char exp[400];
	int count;
	public:
		trainer();
		trainer(double,char* ,char* ,int ,char* ,char* ,char* ,int);
		void setfees(double);
		void setexp(char*);
		double getfees();
		char* getexp();
		void registertrainer(trainer&);
		bool logintrainer(int);
		void displaytrainer();
		void searchtrainer(int);
		void updateTrainer(int);
		void deleteTrainer(int);
		virtual void display();
};
