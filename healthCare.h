#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
class healthCare
{
	//Admin
	char name[40];
	int id;
	char password[20];
	char contact[10];
	char gender[20];
	int age;

	public:
		healthCare();
		healthCare(char*,int,char*,char*,char*,int);
		void setname(char*);
		void setid(int);
		void setpass(char*);
		void setcontact(char*);
		void setgender(char*);
		void setage(int);
	//	void setMediCond(char*);
		char* getname();
		int getid();
		char* getpass();
		char* getcontact();
		char* getgender();
		int getage();
		virtual void display();
};
