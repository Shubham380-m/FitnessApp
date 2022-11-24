#include"client.h"
healthClient::healthClient()
{
	this->height=00;
	this->weight=00;
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
healthClient::healthClient(double hig,double wig,char* nm,int id,char* pass,char* con,char* gen,int ag) : healthCare(nm,id,pass,con,gen,ag)
{
	this->height=hig;
	this->weight=wig;
}
void healthClient::setweight(double wght)
{
	this->weight=wght;
}
void healthClient::setheight(double heg)
{
	this->height=heg;
}
void healthClient::caloriesCal(double heigh,double weigh,int age,char* gen)
{
	double bmr;
	if(strcmp(gen,"female")==0)
	{
		bmr=(9.247*weigh + 3.098*heigh - 4.300*age + 477.593);
		
		cout<<"\t\t\nYou need to maintain "<<bmr<<" Calories per day"<<endl; 
		return;
	}
	else
	{
		bmr=(13.397*weigh + 4.799*heigh - 5.677*age + 88.362);
		cout<<"\t\t\nYou need to maintain "<<bmr<<" Calories per day"<<endl;
		return;
	}	
}
void healthClient::heightWeight(double height,double weight,char* gen)
{
	double ibw;
	double nheight;
	if((strcmp(gen,"female")==0) || (strcmp(gen,"FEMALE")==0))
	{
		ibw=45.5+0.9*(height -152);
		cout<<"Ideal weight is: "<<ibw<<" for height: "<<height;
	}
	else
	{
		ibw=50+0.9*(height -152);
		cout<<"Ideal weight is between: "<<ibw<<" for height: "<<height;
	}
}
void healthClient::registerclient(healthClient  &h1)
{
	
//	int c=0;

	ifstream file("user.dat",ios_base::binary);
	if(!file)
	{
		
		ifstream myfile2("count.txt");
		int count;
		myfile2>>count;
		myfile2.close();
		
		
		count++;
		ofstream myfile1("count.txt");
		myfile1<<count;
		myfile1.close();
		
		
		ofstream myfile("user.dat",ios_base::binary | ios_base::app);
		myfile.write((char*)&h1,sizeof(h1));
		myfile.close();
		
		
	
		cout<<"===============| !Registration sucessfull! |=============="<<endl;
		return;
	}
	else
	{
		file.close();
		
		ifstream myfile2("count.txt");
		int count;
		myfile2>>count;
		myfile2.close();
		
		
		count++;
		ofstream myfile1("count.txt");
		myfile1<<count;
		myfile1.close();
		
		
		ofstream myfile("user.dat",ios_base::binary | ios_base::app);
		myfile.write((char*)&h1,sizeof(h1));
		myfile.close();
	
	

		cout<<"===============| !Registration sucessfull! |=============="<<endl;
	}	
		/*	else
			{
				healthCare h2;
			
			//	file.read((char*)&h2,sizeof(h2));
				while(!file.eof())
				{
					file.read((char*)&h2,sizeof(h2));
					if(h1.getid() == h2.getid())
					{
						c=1;
						break;
					}
				
				}
				file.close();
				if(c==1)
				{
					cout<<"\t\t\n*ALLREADY REGESTERED WITH THIS USER ID"<<endl;
					cout<<"\t\t\t\n!PLEASE TRY WITH DIFFERENT ID!"<<endl;
					return;
				}*/

//	}
	
}
bool healthClient::login(int nid)
{
	char pass[20];
	bool found=false;
	int c=0;
	ifstream myfile("user.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"File not found"<<endl;
	}
	else
	{
		healthClient h1;
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
void healthClient::Displayclient()
{
	ifstream myfile("user.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"file does not exist"<<endl;
		return;
	}
	else
	{
		healthClient c1;
		myfile.read((char*)&c1,sizeof(c1));
		cout<<"\n\t\t=====================================================================================================";
		cout<<"\n\t\t";
		cout<<"|NAME         |  ID        |  PASSWORD      |  CONTACT       |  GENDER     |  AGE | Height  |weight|";
		cout<<"\n\t\t=====================================================================================================\n";
		do{	
			
			c1.display();
			myfile.read((char*)&c1,sizeof(c1));
		
		  }while(!myfile.eof());
	
		myfile.close();	
	}	
}
void healthClient::searchClient(int cid)
{
	ifstream myfile("user.dat",ios_base::binary);
 	if(!myfile)
	{
		cout<<"file does not exist"<<endl;
		return;
	}
	else
	{
		bool found=false;
		healthClient h1;
		myfile.read((char*)&h1,sizeof(h1));
		cout<<"\n\t\t=====================================================================================================";
		cout<<"\n\t\t";
		cout<<"|NAME         |  ID        |  PASSWORD      |  CONTACT       |  GENDER     |  AGE | Height  |weight|";
		cout<<"\n\t\t=====================================================================================================\n";
	 do{
			
			if(cid == h1.getid())
			{
				found=true;
				h1.display();
			//	cout<<"record found"<<endl;
			
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
void healthClient::updateClient(int id)
{
	ifstream myfile1("count.txt");
	int count;
	myfile1>>count;
	myfile1.close();
	
	healthClient *p = new healthClient[count];
	ifstream myfile("user.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"\nFile doesnt exist";
		return;
	}
	else
	{
		bool found = false;
		healthClient h1;
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
					cout<<"\n\tpress 2. change weight"<<endl;
					cout<<"\n\tpress 3. change height"<<endl;
					cout<<"\n\tpress 4. change contact number"<<endl;
					cout<<"\n\tpress 5. Change password"<<endl;
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
							cout<<"\n Change weight"<<endl;
							double weigh;
							cin>>weigh;
							h1.setweight(weigh);
						}
						break;
						case 3:
						{
							cout<<"\n Enter new height"<<endl;
							double heig;
							cin>>heig;
							h1.setheight(heig);	
						}
						break;
						case 4:
						{
							cout<<"\n Enter new contact number"<<endl;
							char cont[15];
							cin>>cont;
							h1.setcontact(cont);	
						}
						case 5:
						{
							cout<<"\nEnter new password"<<endl;
							char pass[30];
							cin>>pass;
							h1.setpass(pass);
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
			ofstream myfile2("user.dat",ios_base::binary);
			for(int i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
		}
	}
}
void healthClient::deleteclient(int id)
{
	ifstream file("count.txt");
	int count;
	file>>count;
	file.close();
	
	healthClient *p=new healthClient[count];
	ifstream myfile("user.dat",ios::binary);
	if(!myfile)
	{
		cout<<"\nFile does not exist"<<endl;
		return;
	}
	else
	{
		int i=0;
		bool found=false;
		healthClient h1;
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
			ofstream myfile1("count.txt");
			myfile1<<count;
			myfile1.close();
			ofstream myfile2("user.dat",ios_base::binary);
			for(i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
			cout<<"\nProfile sucessfully deleted"<<endl;
			
		}
	}
	
}
void healthClient::display()
{
/*	cout<<"\n\t\t=====================================================================================================";
	cout<<"\n\t\t";
	cout<<"|NAME         |  ID        |  PASSWORD      |  CONTACT       |  GENDER     |  AGE | Height  |weight|";
	cout<<"\n\t\t=====================================================================================================\n";*/
	healthCare::display(); cout<<setw(5)<<height<<setw(5)<<"|"<<weight<<"    |"; //cout<<"|"<<height<<"|"<<weight;
	cout<<"\n\t\t-----------------------------------------------------------------------------------------------------"<<endl;
	
}
