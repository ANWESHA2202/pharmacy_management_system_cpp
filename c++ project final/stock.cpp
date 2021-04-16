#include<iostream>
#include<fstream>
#include"conio.h"

 
using namespace std;

class MedStore
{
  public:
   	       int MedID;
		   char MedName[40];
		   int Quantity;
		   float Price;
		   string Expiry_Date; 
		 
   public:
           friend double StockEntry();
           friend int StockAccess();
           friend int StockWrite();
           friend int StockUpdate();
           
		   int ShowData();
		   friend void read();
		   void display()
			{
				cout<<"MEDICINE ID    ="<<MedID<<endl;
				cout<<"MEDICINE NAME  ="<<MedName<<endl;
				cout<<"QUANTITY       ="<<Quantity<<endl;
				cout<<"PRICE          ="<<Price<<endl;
				cout<<"EXPIRY DATE    ="<<Expiry_Date<<endl;
						
			}
         		
 };
		

 MedStore M1[10];
 MedStore M2[20];
 
 

 
 StockWrite()
 {
 	

 fstream entry;
      
    entry.open("stock.txt",ios::out|ios::app|ios::binary);  //penindg binary file in write mode 
	 if(!entry)
 		{					
  	     cout<<"error file not open";
  		 exit(1);
        }
        
         entry.write((char*)&M1,sizeof(M1));     //writing the data given by user in file"stock"     
		       entry<<endl;
		       
		       entry.close();
        
 }
 int count=3;
double StockEntry()
 	{           int i=0;
 	            
 	           // double tprice=1,sprice=0;
	            char select;
                cout<<"If you want to enter data PRESS y"<<endl;
                cin>>select;
                 while(select=='y'||select=='Y')    //Getting data by user 
		        {
			       cout<<"Enter Medicine ID \n";
			       cin>>M1[i].MedID;
			       cin.ignore();
                   cout<<"Enter Medicine name\n";
	               cin.getline(M1[i].MedName,40);
	            
	           
		           cout<<"Enter Medicine quantity\n";
		           cin>>M1[i].Quantity;
		           
				   cout<<"Enter Medicine price\n";
		           cin>>M1[i].Price;
		          // tprice=M1[i].Price*M1[i].Quantity;
		           //sprice+=tprice;
		           
				  cout<<"Enter Medicine Expiry Date\n";
		           cin>>M1[i].Expiry_Date;
				          
		        cout<<"If you want to exit Press 'N'"<<endl;
		        cout<<"To continue press'Y'"<<endl;
				cin>>select;
				i++;
				count++;
                }
                StockWrite();
               // return sprice;
		             
	}

StockAccess()
 		   	{  
				ifstream entry;
				
			
			      entry.open("stock.txt",ios::in|ios::binary);
			      entry.read( (char*) &M2, sizeof(M2));
				 for(int inc=0;inc<5;inc++)
				
				  { 
				  	if(M2[inc].Price==0)
				  	break;
				    
				    M2[inc].display();
				    cout<<endl;
		            
				    }
				     entry.close();
		    }
			     
void read()
{  ifstream entry;		
	entry.open("stock.txt",ios::in|ios::binary);
	entry.read( (char*) &M2, sizeof(M2));
	entry.close();
	
}
	
		
StockUpdate()
            {
 	          int flag=0;
 	        
 	            string name;
            
 	            	cout<<"Enter the Medicine Name you want to update\n ";
 	                cin>>name;
 	            
 	             
 	          
 	          fstream f;
 	          f.open("stock.txt",ios::in|ios::out|ios::binary|ios::ate);
 	          f.seekg(0);
 	          f.read( (char*) &M2, sizeof(M2));
 	          
               int inc=0;
              for(;inc<5;inc++)
              {
			  
 	          if(M2[inc].MedName==name)
 	          {
			   
 	             cout << "\nNAME:" << M2[inc].MedName; 
				 cout<< "\nQuantity" << M2[inc].Quantity; 
				 cout<< "\nPrice:" << M2[inc].Price;
	             cout<< "\nExpiry Date" << M2[inc].Expiry_Date;
				 cout << "\nEnter new detail of Medicine " << endl;

	            cout << "New  Medicine Name:\t";
	             cin.ignore ();
	             cin >> M2[inc].MedName;

	             cout << "New Qunatity:\t";
	             cin.ignore ();
	             cin >> M2[inc].Quantity;

	             cout << "New Price :\t";
	             cin.ignore ();
	             cin >> M2[inc].Price;
	             
	             cout << "Expiry Date :\t";
	             cin.ignore ();
	             cin >> M2[inc].Expiry_Date;

	             f.seekp (-sizeof (M2), ios::cur);
	             f.write ((char *) &M2[inc], sizeof (M2[inc]));
	             flag = 1;
	             
	             
 	          
 	      }
 	          
 	         }
 	         
 	             if (flag == 0)
                  {
                    cout << "\n" << 101 << "MEDICINE NAME NOT EXIST !!!" << endl;
                  }
}    
		
	  
		        
		       
		    
/*int main()
{ 	
	//StockEntry();
//	StockAccess();
StockUpdate();
	StockAccess();
	getch();
                          
    return 0;
}*/
		               
