#include"subscribe.h"
subscribe::subscribe()
{
	int count=0;
	ifstream myfile("Scount.txt");
	if(!myfile)
	{
		ofstream rcount("Scount.txt");
		rcount<<count;
		rcount.close();	
	}
	else
	{
		myfile>>count;
		myfile.close();	
	}
	
}
void subscribe::setcname(char* tnm)
{
	strcpy(this->Cname,tnm);
}
void subscribe::setstartDate(date start)
{
	this->subscDate=start;
}
void subscribe::setEndDate(date end)
{
	this->endDate=end;
}
/*void subscribe::settrainingdays(date d1)
{
	this->tdate=d1.getdate();
}*/
date subscribe::getEndDate()
{
	return this->endDate;
}
date subscribe::getStartDate()
{
	return this->subscDate;
}
/*date subscribe::gettrainingdays()
{
	return this->tdate;
}*/

void subscribe::settname(char* tnm)
{
	strcpy(this->tname,tnm);
}
void subscribe::setfees(double fees)
{
	this->tfees=fees;
}
void subscribe::settid(int id)
{
	this->tid=id;
}
int subscribe::gettid()
{
	return this->tid;
}
void subscribe::setcid(int id)
{
	this->cid=id;
}
int subscribe::getcid()
{
	return this->cid;
}
char* subscribe::getcname()
{
	return this->Cname;
}
char* subscribe::gettname()
{
	return this->tname;
}
double subscribe::getfees()
{
	return this->tfees;
}
void subscribe::trainerList(int cid)
{
	ifstream myfile("trainer.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"file does not exist"<<endl;
		return;
	}
	else
	{
		trainer t1;
		myfile.read((char*)&t1,sizeof(t1));
		do{
			cout<<"\t\t===================================";
			cout<<"\n\t\t|Trainer Name:"<<t1.getname();cout<<"|";
			cout<<"\n\t\t-----------------------------------";
			cout<<"\n\t\t|Trainer Id:"<<t1.getid();cout<<"|";
			cout<<"\n\t\t-----------------------------------";
			cout<<"\n\t\t|Experience:"<<t1.getexp();cout<<"|";
			cout<<"\n\t\t-----------------------------------";
			cout<<"\n\t\t|Contact number:"<<t1.getcontact();cout<<"|";
			cout<<"\n\t\t-----------------------------------";
			cout<<"\n\t\t|Subscription fees:"<<t1.getfees();cout<<"|";
			cout<<"\n\t\t===================================";
			cout<<"\n\n\n"<<endl;
			myfile.read((char*)&t1,sizeof(t1));
		
		  }while(!myfile.eof());
	
		myfile.close();
		char x;
		cout<<"Do you want to subscribe for training(Y/N)"<<endl;
		cin>>x;
		if(x == 'Y' || x == 'y')
		{
			int c=0;
			int tid;
			cout<<"\nEnter trainer id to Enroll"<<endl;
			cin>>tid;
			trainer t;
			ifstream tfile("trainer.dat",ios_base::binary);
			tfile.read((char*)&t,sizeof(t));
			do{
				if(tid == t.getid())
				{
					c=1;
					break;
				}
				else
				{
					c=0;
				}
				tfile.read((char*)&t,sizeof(t));
				
			}while(!tfile.eof());
			tfile.close();
			if(c==0)
			{
				cout<<"Incorrect trainer id"<<endl;
			}
			else
			{
				subscribe s1;

				date start1;
				cout<<"\nEnter start training date"<<endl;
				int d,m,y;
				
				cout<<"Enter Day Month Year(DD-MM-YYY)"<<endl;
				cin>>d>>m>>y;
				this->subscDate.setdate(d);
				this->subscDate.setmonth(m);
				this->subscDate.setyear(y);
				
				s1.setstartDate(this->subscDate);
				
				s1.setfees(t.getfees());
				
				s1.settname(t.getname());
				
				s1.settid(t.getid());
				
				ifstream f("user.dat",ios_base::binary);
				healthClient h;
				f.read((char*)&h,sizeof(h));
				do{
					if(h.getid() == cid)
					{
						s1.setcname(h.getname());
						s1.setcid(cid);
						break;
					}
					f.read((char*)&h,sizeof(h));
				}while(!f.eof());
				f.close();
				cout<<"\nEnter End date"<<endl;
				int d1,m1,y1;
				
				cout<<"Enter Day Month Year(DD-MM-YYY)"<<endl;
				cin>>d1>>m1>>y1;
		
				this->endDate.setdate(d1);
				
				this->endDate.setmonth(m1);
				
				this->endDate.setyear(y1);
				s1.setEndDate(this->endDate);
				int d3;
				d3=this->endDate-this->subscDate;
				s1.trainingdays(d3);
				s1.trainingfees(d3);
				s1.subTrainer(s1);
				cout<<"subscribe sucessfully"<<endl;
				return;
			}
		
		}
		else
		{
			cout<<"Incorrect input"<<endl;
			return;
		}
	}	
	
}
void subscribe::trainingdays(int d)
{
	
	this->totaldays=d;
}
int subscribe::gettrainingdays()
{
	return this->totaldays;
}
void subscribe::trainingfees(int d)
{
	
	this->totalfees=d*this->tfees;
	
}
int subscribe::gettotalfees()
{
	return this->totalfees;
}
void subscribe::subTrainer(subscribe& h1)
{

	
	ifstream myfile2("Scount.txt");
	int count;
	myfile2>>count;
	myfile2.close();
	
	
	count++;
	ofstream myfile1("Scount.txt");
	myfile1<<count;
	myfile1.close();
	
	
	ofstream myfile("subscribe.dat",ios_base::binary | ios_base::app);
	myfile.write((char*)&h1,sizeof(h1));
	myfile.close();
	
	

	cout<<"===============| !Subscribe sucessfull! |=============="<<endl;
		

}
void subscribe::displayallsub()
{
		ifstream myfile("subscribe.dat",ios_base::binary);
	if(!myfile)
	{
		cout<<"file does not exist"<<endl;
		return;
	}
	else
	{
		subscribe t1;
		myfile.read((char*)&t1,sizeof(t1));
		cout<<"\n\t\t===========================================================================================================================================================";
		cout<<"\n\t\t";
		cout<<"|CLIENT NAME   |TRAINER NAME    | TRAINER ID      |  CLIENT ID      | FEES PER DAY |     START DATE    |    END DATE     | TOTAL TRAINING DAY| TOTAL FEES |";
		cout<<"\n\t\t===========================================================================================================================================================\n";
		do{	
			
			t1.display();
			myfile.read((char*)&t1,sizeof(t1));
		
		}while(!myfile.eof());
	
		myfile.close();
	}	
}
void subscribe::displaySub(int id)
{
	int c=0;
	ifstream file("subscribe.dat",ios_base::binary);
 	if(!file)
	{
		cout<<"File not exist"<<endl;
		return;
	}
	else
	{
		bool found=false;
		subscribe s1;
		file.read((char*)&s1,sizeof(s1));
		cout<<"\n\t\t============================================================================================================================================================";
		cout<<"\n\t\t";
		cout<<"|CLIENT NAME   |TRAINER NAME    | TRAINER ID      |  CLIENT ID      | FEES PER DAY |     START DATE    |    END DATE     | TOTAL TRAINING DAY| TOTAL FEES |";
		cout<<"\n\t\t============================================================================================================================================================\n";
		
 	 do{
			if(s1.gettid() == id || s1.getcid() == id)
			{
				
			//	cout<<"record found"<<endl;
				s1.display();
				c=0;
				break;
				
			}
			else
			{
				c=1;
			}
			file.read((char*)&s1,sizeof(s1));
		}while(!file.eof());
		file.close();
		
		if(c==1)
		{
			cout<<"\nNo Data found"<<endl;
		}
	
	}
}
void subscribe::unsubTrainer(int id)
{
	ifstream file("Scount.txt");
	int count;
	file>>count;
	file.close();
	
	subscribe *p=new subscribe[count];
	ifstream myfile("subscribe.dat",ios::binary);
	if(!myfile)
	{
		cout<<"\nFile does not exist"<<endl;
		return;
	}
	else
	{
		int i=0;
		bool found=false;
		subscribe s1;
		myfile.read((char*)&s1,sizeof(s1));
		do{
			if(s1.getcid() == id || s1.gettid() == id)
			{
				cout<<"\nEnter End date"<<endl;
				int d1,m1,y1;
				
				cout<<"Day"<<endl;
				cin>>d1;
				this->endDate.setdate(d1);
				
				cout<<"Month"<<endl;
				cin>>m1;
				this->endDate.setmonth(m1);
				cout<<"Year"<<endl;
				cin>>y1;
				this->endDate.setyear(y1);
				s1.setEndDate(this->endDate);
				int d3;
				d3=s1.getEndDate()-s1.getStartDate();
				s1.trainingdays(d3);
				s1.trainingfees(d3);
				found=true;
				
			}
			else
			{
				p[i]=s1;
				i++;	
			}
		
			myfile.read((char*)&s1,sizeof(s1));
		}while(!myfile.eof());
		myfile.close();
		
		if(!found)
		{
			cout<<"\nNo such record found of this ID"<<endl;
			return;
		}
		else
		{
		cout<<"\n\t\t===========================================================================================================================================================";
		cout<<"\n\t\t";
		cout<<"|CLIENT NAME   |TRAINER NAME    | TRAINER ID      |  CLIENT ID      | FEES PER DAY |     START DATE    |    END DATE     | TOTAL TRAINING DAY| TOTAL FEES |";
		cout<<"\n\t\t===========================================================================================================================================================\n";
			s1.display();
			count--;
			ofstream myfile1("Scount.txt");
			myfile1<<count;
			myfile1.close();
			ofstream myfile2("subscribe.dat",ios_base::binary);
			for(i=0;i<count;i++)
			{
				myfile2.write((char *)&p[i],sizeof(p[i]));
			}
			myfile2.close();
			cout<<"\nUnsubscribe sucessfully deleted"<<endl;
			
		}
	}
	
}
void subscribe::display()
{
/*	cout<<"\nClient name:"<<this->Cname;
	cout<<"\ntrainer name:"<<this->tname;
	cout<<"\nTrainer id:"<<this->tid;
	cout<<"\nclient id:"<<this->cid;
	cout<<"\nfees per day:"<<this->tfees;
	cout<<"\nstart date:";this->getStartDate().ddisplay();
	cout<<"\nEnd date:";this->getEndDate().ddisplay();
	cout<<"\nTotal numbers of training days:"<<this->totaldays;
	cout<<"\nTotal training fees"<<this->totalfees;*/
	cout<<setw(17)<<"|"<<this->Cname<<setw(10)<<"|"<<this->tname<<setw(15)<<"|"<<this->tid<<setw(15)<<"|"<<this->cid<<setw(15)<<"|"<<this->tfees<<setw(10)<<"|";this->getStartDate().ddisplay();cout<<setw(10)<<"|";this->getEndDate().ddisplay();cout<<setw(10)<<"|"<<this->totaldays<<setw(10)<<"|"<<this->totalfees<<setw(10)<<"  |"<<endl;
	cout<<"\t\t-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
