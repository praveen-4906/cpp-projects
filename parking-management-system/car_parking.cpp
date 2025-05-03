#include <iostream>
#include<string.h>
using namespace std;

//variables

int choice;
char status[11] = {'E','E','E','E','E','E','E','E','E','E','E'} ;
int pno;
char carname[10][15];
char ownername[10][15];
float intime[10];
float outtime[10];
float duration[10];
float amount[10];
float totalamount[10];

//Functions
void homescreen();
void addcar();
void removecar();
void carinfo();

int main()
{
	cout<<"====================================================\n";
	cout<<"\n                  PARKING SOFTWARE                  \n";
	cout<<"\n====================================================\n";
	
	homescreen();
	
}

void homescreen()
{
	cout<<"\nReference Image :"<<"           "<<"Full or Empty Status :\n";
	cout<<"\n|   |   |   |   |   |"<<"     "<<"  |   |   |   |   |   |";
	cout<<"\n| 1 | 2 | 3 | 4 | 5 |"<<"     "<<"  | "<<status[1]<<" | "<<status[2]<<" | "<<status[3]<<" | "<<status[4]<<" | "<<status[5]<<" |";
	cout<<"\n|___|___|___|___|___|"<<"     "<<"  |___|___|___|___|___|";
	cout<<"\n|   |   |   |   |   |"<<"     "<<"  |   |   |   |   |   |";
	cout<<"\n| 6 | 7 | 8 | 9 | 10|"<<"     "<<"  | "<<status[6]<<" | "<<status[7]<<" | "<<status[8]<<" | "<<status[9]<<" | "<<status[10]<<" |";
	cout<<"\n|   |   |   |   |   |"<<"     "<<"  |   |   |   |   |   |\n";
	
	cout<<"\n1. ADD CAR";
	cout<<"\n2. REMOVE CAR";
	cout<<"\n3. CAR INFO";
	
	cout<<"\n\nEnter Your Choice : ";
	cin>>choice;
	
	if (choice == 1)
		addcar();
		
	else if (choice == 2)
		removecar();
		
	else
		carinfo();
	
}

void addcar()
{
	char eco;
	
	cout<<"\n---------- ADD CAR ----------\n";
	
	cout<<"\nEnter Parking Number : ";
	cin>>pno;
	cout<<"Enter Car Number     : ";
	cin>>carname[pno];
	cout<<"Enter Car Owner Name : ";
	cin>>ownername[pno];
	cout<<"Enter Car IN Time    : ";
	cin>>intime[pno];
	
	status[pno] ='F';
	
	cout<<"\nCar Added Successfully !";
	
	cout<<"\n\nPress 'y' to go to homescreen : ";
	cin>>eco;
	
	if(eco == 'y')
		homescreen();
}

void removecar()
{
	char eco;
	
	cout<<"\n---------- REMOVE CAR ----------\n";
	
	cout<<"\nEnter Parking Number  : ";
	cin>>pno;
	cout<<"Enter Car OUT Time    : ";
	cin>>outtime[pno];
	duration[pno] = outtime[pno] - intime[pno];
	cout<<"Enter Amount per hr   : ";
	cin>>amount[pno];
	
	cout<<"\n\n--------------- RECEIPT ---------------";
	cout<<"\n\nParking Number : "<<pno;
	cout<<"\nCar Number     : "<<strupr(carname[pno]);
	cout<<"\nOwner Name     : "<<strupr(ownername[pno]);
	cout<<"\nDuration       : "<<duration[pno];
	cout<<"\nAmount per hr  : "<<amount[pno];
	totalamount[pno] = amount[pno]*duration[pno];
	cout<<"\nTotal Amount   : "<<totalamount[pno];
	
	status[pno] ='E';
	
	cout<<"\n\nCar Removed Successfully !";
	
	cout<<"\n\nPress 'y' to go to homescreen : ";
	cin>>eco;
	
	if(eco == 'y')
		homescreen();
}

void carinfo()
{
	char eco;
	
	cout<<"\n----- CAR INFO -----\n";
	cout<<"\nEnter Parking Number  : ";
	cin>>pno;
	cout<<"\nCar Number     : "<<strupr(carname[pno]);
	cout<<"\nOwner Name     : "<<strupr(ownername[pno]);
	cout<<"\nCar IN Time    : "<<intime[pno];
	
	cout<<"\n\nPress 'y' to go to homescreen : ";
	cin>>eco;
	
	if(eco == 'y')
		homescreen();
}