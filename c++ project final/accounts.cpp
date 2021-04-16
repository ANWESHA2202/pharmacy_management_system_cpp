#include<iostream>
#include<fstream>
#include<string>
#include "test1.cpp"

using namespace std;
 double acc=0;

double bill_to_account()
{
    
    acc+=billsum;

    return acc;
}


void display_account()
{
	cout<<"TOTAL INCOME="<<acc<<endl;
}
/* int main()
 {
 	bill_to_account();
 }*/
 
/*double stock_to_account()
{
    double stock=StockEntry();
    acc-=stock;

    return acc;
}*/
