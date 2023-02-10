//213060 Muhammad Hassaan Nizaal
//213191 Mahir Ahmad Cheema
//213033 Ali Shaan
//SEMESTER PROJECT 
//CAR PARKING SYSTEM
#include<iostream>
using namespace std;
#include<fstream>
class car
{
	public:
	int vno;
	float count;
	char  dname[15],x,l[50];
	void input()
	{
		system("CLS");
			int d;
			
		cout<<"Enter the Name of driver : "<<endl;
		cin>>dname;
		cout<<"Enter the Car No. : "<<endl;
		cin>>vno;
		cout<<"Enter the no of hours of stay : "<<endl;
		cin>>count;
		cout<<"Enter the time slot : "<<endl;
		cin>>l;
		if(d<20&&count<8)
   			{
   				cout<<"Parking Available! You can park your car. "<<endl;
   			}
   			else
   				cout<<"Parking not possible!!"<<endl;
   			cout<<"Car got parked!!"<<endl;
		
	}
	void cal()
	{
			
		cout<<"Are you a V.I.P: y/n "<<endl;
		cin>>x;
		if(x=='y')
	{
		system("CLS");
		cout<<"The total expense during parking  "<<endl;
		cout<<count*20<<" rupees"<<endl;
	}
	else 
	{
		system("CLS");
		cout<<"The total expenses during parking  "<<endl;
		cout<<count*25<<" rupees"<<endl;
		
	}
}	
	void output()
	{
		cout<<"The Driver Name : "<<dname<<endl;
		cout<<"The Car No : "<<vno<<endl;
		cout<<"The Hours Of Stay : " <<count<<endl;
		cout<<"The Time Slot Of Parking : " <<l<<endl;
	
	}
	

		
}a,a1;


int main()
{
car c;

	int choice,vno1,d;
	while(1) {
	system("CLS");

     cout <<"CAR PARKING RESERVATION SYSTEM "<<endl;
     cout <<"                                          "<<endl;
     cout<<"                                          "<<endl;
    cout<<"THE PRICE IS 20 RUPEES PER VECHILE FOR VIPs"<<endl;
     cout<<"THE PRICE IS 25 RUPEES PER VECHILE FOR Regulars"<<endl;
     cout<<endl;	
     cout << "1. Arrival of a Car"<<endl;
     cout << "2. Total no of cars Arrived"<<endl;
     cout << "3. Total parking charges of all cars with details"<<endl; 
     cout << "5. Exit Program"<<endl;
     cout<<"                                                                  "<<endl;
     cout << "  "<<endl;
     cout << "Select Your Choice ::"<<endl;
     cin>>choice;
     switch(choice)
     {
      case 1 :
        {		
        		char f;
        		cout<<"Do You Want to continue: y/n "<<endl;
        		cin>>f;
        		if(f=='y')
        		{
        		
				ofstream f1("parking3.dat",ios::binary|ios::out|ios::app);
                a.input();
                f1.write((char*)&a,sizeof(a));
        }
            	break;
        }
       case 2 :
           {
           	system("CLS");
  		   cout << "View the Records in the Parking Database"<<endl;
           cout << " "<<endl;
           ifstream infile("parking3.dat",ios::binary|ios::in);
           int d=1;
           while (infile.read((char *)&a,sizeof (a)))
		   {
		system("CLS");
           cout << " "<<endl;
           cout<<"The Car position in parking lot : "<<d<<endl;
           d++;
           a.output();
           cout<<"  "<<endl;
           cout<<"   "<<endl;
           system("PAUSE");
           cout<<endl;
       	   }
       
           break;
       	   }
       
	
    	case 3:
		{
				ifstream infile("parking3.dat",ios::binary|ios::in);
           while (infile.read((char *)&a,sizeof (a)))
		   {
             cout << "  "<<endl;
			 a.cal();
			 a.output();
			 cout<<"  "<<endl;
			 cout<<endl;
			 
       		}
       		break;
   }
   		
   		case 5: 
		   {
		   	system("CLS");
		   	cout<<endl;
		   	cout<<"  THANK YOU FOR PARKING YOUR VEHICLE                  "<<endl;
		   	
		   exit(0);
   			break;
   		}
   		default : 
		   {
		   	
		   cout<<"Invalid input"<<endl;
	
   	}
   }
}

}


