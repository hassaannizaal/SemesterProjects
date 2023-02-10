//TECH HUB
//DSA FINAL SEMESTER PROJECT
//213060 Muhammad Hassaan Nizaal
//213033 Ali Shaan
  #include<iostream>



using namespace std;

class Node
{
    public :
    int id,quantity,price;
    string name;
    Node *next;
    void Add();
    void Administrator();
    void Display();
    void Modify();
    void Delete();
    void DisplayCustomer();
}*head=NULL,*last=NULL;



class Cust
{

public :
    string name;
    long int phoneno;
    Cust *up,*down;
    void Customer();
    void remove();
}*top = NULL,*current = NULL;


void Cust::Customer()
{
    Node *p=head;
    Node ob;
se:
    long int number,choose,count=0,s,y,id,quantity,purchased=0;
    cout<<"Enter your name : ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter your phone number : ";
    cin>>number;
    Cust *temp;
    if(top==NULL)
    {
        temp = new Cust;
        top = temp;
        temp->name = name;
        temp->phoneno = number;
        temp->up = NULL;
        current =temp;
        temp->down = NULL;
    }
    else
    {
        temp = new Cust;
        temp->down = top;
        temp->name = name;
        temp->phoneno = number;
        temp->up = NULL;
        top = temp;
    }
   do{
	cout<<endl;
	cout<<endl;
    cout<<"Enter your choice"<<endl;
	cout<<"Press 1 to INQUIRY about Products."<<endl;
	cout<<"Press 2 to Buy products."<<endl;
	cout<<"Press 3 to Remove products."<<endl;
	cout<<"Press 4 to Exit Customer Section. "<<endl;
    cin>>choose;
 
    switch(choose)
    {
    case 1 :
        cout<<"Here are the products available at our store...."<<endl;
    
        ob.Display();
        break;
    case 2 :
        y :
        purchased++;
        ob.Display();
        cout<<"Enter the id of the product you wanna buy : ";
        cin>>id;
        while(p!=NULL)
        {
            if(p->id==id)
            {
                s :
                cout<<"Enter the quantity of the product you wanna buy : ";
                cin>>quantity;
                if(p->quantity<quantity)
                {
                    cout<<"Sorry! We are not available with the desired quantity. Would you like to enter quantity again?\n1.Yes\n2.No";
                    cin>>choose;
                    if(choose == 1)
                        goto s;
                    else
                        break;
                }
                else
                {
                    p->quantity = p->quantity - quantity;
                    count+=(quantity*(p->price));
                }
                break;
            }
            p=p->next;
        }
        if(p==NULL)
        {
            cout<<"Product not found."<<endl;
        }
        else if(p!=NULL)
        {
            cout<<"Would you like to buy anything else?\n1.Yes\n2.No"<<endl;
            cin>>choose;
            if(choose==1)
            {
            p=head;
           system("cls");	 
        	 goto y;
            }
            
        }
      
	   
	    
    cout<<endl;
	cout<<endl;    
	cout<<"Your Final receipt is as follows..."<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Name : "<<name<<endl;
    cout<<"| Phone number : "<<number<<endl;
    cout<<"| Products purchased : "<<purchased<<endl;
    cout<<"| Total Bill : Rs. "<<count<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"Thankyou for shopping!!"<<endl;
    cout<<endl;
    cout<<endl;
        break;
        
    case 3:
	   remove();
	   break;   
       
    }

	

    

}while(choose!=4);
	int choosee;
 cout<<"Do you want to continue within Customer?\n1.Yes\n2.No"<<endl;
    cin>>choosee;
    if(choosee==1)
        goto se;
    else
        cout<<"Terminated..."<<endl;
}



