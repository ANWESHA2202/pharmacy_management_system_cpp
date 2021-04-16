#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<stdio.h>

using namespace std;
void login();
void reg();
void forgot();
void mn();


 int i=0;
 bool exist=false;
void login()
{  
    
    string id,password,user,pass;
			
    cout<<"\nUsername:"<<endl;
    cin>>id;
    cout<<"\nPassword:"<<endl;
    cin>>password;

    ifstream file("database.txt");

    while(file>>user>>pass)
    {
        if(user==id)
        {
            if(pass==password)
            {
                exist=true;
                cout<<"\nWELCOME "<<id<<endl;
            
            }
        }

    }

    file.close();

    if(!exist)
	{  
	 if(i!=2)
    	{
	
	   cout<<"\n Incorrect User ID or Password"<<endl;
        cout<<"Enter Again\n";
        
       while(i!=2)
        { 
		i++;
        login();
        if(exist)
        {
        	break;
		}
        
       }
   }   while(i==2)
      { 
       cout<<"Too Many Incorrect Entries ";
       forgot();
       ++i;
       if(i!=2)
       break;
    
   }
    }
    

}
void reg()
{
    string user, password;
   
    cout<<"\nEnter Username:"<<endl;
    cin>>user;
    cout<<"\nEnter Password:"<<endl;
    cin>>password;

    ofstream reg("database.txt",ios::app);
    reg<<user<<"\t"<<password<<endl;

   
    cout<<"\nREGISTRATION IS SUCCESSFUL!!!"<<endl;
    mn();
}
void forgot()
{
    int ch;
     cout<<"FORGET PASSWORD\n\n";
    cout<<"\n1.Search account using username: "<<endl;
    cout<<"2.Return to Mainmenu:"<<endl;
    cout<<"_________________________"<<endl;
    cout<<"\nEnter your choice:    ";
    cin>>ch;

    switch(ch)
    {
        case 1:
        {
            bool exist=false;
            string id,user,pass;

            cout<<"\nEnter your Username:"<<endl;
            cin>>id;

            ifstream file("database.txt");
            while(file>>user>>pass)
            {
                if(id==user)
                {
                    exist=true;
                    break;
                }
            }
            file.close();
            if(exist)
            {
                cout<<"your password is "<<pass;
                cin.get();
                cin.get();
                mn();
            }
            else
            {
                cout<<"\nSorry your account doesn't exist"<<endl;
                cout<<"Please register!"<<endl;
                cin.get();
                cin.get();
                mn();
            }
            break;
        }


        case 2:
        {
            mn();
            break;
        }

        default:
        {
            cout<<"Oops! wrong choice! press a key to try again"<<endl;
            cin.get();
            cin.get();
            forgot();
        }
    }


}

void mn()
{
    int choice;
    cout<<"****************** LOG IN *******************"<<endl;
    cout<<"1.Log in"<<endl;
    cout<<"2.Register"<<endl;
    cout<<"3.Forgot password"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Enter your CHOICE:"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            login();
            break;
        }
        case 2:
        {
            reg();
            break;
        }
        case 3:
        {
            forgot();
            break;
        }
        default:
        {
            cout<<"Alert: wrong choice!"<<endl<<"Please choice again"<<endl;
            mn();
            break;
        }
    }


}

/*int main()
{
    mn();
    return 0;
}*/
