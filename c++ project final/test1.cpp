#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"stock.cpp"

using namespace std;


class receipt
{
    public:
        string name; //product name
        int qty;
        double price;
        float product_total;
        
        double product_price(int qty, double price);
        void display(int num,string name,double price,int qty,receipt r[]);
        void condisplay(int num,string name,double price,int qty,receipt r[]);
        friend void execute();
};


int x=0;
int billsum=0;                        //used in display and condisplay


double receipt::product_price(int qty,double price)
{
    double pprice=0;
    pprice=qty*price;
    return pprice;
}

double bill(int qty,double price,int num,receipt r[])
{

    double total=0;
    for(int i=0;i<num;i++)
    {
        total+=r[i].product_total;
    }

    if(total>2500&&total<3000)
    {
        total-=(total*0.01);
    }

    else if(total>=3000&&total<4000)
    {
        total-=(total*0.02);
    }
    else if(total>=4000&&total<5000)
    {
        total-=(total*0.05);
    }
    else if(total>=5000)
    {
        total-=(total*0.1);
    }


    return total;

}

void default_display()
{
    ofstream file;
    file.open("bill.dat",ios::app);
    for(int i=0;i<70;i++)
    {
        file<<"-";
        cout<<"-";
    }
    file<<endl;
    cout<<endl;

    file.width(35);file<<"MED STORE"<<endl;
    cout<<setw(38)<<"MED STORE"<<endl;

    for(int i=0;i<70;i++)
    {
        file<<"-";
        cout<<"-";
    }
    file<<endl;
    cout<<endl;

    file.width(12);file<<"PRODUCT NAME"<<"\t";
    cout<<setw(12)<<"PRODUCT NAME"<<"\t";
    
	file.width(8);file<<"PRICE"<<"\t";
    cout<<setw(8)<<"PRICE"<<"\t";
    
	file.width(8);file<<"QUANTITY"<<"\t";
    cout<<setw(8)<<"QUANTITY"<<"\t";
    
	file.width(13);file<<"PRODUCT PRICE"<<"\t";
    cout<<setw(13)<<"PRODUCT PRICE"<<"\t";
    
	file<<endl;
    cout<<endl;

}




void receipt::display(int num,string name,double price,int qty,receipt r[])
{
    ofstream file;
    file.open("bill.dat",ios::app);
    
       
        file.width(12);file<<name<<"\t";
        file.width(8);file<<price<<"\t";
        file.width(8);file<<qty<<"\t";
        file.width(13);file<<r[x].product_price(qty,price)<<"\t";
        file<<endl;
    
    
}



void receipt::condisplay(int num,string name,double price,int qty,receipt r[])
{

   
        cout<<setw(12)<<name<<"\t";
        cout<<setw(8)<<price<<"\t";
        cout<<setw(8)<<qty<<"\t";
        cout<<setw(13)<<r[x].product_price(qty,price)<<"\t";
        cout<<endl;
        
}

void execute()
{
	 receipt r[5];
	 int count=0;
    int num=0,i=0,qty;
    string name;
    double price,pprice=0,total=0;
    char c='Y';
    while(c=='Y'||c=='y')
    {
        cout<<"\nPRODUCT NAME:"<<endl;
        cin>>name;
        r[i].name=name;
        cin.ignore();

        cout<<"\nPRODUCT PRICE:"<<endl;
        
        read();
        for(int inc=0;inc<5;inc++)
				  {
				  	if(M2[inc].MedName==r[i].name)
				  	
					  
				      r[i].price=M2[inc].Price;
		            
				    }
		cout<<r[i].price<<endl;		    
		

        cout<<"\nPRODUCT QUANTITY:"<<endl;
        cin>>qty;
        r[i].qty=qty;
        
       /* int flag=0;
 	
 	          fstream f;
 	          f.open("stock.txt",ios::in|ios::out|ios::binary|ios::ate);
 	          f.seekg(0);
 	          f.read( (char*) &M2, sizeof(M2));
 	          
               int inc=count;
              for(;inc<5;inc++)
              {
			  
 	          if(M2[inc].MedName==r[i].name)
 	          {
	              M2[inc].Quantity-=r[i].qty;


	             f.seekp (-sizeof (M2), ios::cur);
	             f.write ((char *) &M2[inc], sizeof (M2[inc]));
	             flag = 1;
	             count++;
	             
	          }
 	          
 	          }*/
 	        
        pprice=r[i].product_price(qty,price);
        cout<<"\nTO ADD MORE PRODUCT PRESS 'Y', ELSE PRESS ANY OTHER CHARACTER  "<<endl;
        i++;
        num++;
        cin>>c;
    }
    default_display();
    ofstream file;
    file.open("bill.dat",ios::app);
    for(int i=0;i<80;i++)
    {
        cout<<"_";
        file<<"_";
    }
    cout<<endl;
    file<<endl;
   for(int i=0;i<num;i++)
    {
        r[i].product_total=r[i].product_price(r[i].qty,r[i].price);
        r[i].display(num,r[i].name,r[i].price,r[i].qty,r);
	    r[i].condisplay(num,r[i].name,r[i].price,r[i].qty,r);
	    x++;
    }
    

    total=bill(qty,price,num,r);
    billsum+=total;
    cout<<"\n\n";
    cout<<setw(58)<<"TOTAL   ="<<total<<endl<<endl<<endl;
    file<<endl<<endl;
    file.width(47);file<<"TOTAL=  ";
	file.width(14);file<<total<<endl;
}


/*int main()
{   execute();
    return 0;
}*/

