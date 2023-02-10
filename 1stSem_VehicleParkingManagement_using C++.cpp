//213060
//Muhammad Hassaan Nizaal
//PF PROJECT
#include<iostream>   //header file

using namespace std;
//main function
int main()
{
    int inp; 
    int amount=0,car_count=0,bus_count=0,count=0,motorbike_count=0;
    // Parking price for different vehicle
    int motorbike_price=100;
    int car_price=200;
    int bus_price=300;

     int n=50;// n is the number of total parking space in parking
  
    while(true)
    {
        //menu starting
        cout << " ====== CAR PARKING RESERVATION SYSTEM ======"<<endl;
        cout<<"                                              "<<endl;
        cout<<"  Press 1 for Motorbike: "<<endl;
        cout<<"  Press 2 for Car: "<<endl;
        cout<<"  Press 3 for Bus: "<<endl;
        cout<<"  Press 4 to show the record: "<<endl;
        cout<<"  Press 5 to delete all record: "<<endl;
        
		
		//inp 
        cin>>inp;

        if(inp==1)
        {
            if(count<n)
            {
                // parking charges of rickshaw
                cout << "_____________________________________" << endl;
                cout<<"  Amount to paid for MotorBike Rs 100/-"<<endl;
                amount+=motorbike_price;
                motorbike_count++;
                count++;
                 
                 cout << "  Data Saved successully " << endl;
                  cout << "_____________________________________" << endl;
            }
            else
                cout<<"  Parking is full"<<endl;
        }
        else if(inp==2)
        {
            if(count<n)
            {
                // parking charges of car
                cout << "_____________________________________" << endl;
                cout<<"  Amount to paid for Car is Rs 200/-"<<endl;
                amount+=car_price;
                car_count++;
                count++;
                cout << "  Data Saved successully " << endl;
                  cout << "_____________________________________" << endl;
            }
            else
                cout<<"  Parking is full"<<endl;
            }
        else if(inp==3)
        {
            if(count<n)
            {
                // parking charges of bus
                cout << "_____________________________________" << endl;
                cout<<"  Amount to paid for Bus is Rs 300/-"<<endl;
                amount+=bus_price;
                bus_count++;
                count++;
                cout << "  Data Saved successully " << endl;
                  cout << "_____________________________________" << endl;
            }
            else cout<<"  Parking is FULL"<<endl;
        }
        else if(inp==4)
        {
            //details to be display on the screen
            cout<<"  Number of vehicle parked in parking area is "<< count<<endl;
            cout<<"  Number of MotorBikes parked "<<motorbike_count<<endl;
            cout<<"  Number of car parked "<<car_count<<endl;
            cout<<"  Number of bus parked " <<bus_count<<endl;
            cout<<"  Total Amount " <<amount<<endl;
        }
        else if(inp==5)
        {
            // delete the previous result
            amount=0;
            //set all counter to zero
            count=0;
            bus_count=0;
            motorbike_count=0;
            car_count=0;
        }
        else
            cout<<"  Invalid input";
        cout<<endl;
    }
}