void Cust::remove()
{
    Node *p = head;
    int id;
    int quantity;
    int count;

    cout << "Enter the id of the item you want to remove from the bill: ";
    cin >> id;
    cout << "Enter the quantity of the item you want to remove: ";
    cin >> quantity;

    while (p != NULL)
    {
        if (p->id == id)
        {
        	
            p->quantity += quantity;
            count -= (quantity * p->price);
            cout << "Item removed successfully! Your updated bill is: Rs." << count << endl;
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Item not found." << endl;
    }
}



void Node::Add()       
{
    int Pid,Pq,Pprice;
    string Pname;
    Node *temp;
    cout<<"Enter id of the product : ";
    cin>>Pid;
    cout<<"Enter name of the product : ";
    cin.ignore();
    getline(cin,Pname);
    cout<<"Enter quantity available of this product : ";
    cin>>Pq;
    cout<<"Enter price of the product : ";
    cin>>Pprice;
    cout<<endl;
    if(head==NULL)
    {
        temp = new Node;
        head = temp;
        temp->name = Pname;
        temp->quantity = Pq;
        temp->price = Pprice;
        temp->id = Pid;
        last = temp;
        last->next = NULL;
    }
    else
    {
        temp = new Node;
        temp->name = Pname;
        temp->quantity = Pq;
        temp->price = Pprice;
        temp->id = Pid;
        last->next = temp;
        last = temp;
    }
    cout<<"Product Added Successfully!!"<<endl;
}




void Node::Display() {
	set:
    if (head == NULL) {
        cout << "There is no existing product!!";
    } else {
        cout << "Existing products are:" << endl;
        cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity" << endl;
        cout << "|==============================================================|" << endl;

        Node* currentNode = head;
        int c = 0;
        while (currentNode != NULL) {
        	
            cout << currentNode->id << "\t\t" << currentNode->name << "\t\t\t" << currentNode->price << "\t\t\t" << currentNode->quantity << endl;
            currentNode = currentNode->next;
            c++;
        }

        cout << "\nTotal products in our store is : " << c << endl;
    }
    int chooose,set;
	cout<<"Do you want to Re-View? If YES press 1 else press 2"<<endl;
     
    cin>>chooose;
    if(chooose==1)
        goto set;
    else
        cout<<"Terminated..."<<endl;
        
}



void Node::Modify()
{
    int id,quantity,price;
    string name;
    Display();
    cout<<"Enter the id of the product you want to modify : ";
    cin>>id;
    Node *p = head;
    while(p!=NULL)
    {
        if(p->id==id)
        {
            cout<<"Existing Details : "<<endl;
            cout<<"Product Name = "<<p->name<<endl;
            cout<<"Product id   = "<<p->id<<endl;
            cout<<"Product Quantity = "<<p->quantity<<endl;
            cout<<"Product Price = "<<p->price<<endl;
            cout<<endl;
            cout<<"Enter new id : ";
            cin>>id;
            p->id = id;
            cout<<"Enter product name : ";
            cin.ignore();
            getline(cin,name);
            p->name = name;
            cout<<"Enter product quantity : ";
            cin>>quantity;
            p->quantity = quantity;
            cout<<"Enter price : ";
            cin>>price;
            p->price = price;
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        cout<<"Invalid id!!"<<endl;
        return;
    }
    cout<<"Item Modified Successfully..."<<endl;
}




void Node::Delete()
{
    int id;
    Display();
    cout<<"Enter the id of the node you want to delete : ";
    cin>>id;
    Node *p=head,*q=NULL;
    while(p!=NULL)
    {
        if(p->id==id&&p==head)
        {
            head = head->next;
            delete p;
            cout<<"Product Deleted successfully!"<<endl;
            break;
        }
        else if(p->id==id)
        {
            q->next = p->next;
            delete p;
            cout<<"Product Deleted successfully!"<<endl;
            break;
        }
        q=p;
        p = p->next;
    }
    if(p==NULL)
        cout<<"Invalid input id!! Product cannot be deleted!"<<endl;
}




void Node::DisplayCustomer()
{
    Cust *p = top;
    cout<<"Customer list up to now is as follows : "<<endl;
    if(p==NULL)
    {
        cout<<"There have been no customers up to now!!"<<endl;
    }
    else
    {
    while(p!=NULL)
    {
        cout<<p->name<<" - "<<p->phoneno<<endl;
        p = p->down;
    }
    }
}





void Node::Administrator()
{
    int choose,s;
    s :
    cout<<"Choose from the following :\n1.Add Product.\n2.Display All Products\n3.Modify Existing Product\n4.Delete an Product\n5.Display Customers List"<<endl;
    cin>>choose;
    switch(choose)
    {
        case 1 : Add();
        break;
        case 2 : Display();
        break;
        case 3 : Modify();
        break;
        case 4 : Delete();
        break;
        case 5 : DisplayCustomer();
        break;
    }
    cout<<"Do you want to continue within administrator?\n1.Yes\n2.No"<<endl;
    cin>>choose;
    if(choose==1)
        goto s;
    else
        cout<<"Terminated..."<<endl;
}




int main()
{
    Node ob;
    Cust c;
   	cout<<endl;
    cout<<"                                         TECH HUB                                      "<<endl;
    cout<<"                                 (AN ONLINE SHOPPING STORE)                           "<<endl;
    cout<<endl;
    cout<<endl;
   
    
    int choice,k;
    string temp_input;
    while (true) 
	{
    	string choose="";
    	cout<<"Press ENTER key to start shopping..."<<endl;
        getline(cin, choose);
        if (choose.empty()) {
            break;
        }
        else{
        	system("cls");
		}
    }
    
    
    cout<<endl<<endl;
    do
    {
	
		
    		cout<<"Please enter the choice from the options mentioned below :"<<endl;
			cout<<"Press 1. for  Administrator"<<endl;
			cout<<"Press 2. for  Customer"<<endl;
			cout<<"Press 3  for  Exit"<<endl<<endl;
    		cout<<"User input: ";
			cin>>choice;
		
		
	system("cls");
    switch(choice)
    {
        case 1 :  ob.Administrator();
       
        break;
        case 2 :  c.Customer();
        
    
        break;
        case 3 : return 0;
        break;
        
    }
    system("pause");
    system("cls");
    }
	while(choice!=3);
}
