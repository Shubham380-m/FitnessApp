#include"trainer.h"
trainer::trainer()
{
	strcpy(this->exp,"NULL");
	this->fees=00;
	
	int count=0;
	ifstream myfile("tcount.txt");
	if(!myfile)
	{
		ofstream rcount("tcount.txt");
		rcount<<count;
		rcount.close();	
	}
	else
	{
		myfile>>count;
		myfile.close();	
	}
	
}
trainer::trainer(double fee,char* exp,char* nm,int id,char* pass,char* con,char* gen,int ag) : healthCare(nm,id,pass,con,gen,ag)
{
	strcpy(this->exp,exp);
	this->fees=fee;
}
void trainer::setexp(char* exper)
{
	strcpy(this->exp,exper);
}
void trainer::setfees(double fee) 
{
	this->fees=fee;
}
char* trainer::getexp()
{
	return this->exp;
}
double trainer::getfees()
{
	return this->fees;
}
void trainer::registertrainer(trainer &h1)
{

		
	ifstream myfile2("tcount.txt");
	int count;
	myfile2>>count;
	myfile2.close();
	
	
	count++;
	ofstream myfile1("tcount.txt");
	myfile1<<count;
	myfile1.close();
	
	
	ofstream myfile("trainer.dat",ios_base::binary | ios_base::app);
	myfile.write((char*)&h1,sizeof(h1));
	myfile.close();



	cout<<"===============| !Registration sucessfull! |=============="<<endl;

}
bool trainer::logintrainer(int nid)
{
	char pass[20];
	bool found=false;
	int c=0;
	ifstream myfile("trainer.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"File not found"<<endl;
	}
	else
	{
		trainer h1;
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
		return false;
	}
}
void trainer::displaytrainer()
{
	ifstream myfile("trainer.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"No trainer found"<<endl;
		return;
	}
	else
	{
		trainer t1;
		myfile.read((char*)&t1,sizeof(t1));
		cout<<"\n\t\t=====================================================================================================";
		cout<<"\n\t\t";
		cout<<"|NAME             |  ID         |  PASSWORD          |  CONTACT      |  GENDER      |  AGE  |   FEES   |   EXP  |";
		cout<<"\n\t\t=====================================================================================================\n";
		do{	
			
			t1.display();
			myfile.read((char*)&t1,sizeof(t1));
		
		  }while(!myfile.eof());
	
		myfile.close();
	}	
}
void trainer::searchtrainer(int id)
{
	ifstream myfile("trainer.dat",ios_base::binary);
 	if(!myfile)
	{
		cout<<"file does not exist"<<endl;
		return;
	}
	else
	{
		bool found=false;
		trainer t1;
		myfile.read((char*)&t1,sizeof(t1));
		cout<<"\n\t\t=====================================================================================================";
		cout<<"\n\t\t";
		cout<<"|NAME          |  ID       |  PASSWORD        |  CONTACT     |  GENDER     |  AGE |   FEES   |   EXP  |";
		cout<<"\n\t\t====================================================================================================\n";
	 do{
			
			if(id == t1.getid())
			{
				found=true;
				cout<<"record found"<<endl;
				t1.display();
				break;
			}
			myfile.read((char*)&t1,sizeof(t1));
		}while(!myfile.eof());
		if(!found)
		{
			cout<<"Record not found"<<endl;
		}
		myfile.close();
	}
}
void trainer::updateTrainer(int id)
{
	ifstream myfile1("tcount.txt");
	int count;
	myfile1>>count;
	myfile1.close();
	
	trainer *p = new trainer[count];
	ifstream myfile("trainer.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"\nFile doesnt exist";
		return;
	}
	else
	{
		bool found = false;
		trainer t1;
		int i=0;
		myfile.read((char *)&t1,sizeof(t1));
		do
		{				
			//e.Display();
			if(t1.getid() == id)
			{
				found = true;
				cout<<"\nRecord Found";
				int choice=0;
				while(choice!=7)
				{
					cout<<"\n\tpress 1. to change name:"<<endl;
					cout<<"\n\tpress 2. change experience:"<<endl;
					cout<<"\n\tpress 3. change training fees:"<<endl;
					cout<<"\n\tpress 4. change contact number:"<<endl;
					cout<<"\n\tpress 7. Previous menu:"<<endl;
					cin>>choice;
					switch(choice)
					{
						case 1:
						{
							cout<<"\nEnter new name";
							char name[20];
							cin>>name;
							t1.setname(name);	
						}
						break;
						case 2:
						{
							cout<<"\n Change experience:"<<endl;
							char exp[400];
							cin>>exp;
							t1.setexp(exp);
						}
						break;
						case 3:
						{
							cout<<"\n Enter new Fees:"<<endl;
							double fees;
							cin>>fees;
							t1.setfees(fees);	
						}
						break;
						case 4:
						{
							cout<<"\n Enter new contact number"<<endl;
							char cont[15];
							cin>>cont;
							t1.setcontact(cont);	
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
			p[i] = t1;
			i++;
			myfile.read((char *)&t1,sizeof(t1));			
			
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
			ofstream myfile2("trainer.dat",ios_base::binary);
			for(int i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
		}
	}
}
void trainer::deleteTrainer(int id)
{
	ifstream file("tcount.txt");
	int count;
	file>>count;
	file.close();
	
	trainer *p=new trainer[count];
	ifstream myfile("trainer.dat",ios::binary);
	if(!myfile)
	{
		cout<<"\nFile does not exist"<<endl;
		return;
	}
	else
	{
		int i=0;
		bool found=false;
		trainer t1;
		myfile.read((char*)&t1,sizeof(t1));
		do{
			if(t1.getid() == id)
			{
				found=true;
				
			}
			else
			{
				p[i]=t1;
				i++;	
			}
		
			myfile.read((char*)&t1,sizeof(t1));
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
			ofstream myfile1("tcount.txt");
			myfile1<<count;
			myfile1.close();
			ofstream myfile2("trainer.dat",ios_base::binary);
			for(i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
			cout<<"\nProfile sucessfully deleted"<<endl;
			
		}
	}
	
}
void trainer::display()
{
	healthCare::display(); cout<<setw(5)<<this->fees<<setw(5)<<"|"<<this->exp<<"    |";

}
