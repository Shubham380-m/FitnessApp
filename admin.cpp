#include"admin.h"
#include<fstream>
admin::admin() : healthCare()
{
	int count=0;
	ifstream myfile("Acount.txt");
	if(!myfile)
	{
		ofstream rcount("Acount.txt");
		rcount<<count;
		rcount.close();	
	}
	else
	{
		myfile>>count;
		myfile.close();	
	}
	
}
admin::admin(char* nm,int id,char* pass,char* con,char* gen,int ag) : healthCare(nm,id,pass,con,gen,ag)
{
	
}
/*void admin::settotcol(double tc)
{
	this->totalcol=tc;
}
double admin::gettotalcol()
{
	return this->totalcol;
}*/

void admin::Adminregister(admin&h1)
{
	
	ifstream myfile2("Acount.txt");
	int count;
	myfile2>>count;
	myfile2.close();
	
	
	count++;
	ofstream myfile1("Acount.txt");
	myfile1<<count;
	myfile1.close();
	
	
	ofstream myfile("admin.dat",ios_base::binary | ios_base::app);
	myfile.write((char*)&h1,sizeof(h1));
	myfile.close();



	cout<<"===============| !Registration sucessfull! |=============="<<endl;
		
}
bool admin::login(int nid)
{
	char pass[20];
	bool found=false;
	int c=0;
	ifstream myfile("admin.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"File not found"<<endl;
	}
	else
	{
		admin h1;
		myfile.read((char*)&h1,sizeof(h1));
		do
		{
			
			if((nid == h1.getid()))
			{
				cout<<"\nEnter password"<<endl;
				cin>>pass;
				if(strcmp(h1.getpass(),pass)==0)
				{
					c=1;
					break;
				}
				else
				{
					cout<<"Please enter correct password"<<endl;
					c=0;
					return false;
				}
				myfile.read((char*)&h1,sizeof(h1));
			}
			else
			{
				c=0;
			}
				myfile.read((char*)&h1,sizeof(h1));	
		}while(!myfile.eof());
		myfile.close();	
	}
	
	if(c==1)
	{
		found=true;
		return true;
	}
	else
	{
		cout<<"**Please enter correct userId pass**"<<endl;
		return false;
	}
}
void admin::searchAdmin(int cid)
{
	ifstream myfile("admin.dat",ios_base::binary);
 	if(!myfile)
	{
		cout<<"file does not exist"<<endl;
		return;
	}
	else
	{
		bool found=false;
		admin h1;
		myfile.read((char*)&h1,sizeof(h1));
		cout<<"\n\t\t========================================================================================";
		cout<<"\n\t\t";
		cout<<"|NAME            |  ID        |  PASSWORD          |  CONTACT     |  GENDER     |  AGE |";
		cout<<"\n\t\t========================================================================================\n";
	 do{
			
			if(cid == h1.getid())
			{
				found=true;
			//	cout<<"record found"<<endl;
				h1.display();
				break;
			}
			myfile.read((char*)&h1,sizeof(h1));
		}while(!myfile.eof());
		if(!found)
		{
			cout<<"Record not found"<<endl;
		}
		myfile.close();
	}
}
void admin::updateadmin(int id)
{
	ifstream myfile1("acount.txt");
	int count;
	myfile1>>count;
	myfile1.close();
	
	admin *p = new admin[count];
	ifstream myfile("admin.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"\nFile doesnt exist";
		return;
	}
	else
	{
		bool found = false;
		admin h1;
		int i=0;
		myfile.read((char *)&h1,sizeof(h1));
		do
		{				
			//e.Display();
			if(h1.getid() == id)
			{
				found = true;
				cout<<"\nRecord Found";
				int choice=0;
				while(choice!=7)
				{
					cout<<"\n\tpress 1. to change name"<<endl;
					cout<<"\n\tpress 2. to change password"<<endl;
					cout<<"\n\tpress 3. to change age"<<endl;
					cout<<"\n\tpress 4. change contact number"<<endl;
					cout<<"\n\tpress 7. Previous menu"<<endl;
					cin>>choice;
					switch(choice)
					{
						case 1:
						{
							cout<<"\nEnter new name";
							char name[20];
							cin>>name;
							h1.setname(name);	
						}
						break;
						case 2:
						{
							cout<<"\n Change password"<<endl;
							char pass[30];
							cin>>pass;
							h1.setpass(pass);
						}
						break;
						case 3:
						{
							cout<<"\n Enter new age"<<endl;
							int age;
							cin>>age;
							h1.setage(age);	
						}
						break;
						case 4:
						{
							cout<<"\n Enter new contact number"<<endl;
							char cont[15];
							cin>>cont;
							h1.setcontact(cont);	
						}
						break;
						case 7:
						break;
						default:
						cout<<"Invalid input"<<endl;
						break;	
					}	
				}
			}
			p[i] = h1;
			i++;
			myfile.read((char *)&h1,sizeof(h1));			
			
		}while(!myfile.eof());
		myfile.close();
		
		for(int i=0;i<count;i++)
		{
			p[i].display();
		}
		
		if(!found)
		{
			cout<<"\nRecord not found";
			return;
		}
		else
		{
			ofstream myfile2("admin.dat",ios_base::binary);
			for(int i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
		}
	}
}
void admin::deleteadmin(int id)
{
	ifstream file("acount.txt");
	int count;
	file>>count;
	file.close();
	
	admin *p=new admin[count];
	ifstream myfile("admin.dat",ios::binary);
	if(!myfile)
	{
		cout<<"\nFile does not exist"<<endl;
		return;
	}
	else
	{
		int i=0;
		bool found=false;
		admin h1;
		myfile.read((char*)&h1,sizeof(h1));
		do{
			if(h1.getid() == id)
			{
				found=true;
				
			}
			else
			{
				p[i]=h1;
				i++;	
			}
		
			myfile.read((char*)&h1,sizeof(h1));
		}while(!myfile.eof());
		myfile.close();
		
		if(!found)
		{
			cout<<"\nNo such record found of this ID"<<endl;
			return;
		}
		else
		{
			count--;
			ofstream myfile1("acount.txt");
			myfile1<<count;
			myfile1.close();
			ofstream myfile2("admin.dat",ios_base::binary);
			for(i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
			cout<<"\nProfile sucessfully deleted"<<endl;
			
		}
	}
	
}
void admin::displayalladmin()
{
	ifstream myfile("admin.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"file does not exist"<<endl;
		return;
	}
	else
	{
		admin c1;
		myfile.read((char*)&c1,sizeof(c1));
		cout<<"\n\t\t=============================================================";
		cout<<"\n\t\t";
		cout<<"|  NAME       |  ID   |  PASSWORD  |  CONTACT  |  GENDER  |  AGE  |";
		cout<<"\n\t\t=============================================================";
		do{	
			
			c1.display();
			myfile.read((char*)&c1,sizeof(c1));
		
		  }while(!myfile.eof());
	
		myfile.close();	
	}	
}
void admin::display()
{
/*	cout<<"\n\t\t========================================================================================";
	cout<<"\n\t\t";
	cout<<"|NAME            |  ID        |  PASSWORD          |  CONTACT     |  GENDER     |  AGE |";
	cout<<"\n\t\t========================================================================================\n";*/
	healthCare::display();
	cout<<"\n\t\t----------------------------------------------------------------------------------------"<<endl;
}
