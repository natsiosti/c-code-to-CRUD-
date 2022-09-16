#include <iostream>
#include <assert.h>
#include <time.h>
#include <bitset>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <istream>
#include <typeinfo>
#include <string.h>
#include <unistd.h>

using namespace std;

const int SIGMA=32;


class upper_class
	{
		char name[SIGMA];
		char surname[SIGMA];
		char surbub[SIGMA];
		public:
			virtual string input();
			virtual string process();
			virtual string output();

	};

class lower_class
	{
		char name[SIGMA];
		char surname[SIGMA];
		char surbub[SIGMA];
		public:
			virtual string input();
			virtual string process();
			virtual string output();
	};

class unix_pass
	{
		char *pass;
		int comp;
		const char *cpass;
		public:
			unix_pass()
			{
				cpass="mtsambiwa";
			}
			int unix_pw();
			~unix_pass()
			{
				system("clear");
			}
	};

int unix_pass::unix_pw()
	{
		for(int iota=0;iota<11;iota++)
		cout<<endl;
		cout<<setw(55);
		pass=getpass("PASSWORD\t");
		comp=strcmp(pass,cpass);
		return comp;
	}

class database
	{
		string product,model,price,bank_1,bank_2,bank_3,uuid,ser1,ser2,ser3,junk,_time;
		stringstream ss0,ss1,ss2;
		ofstream fout_1,fout_2,fout_3;	
		double _price;	
		size_t i,c;
		bitset <SIGMA> serialize;
	

		time_t t;
		public:
			database();
			int password();
			void search_db();
			void read_db();
			void update_db();
			void delete_db();
			void display_db();
			~database();
	};

database::~database()
	{
		fout_2.close();

	}	

database::database()
	{

		i=0;	

		fout_1.open("unix_db.txt",ios::in|ios::out|ios::app);
		istream	unix_db(fout_1.rdbuf());
			
		fout_2.open("unix_tracker.txt",ios::in|ios::out|ios::app);
		istream unix_tracker(fout_2.rdbuf());

		fout_3.open("unix_tmp.txt",ios::in|ios::out|ios::app);
		istream unix_tmp(fout_3.rdbuf());
		
		while(getline(unix_tracker,bank_1))
		i++;
		serialize=i;
						
	}



void database::search_db()
	{
		system("clear");
		cout<<setw(22)<<"TYPE SEARCH ITEM\t\t";
		cin.ignore();
		string search;
		getline(cin,search);

		string cat="cat ";

		string grep="|grep ";
		string db="unix_db.txt";

		string s=cat+db+grep+search;

		system(s.c_str());
	}


void database::read_db()
	{
		
		time(&t);
		_time=ctime(&t);
		system("clear");

		cin.ignore();

		cout<<setw(22)<<"MODEL\t\t";
		getline(cin,model);

		cout<<setw(22)<<"PRODUCT\t\t";
		getline(cin,product);

		cout<<setw(22)<<"PRICE\t\t";
		getline(cin,price);
		_price=atof(price.c_str());
	//	printf("%.2f",_price);

fout_1<<setw(22)<<serialize<<setw(22)<<model<<setw(22)<<product<<setw(22)<<fixed<<setprecision(2)<<_price<<setw(22)<<_time<<endl;
	
fout_2<<setw(22)<<serialize<<setw(22)<<model<<setw(22)<<product<<setw(22)<<fixed<<setprecision(2)<<_price<<setw(22)<<_time<<endl;//unix_tracker.txt
		system("clear");	
	}

void database::update_db()
	{
	system("clear");
	cout<<setw(22)<<"WELCOME UPDATE SECTION"<<endl;
	}

void database::delete_db()
	{
		system("clear");
		cout<<setw(22)<<"WELCOME TO DELETE SECTION"<<endl;
		cout<<setw(22)<<"ENTER UNIVERAL UNIQUE ID\t\t";

		cin.ignore();	
		getline(cin,bank_2);
		if(bank_2.length()!=32)
		{
			return;
		}
		istream unix_db0(fout_1.rdbuf());//unix_db.txt
		int alpha;
		string beta;
		while(getline(unix_db0,bank_3))
		{
			alpha=bank_3.find(bank_2);

			if(alpha!=string::npos)
			{
				 beta=bank_3.substr(0,bank_2.length());
				if(beta.length()==32)
				{
					cout<<setw(22)<<"Found !!!!!!"<<endl;
					cout<<setw(22)<<beta<<endl;
			
					continue;
				}
			
			}

		fout_3<<bank_3<<endl;//unix_tmp.txt
		
		}
		fout_3.close();
		fout_1.close();
		remove("unix_db.txt");
		rename("unix_tmp.txt","unix_db.txt");

	}

void database::display_db()
{

	system("clear");
	cout<<setw(22)<<"*************************************************************************************************************************"<<endl;
	cout<<setw(22)<<"UUID"<<setw(22)<<"MODEL"<<setw(22)<<"PRODUCT"<<setw(22)<<"PRICE"<<setw(22)<<"DATE & TIME"<<endl;
	system("less unix_db.txt");

	cout<<setw(22)<<"*************************************************************************************************************************"<<endl;
}

int main(int argc,char**argv)
{
	unix_pass up;
		int pi=up.unix_pw();
		if(pi==0)
		{

			system("clear");
	
			//database db;
			int choice;

			do
			{
				database db;
				cout<<setw(55)<<"HARARE MANAGEMENT SYSTEM"<<endl;
				cout<<setw(55)<<"____UNIX SERIALIZER____"<<endl;
				cout<<endl<<setw(22)<<"1"<<setw(22)<<"SEARCH_DB"<<endl;
				cout<<endl<<setw(22)<<"2"<<setw(22)<<"READ_DB"<<endl;
				cout<<endl<<setw(22)<<"3"<<setw(22)<<"UPDATE_DB"<<endl;
				cout<<endl<<setw(22)<<"4"<<setw(22)<<"DELETE_DB"<<endl;
				cout<<endl<<setw(22)<<"5"<<setw(22)<<"DISPLAY_DB"<<endl;
				cout<<endl<<setw(22)<<"6"<<setw(22)<<"EXIT"<<endl;
				cout<<endl<<setw(22)<<"___PLEASE ENTER YOUR CHOICE___\t\t";
		
				cin>>choice;
				if(cin.fail())	
				{
					system("clear");	
					cout<<endl<<setw(22)<<"INVALI CHOICE....Please enter a valid choice!\t";
					cin.clear();
					cin.ignore();
					cin>>choice;
					
				}
		
				switch(choice)
				{
				case 1:	db.search_db();break;
				case 2:	db.read_db();break;
		 		case 3:	db.update_db();break;
				case 4: db.delete_db();break;
				case 5:	db.display_db();break;
				case 6:	break;

				default:system("clear");cout<<endl<<setw(22)<<"INVALID CHOICE"<<endl;
				}	
			}while(choice!=6);
		}
		else
		{
			system("clear");
			cout<<"ACCESS DENIED"<<endl;
		}
	return 0;
}
