#include "subscribe.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
		admin a1;
		trainer t1;
		healthClient h1;
	int choice=0;
	while(choice!=4)
	{
		cout<<"\t\n========================================================================\n"<<endl;
		cout<<"\t\t\t | Welcome to FitMe App |           \n"<<endl;
		cout<<"\t press 1. User.   "<<endl;
		cout<<"\t press 2. Admin.   "<<endl;
		cout<<"\t press 3. trainer.  "<<endl;
		cout<<"\t press 4. to Exit   "<<endl;
		cout<<"\t\n========================================================================\n"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				int selec=0;
				while(selec!=3)
				{
					cout<<"============================"<<endl;
					cout<<"            USER            "<<endl;
					cout<<"============================"<<endl;
					cout<<"\n\t 1.Register "<<endl;
					cout<<"\t 2. login"<<endl;
					cout<<"\t 3.exit"<<endl;
					cin>>selec;
					switch(selec)
					{
						case 1:
						{
							cout<<"\t___________________________________________________"<<endl;
							cout<<"\t\t\t\t|      Register     |"<<endl;
							cout<<"\t___________________________________________________"<<endl;
							char name[40];
							int id;
							char pass[20];
							char cont[10];
							char gen[20];
							int age;
							double weight;
							double height;
							cout<<"\n Enter name:"<<endl;
							cin>>name;
							cout<<"\n Create id:"<<endl;
							cin>>id;
							cout<<"\n Enter password:"<<endl;
							cin>>pass;
							cout<<"\n Enter contact number"<<endl;
							cin>>cont;
							cout<<"\nEnter gender"<<endl;
							cin>>gen;
							cout<<"\nEnter age:"<<endl;
							cin>>age;
							cout<<"\nEnter weight"<<endl;
							cin>>weight;
							cout<<"\nEnter height"<<endl;
							cin>>height;
							healthClient h2(height,weight,name,id,pass,cont,gen,age);
							h1.registerclient(h2);
						}
						break;
						case 2:
						{
							subscribe s1;
							int id;
						
							cout<<"Enter id:"<<endl;
							cin>>id;
						
							if(h1.login(id))
							{
								
								cout<<"\n\n\t\t__________| login sucessfull |___________"<<endl;
								int select=0;
								while(select!=9)
								{
									cout<<"\n\t\t\t\t====================================================================================\n"<<endl;
									cout<<"\n\t\t\t\t\t\t\t| Welcome To The App |"<<endl;
									cout<<"\n\t\t\t\t====================================================================================\n"<<endl;
									cout<<"\t\t\t\t press 1. display profile: "<<endl;
									cout<<"\t\t\t\t press 2. Update/edit prifile: "<<endl;
									cout<<"\t\t\t\t press 3. check daily calories count: "<<endl;
									cout<<"\t\t\t\t press 4. check height-to-Weight ratio: "<<endl;
									cout<<"\t\t\t\t press 5. Display trainer list:"<<endl;
									cout<<"\t\t\t\t press 6. Display subscribe trainer:"<<endl;
									cout<<"\t\t\t\t press 7. Delete subscribtion"<<endl;
									cout<<"\t\t\t\t press 8. Delete your profile :"<<endl;
									cout<<"\t\t\t\t press 9. to exit"<<endl;
									cin>>select;
									switch(select)
									{
										case 1:
											{
											h1.searchClient(id);
											}
											break;
										case 2:
											{
												h1.updateClient(id);	
											}
											break;
										case 3:
											{
												double weight;
												double height;
												int age;
												char gen[10];
												cout<<"========================CALORIES TRACKING=================="<<endl;
												cout<<"\t\t\t Enter weight in kg:"<<endl;
												cin>>weight;
												cout<<"\t\t\t Enter height in cm:"<<endl;
												cin>>height;
												cout<<"\t\t\t Enter age:"<<endl;
												cin>>age;
												cout<<"\t\t\t Enter gender:"<<endl;
												cin>>gen;
											
												h1.caloriesCal(height,weight,age,gen);
											}
											break;
										case 4:
											{
												double heig,weigh;
												char gen[10];
												cout<<"\t\t===============Height to weight ratio================"<<endl;
												cout<<"Enter gender:"<<endl;
												cin>>gen;
												cout<<"Enter height in cm:"<<endl;
												cin>>heig;
												cout<<"Enter weight in kg:"<<endl;
												cin>>weigh;
												h1.heightWeight(heig,weigh,gen);
											}
											break;
										case 5:
											{
												s1.trainerList(id);
											}
											break;
										case 6:
											{
												s1.displaySub(id);
											}
											break;
										case 7:
											{
												s1.unsubTrainer(id);
											}
											break;
										case 8:
											{
												
												h1.deleteclient(id);
												main(argc,argv);
											}
											break;
										case 9:
											cout<<"Thanku for Visiting"<<endl;
											break;
										default:
											cout<<"Invalid input"<<endl;
											break;
										  	
									}
								}
							
							}
							else
							{
							cout<<"\n***No such Id found***"<<endl;
				
							//main(argc,argv);
							}
						}
						break;
						case 3:
						break;
						default:
							cout<<"Invalid input"<<endl;
							
					}
				}
			}
			break;
			case 2:
			{
				int selec=0;
				while(selec!=3)
				{
					cout<<"============================"<<endl;
					cout<<"            ADMIN            "<<endl;
					cout<<"============================"<<endl;
					cout<<"\n\t 1.Register "<<endl;
					cout<<"\t 2. login"<<endl;
					cout<<"\t 3.exit"<<endl;
					cin>>selec;
					switch(selec)
					{
						case 1:
						{
							cout<<"\t___________________________________________________"<<endl;
							cout<<"\t\t\t\t|      Register     |"<<endl;
							cout<<"\t___________________________________________________"<<endl;
							char name[40];
							int id;
							char pass[20];
							char cont[10];
							char gen[20];
							int age;
							
							cout<<"\n Enter name:"<<endl;
							cin>>name;
							cout<<"\n Create id:"<<endl;
							cin>>id;
							cout<<"\n Enter password:"<<endl;
							cin>>pass;
							cout<<"\n Enter contact number"<<endl;
							cin>>cont;
							cout<<"\nEnter gender"<<endl;
							cin>>gen;
							cout<<"\nEnter age:"<<endl;
							cin>>age;
						
							admin h2(name,id,pass,cont,gen,age);
							a1.Adminregister(h2);
						}
						break;
						case 2:
						{
							subscribe s1;
							int id;
						
							cout<<"Enter id:"<<endl;
							cin>>id;
						
							if(a1.login(id))
							{
								healthClient c1;
								cout<<"\n\n\t\t__________| login sucessfull |___________"<<endl;
									int s=0;
								while(s!=16)
								{
									cout<<"\n\t1.Add client"<<endl;
									cout<<"\t2.Add trainer"<<endl;
									cout<<"\t3.Search client"<<endl;
									cout<<"\t4.search trainer"<<endl;
									cout<<"\t5.update client"<<endl;
									cout<<"\t6.Update trainer"<<endl;
									cout<<"\t7.Delete client"<<endl;
									cout<<"\t8.Delete Trainer"<<endl; 
									cout<<"\t9.Display suscribed client"<<endl;
									cout<<"\t10.Delete subscription"<<endl;
									cout<<"\t11.Display all client"<<endl;
									cout<<"\t12.Display all trainers"<<endl;
									cout<<"\t13.Display admin profile"<<endl;
									cout<<"\t14.Update admin profile"<<endl;
									cout<<"\t15.Delete admin profile"<<endl;
									cout<<"\n\t16.Exit"<<endl;
									cin>>s;
									switch(s)
									{
										case 1:
										{
							
											cout<<"\t___________________________________________________"<<endl;
											cout<<"\t\t\t\t|      ADD CLIENT     |"<<endl;
											cout<<"\t___________________________________________________"<<endl;
											char name[40];
											int id;
											char pass[20];
											char cont[10];
											char gen[20];
											int age;
											double weight;
											double height;
											cout<<"\n\t Enter name:"<<endl;
											cin>>name;
											cout<<"\t Create id:"<<endl;
											cin>>id;
											cout<<"\t Enter password:"<<endl;
											cin>>pass;
											cout<<"\t Enter contact number"<<endl;
											cin>>cont;
											cout<<"\tEnter gender"<<endl;
											cin>>gen;
											cout<<"\tEnter age:"<<endl;
											cin>>age;
											cout<<"\tEnter weight"<<endl;
											cin>>weight;
											cout<<"\tEnter height"<<endl;
											cin>>height;
											healthClient h2(height,weight,name,id,pass,cont,gen,age);
											h1.registerclient(h1);
										}
										break;
										case 2:
										{
											cout<<"\t___________________________________________________"<<endl;
											cout<<"\t\t\t\t|      ADD TRAINER     |"<<endl;
											cout<<"\t___________________________________________________"<<endl;
											char name[60];
											int id;
											char pass[30];
											char cont[15];
											int age;
											char gen[10];
											char exp[90];
											double fees;
											cout<<"\t Enter name:"<<endl;
											cin>>name;
											cout<<"\t Create id:"<<endl;
											cin>>id;
											cout<<"\t Enter password:"<<endl;
											cin>>pass;
											cout<<"\t Enter contact number"<<endl;
											cin>>cont;
											cout<<"\t Enter age"<<endl;
											cin>>age;
											cout<<"\tEnter experience in years"<<endl;
											cin>>exp;
											cout<<"\t Enter your Traning fees per person"<<endl;
											cin>>fees;
											
											
											trainer t2(fees,exp,name,id,pass,cont,gen,age);
											t1.registertrainer(t2);
										}	
										case 3:
										{
											int aid;
											cout<<"Enter id to search data"<<endl;
											cin>>aid;
											h1.searchClient(aid);	
										}
										break;
										case 4:
										{
											int aid;
											cout<<"Enter id to search client"<<endl;
											cin>>aid;
											t1.searchtrainer(aid);
										}
										break;
										case 5:
										{
											int aid;
											cout<<"Enter id of client to update data"<<endl;
											cin>>aid;
											h1.updateClient(aid);		
										}
										break;
										case 6:
										{
											int aid;
											cout<<"Enter id of TRAINER to update data"<<endl;
											cin>>aid;
											t1.updateTrainer(aid);
										}
										break;
										case 7:
										{
											int aid;
											cout<<"Enter id of client to DELETE data"<<endl;
											cin>>aid;
											h1.deleteclient(aid);
										}	
										break;
										case 8:
										{
											int aid;
											cout<<"Enter id of TRAINER to update data"<<endl;
											cin>>aid;
											t1.deleteTrainer(aid);			
										}
										break;
										case 9:
											{
												s1.displayallsub();
											}
											break;
										case 10:
											{
												int sid;
												cout<<"Enter trainer or Client Id to delete subscription"<<endl;
												cin>>sid;
												s1.unsubTrainer(id);
											}
											break;
										case 11:
										{
											h1.Displayclient();
										}
										break;
										case 12:
										{
											t1.displaytrainer();
										}
										break;
										case 13:
										{
											a1.searchAdmin(id);
										}
										break;
										case 14:
										{
											a1.updateadmin(id);
										}
										break;
										case 15:
										{
											a1.deleteadmin(id);
										}
										case 16:
										break;
										default:
											cout<<"Invalid input"<<endl;
									
									}
								}
							}
						}
						case 3:
						break;
						default:
						cout<<"invalid input"<<endl;
						break;
					}
				
				}
			}
			break;
			case 3:
			{
				int t=0;
				while(t!=3)
				{
					cout<<"\t=========================="<<endl;
					cout<<"\t          TRAINER         "<<endl;
					cout<<"\t=========================="<<endl;
					cout<<"\t 1. Register "<<endl;
					cout<<"\t 2.login "<<endl;
					cout<<"\t 3.exit"<<endl;
					cin>>t;
					switch(t)
					{
						case 1:
						{
							char name[60];
							int id;
							char pass[30];
							char cont[15];
							int age;
							char gen[10];
							char exp[90];
							double fees;
							cout<<" Enter name:"<<endl;
							cin>>name;
							cout<<" Create id:"<<endl;
							cin>>id;
							cout<<" Enter password:"<<endl;
							cin>>pass;
							cout<<" Enter contact number"<<endl;
							cin>>cont;
							cout<<" Enter gender"<<endl;
							cin>>gen;
							cout<<" Enter age"<<endl;
							cin>>age;
							cout<<" Enter experience in training(min:100 words)"<<endl;
							cin>>exp;
							cout<<" Enter your Traning fees per Day"<<endl;
							cin>>fees;
							
							
							trainer t2(fees,exp,name,id,pass,cont,gen,age);
							t1.registertrainer(t2);	
						}
						break;
						case 2:
						{
							subscribe s1;
							int id;
					
							cout<<"Enter id:"<<endl;
							cin>>id;
						
							if(t1.logintrainer(id))
							{
								healthClient c1;
								cout<<"\n\n\t\t__________| login sucessfull |___________"<<endl;
								int select=0;
								while(select!=5)
								{
									cout<<"\n\t\t\t\t====================================================================================\n"<<endl;
									cout<<"\n\t\t\t\t\t\t\t| Welcome To The App |"<<endl;
									cout<<"\n\t\t\t\t====================================================================================\n"<<endl;
									cout<<"\t\t\t\t press 1. display profile: "<<endl;
									cout<<"\t\t\t\t press 2. display my clients: "<<endl;
									cout<<"\t\t\t\t press 3. Update/edit prifile: "<<endl;
									cout<<"\t\t\t\t press 4. Delete your profile :"<<endl;
									cout<<"\t\t\t\t press 5. to exit"<<endl;
									cin>>select;
									switch(select)
									{
										case 1:
											{
											t1.searchtrainer(id);
											}
											break;
										case 2:
											{
												s1.displaySub(id);
											}
											break;
										case 3:
											{
												t1.updateTrainer(id);
											}
											break;
										case 4:
											{
												
												t1.deleteTrainer(id);
												main(argc,argv);
											}
											break;
										case 5:
											cout<<"Thanku for Visiting"<<endl;
											break;
										default:
											cout<<"Invalid input"<<endl;
											break;
										  	
									}
								}
							
							}
							else
							{
							cout<<"\n***No such Id found***"<<endl;
				
							//main(argc,argv);
							}
							break;
						}
						break;
						case 3:
						break;
						default:
						cout<<"Invalid input"<<endl;
						break;
					}
						
				}
			}
			break;
			case 4:
			cout<<"Thank you for visiting"<<endl;
			break;
			default:
			cout<<"|wrong input| \nPlease choose from above option"<<endl;
			break;
	
	
			
		}
	}
	return 0;	
}
