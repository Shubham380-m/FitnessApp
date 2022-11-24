#include"healthCare.h"
//////////////////////////////////////////////
healthCare::healthCare()
{
	strcpy(this->name,"NULL");
	this->id=00;
	strcpy(this->password,"NULL");
	strcpy(this->contact,"NULL");
	strcpy(this->gender,"NULL");
	this->age=00;
}
healthCare::healthCare(char* nm,int nid,char* pass,char* con,char* gen,int ag)
{
	strcpy(this->name,nm);
	this->id=nid;
	strcpy(this->password,pass);
	strcpy(this->contact,con);
	strcpy(this->gender,gen);
	this->age=ag;
	
}
void healthCare::setname(char* nm)
{
	strcpy(this->name,nm);
}
void healthCare::setpass(char* pass)
{
	strcpy(this->password,pass);
}
void healthCare::setid(int nid)
{
	this->id=nid;
}
void healthCare::setcontact(char* con)
{
	strcpy(this->contact,con);
}
void healthCare::setgender(char* gen)
{
	strcpy(this->gender,gen);
}
void healthCare::setage(int ag)
{
	this->age=ag;
}

char* healthCare::getname()
{
	return this->name;
}
char* healthCare::getpass()
{
	return this->password;
}
int healthCare::getid()
{
	return this->id;
}
char* healthCare::getcontact()
{
	return this->contact;
}
char* healthCare::getgender()
{
	return this->gender;
}
int healthCare::getage()
{
	return this->age;
}
void healthCare::display()
{

//	cout<<"\t\n|"<<this->name<<"\t|"<<this->id<<"\t|"<<this->password<<"\t|"<<this->contact<<"\t|"<<this->gender<<"\t|"<<this->age<<"\t|"<<endl;
	cout<<setw(17)<<"|"<<name<<setw(10)<<"|"<<id<<setw(10)<<"|"<<password<<setw(10)<<"|"<<contact<<setw(10)<<"|"<<gender<<setw(10)<<"|"<<age<<"    |";


}
