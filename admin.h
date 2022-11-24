#include "client.h"
class admin : public healthCare
{
	int count;
	public:
		admin();
		admin(char*,int,char*,char*,char* ,int );
		void Adminregister(admin&);
		bool login(int);
		void displayalladmin();
		void searchAdmin(int);
		void updateadmin(int);
		void deleteadmin(int);
		virtual void display();
		//void registertrainer(trainer&);
};
