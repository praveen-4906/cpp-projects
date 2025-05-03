#include <iostream>
#include <iomanip>
using namespace std;

char   proname  [25][15];
double price    [25];
int    quantity [25];
double amount   [25];
double totalamt = 0 ;
int    i = 1;
int    totpro;

void choice();

void addpro()
{
	cout<<"\nEnter name of product "<<i<<"     : ";
	cin>>proname[i];
	cout<<"Enter price of product "<<i<<"    : ";
	cin>>price[i];
	cout<<"Enter quantity of product "<<i<<" : ";
	cin>>quantity[i];
	amount[i] = price[i] * quantity[i];
	totpro = i;
	i++;
	
	choice();
}

void disppro()
{
	cout<<endl;
	cout<<"===========================================\n\n";
	cout<<"                  Reciept                  \n\n";
	cout<<"===========================================\n\n";
	cout<<setw(6)<<"S.NO"<<setw(12)<<"PRODUCT"<<setw(7)<<"PRICE"<<setw(5)<<"QTY"<<setw(8)<<"AMOUNT"<<endl<<endl;
	for (int j=1 ; j<=totpro ; j++)
	{
		cout<<setw(6)<<j<<setw(12)<<proname[j]<<setw(7)<<price[j]<<setw(5)<<quantity[j]<<setw(8)<<amount[j]<<endl;
	}
	for (int k=1 ; k<=totpro ; k++)
	{
		totalamt += amount[k];
	}
	cout<<endl;
	cout<<setw(19)<<"TOTAL AMOUNT"<<setw(19)<<totalamt;
}

void choice()
{
	char choice;

	cout<<"\nDo you wish to add products ( y / n ) : ";
	cin>>choice;
	
	if (choice == 'y')
	{
		addpro();
	}
	else
	{
		disppro();
	}
}

int main ()
{
	cout<<"===========================================\n\n";
	cout<<"              billing software             \n\n";
	cout<<"===========================================\n\n";
	choice();
}













