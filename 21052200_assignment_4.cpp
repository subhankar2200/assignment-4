#include<iostream>
#include <windows.h>
#include<string>
using namespace std;

class Books//Stores and displays original details of the book
{
	public:
	int id, count;
	double price;
	string author, name;
	void input()
	{
	cout<<"Enter the details of the book:"<<endl;
	cout<<"ID: "<<endl;
	cin>> id;
	cout<<"NAME:"<<endl;
	cin>>name;
	cout<<"PRICE: "<< endl;
	cin>> price;
	cout<<"NAME OF AUTHOR: "<<endl;
	cin>>author;
	cout<<"THE QUANTITY: "<<endl;
	cin>>count;
	}
	void display()
	{
	cout<<"ORIGINAL DETAILS OF THE BOOK:"<<endl;
	cout<<"ID:"<< id<<"\n NAME:"<< name<< "\n ORIGINAL PRICE: "<<price<<"\n AUTHOR: "<<author<<"\n COUNT: "<<count<<endl;

	}

};
class Supplier: public Books//Takes and updates details about books from potential suppliers
{
	public:
	int change;
	double new_price;
	void check()
	{
	cout<<"Do you want to make any modifications to the price of the book you are selling?"<<endl;
	cout<<"Enter 0 for no and 1 for yes"<<endl;
	cin>>change;
	switch(change)
	{
	case 0: cout<<"No changes are being made to the book's price and being supplied"<<endl;
	break;
	case 1: cout<<"What is the price for which you wish to sell the book?"<<endl;
	cout<<"REMEMBER: WE DON'T BUY BOOKS AT A COST WHICH EXCEEDS THEIR MRP BY 100 RUPPEES"<<endl;
	cin>>new_price;
	if(new_price>price)
	{
	if((new_price-price)>100)
	{
	cout<<"SORRY. WE DO NOT ACCEPT THE PROPOSED PRICE AND ARE NOT BUYING THE BOOK"<<endl;
	count=0;
	}
	else
	price=new_price;
	}
	else
	price=new_price;
	break;
	default: cout<<"Wrong option chosen. We are considering there are no changes in the pricing and the book is considered supplied at its original price "<<endl;
	}


	}
	void show(){
	cout<< "UPDATED PRICE OF THE BOOK NOW: "<<new_price;
	}
	};
	class Buyer//Customer buys the book
	{
	public:
	int bID;
	void getId()
	{
	cout<<"Enter the id of the book you want to buy:"<<endl;
	cin>>bID;
	}
	};
	class Rent//Person rents the book
	{
	public:
	int rID;
	void getrId()
	{
	cout<<"Enter the id of the book you want to rent:"<<endl;
	cin>>rID;
	}};
	class ReturnBook//Person returns previously rented book
	{
	public:
	int d;
	void ret()
	{
	cout<<"How many days later are you returning the book?"<<endl;
	cin>>d;
	if(d>15)
	cout<<"You have to pay a fine of 100 ruppees"<<endl;
	else
	cout<<"Thank you for returning the book on time"<<endl;	
	}

	};
    void Intro()
    {
    char intro[200] = "\t\t\t\tOOP Theory Project\n\t\t\tSubmitted By - Subhankar Ghosh\n\t\t\t\tRoll No : 21052200 " ;
        for ( int i = 0; i < strlen(intro); i++)
        {
            cout << intro[i];
            Sleep(100);
        }
        Sleep(2000);
    }
	int main()
	{
        Intro();
	cout<<"\n\nEnter an option from below:"<<endl;
	cout<<"1: SUPPLY A BOOK"<<endl;
	cout<<"2: BUY A BOOK"<<endl;
	cout<<"3: RENT A BOOK"<<endl;
	cout<<"4: RETURN BOOK(PREVIOUSLY RENTED)"<<endl;
	cout<<"5. EXIT"<<endl;
	int op;
	cin>>op;
	Books ob[150];
	Supplier s;
	Buyer b;
	Rent r;
	ReturnBook R;
	int i=0;
	do
	{
	switch(op)
	{
	case 1:ob[i].input();
	ob[i].display();
	s.check();
	s.show();
	i++;
	break;
	case 2:
	{
	b.getId();
	int j=i;
	while(j!=-1)
	{
	if( ob[i].id==b.bID)
	{
	if(ob[j].count!=0)
	{
	cout<<"SOLD TO YOU"<<endl;
	ob[j].count--;
	ob[j].display();
	}
	else
	cout<<"Sorry not in stock"<<endl;

	}
	else
	cout<<"Sorry we do not have that book"<<endl;
	j--;
	}
	}

	break;

	case 3: {

	r.getrId();
	int j=i;
	while(j!=-1)
	{
	if( ob[j].id==r.rID)
	{
	if(ob[j].count!=0)
	{
	cout<<"RENTED TO YOU"<<endl;
	ob[j].count--;
	ob[j].display();
	}
	else
	cout<<"Sorry not in stock"<<endl;

	}
	else
	cout<<"Sorry we do not have that book"<<endl;
	j--;
	}}
	break;
	case 4:{
	cout<<"STATE THE BOOK ID OF THE BOOK YOU ARE RETURNING"<<endl;
	int b_id;
	cin>>b_id;
	int j=i;
	while(j!=-1)
	{
	if(ob[j].id==b_id)
	{

	ob[j].count++;
	cout<<"Book returned succesfully"<<endl;
	ob[j].display();
	}
	else
	cout<<"Wrong id"<<endl;
	j--;	
	}
	R.ret();}
	break;
	default:cout<<"Wrong option. Try Again"<<endl;
	}

	}while(op!=5);
	return 0;
	}
