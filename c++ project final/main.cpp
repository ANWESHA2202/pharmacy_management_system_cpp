//project on pharmacy management system by rahul, anwesha, komal
//login and billing system is done by anwesha
//stock management and main is done by rahul
//customer details and account is done by komal




#include <iostream>
#include"costomer.cpp"
#include"accounts.cpp"
#include"login.cpp"

using namespace std;

void Menu()
{
	 int choice;
    cout<<"****************** MAIN MENU *******************"<<endl;
    cout<<"PRESS 1:GENERATE BILL"<<endl;
    cout<<"PRESS 2:VIEW STOCK"<<endl;
    cout<<"PRESS 3:ADD NEW STOCK"<<endl;
    cout<<"PRESS 4:UPDATE STOCK DETAILS"<<endl;
    cout<<"PRESS 5:ADD COSTOMER"<<endl;
    cout<<"PRESS 6:VIEW COSTOMERS"<<endl;
    cout<<"PRESS 7:UPDATE COSTOMER DETAILS"<<endl;
    cout<<"PRESS 8:VIEW ACCOUNTS DETAILS"<<endl;
	cout<<"----------------------------------------------------"<<endl;
    cout<<"Enter your CHOICE:"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            execute();
            bill_to_account();
            Menu();
            break;
        }
        case 2:
        {
            StockAccess();
            Menu();
			break;
        }
        case 3:
        {
            StockEntry();
            Menu();
			break;
        }
        case 4:
        {
            StockUpdate();
            Menu();
            break;
        }
        case 5:
        {
            write();
            Menu();
            break;
        }
        case 6:
        {
            display1();
            Menu(); 
            break;
        }
        case 7:
        
		{
            modify();
            Menu();
            break;
        }
        case 8:
        {
            display_account();
            Menu();
            break;
        }
        default:
        {
            cout<<"Alert: wrong choice!"<<endl<<"Please choice again"<<endl;
             Menu();
            break;
        }
    }
}

int main()
{  
 for(int i=0;i<80;i++)
    {
        cout<<"_";
    }
    
    cout<<endl<<setw(45)<<" CURE_IT DRUG SHOP"<<endl;
    
	for(int i=0;i<80;i++)
    {
        cout<<"_";
    }
    
    cout<<"\n\n";
     mn();
     
    if(exist)
    Menu();
    
	return 0;
	
}
