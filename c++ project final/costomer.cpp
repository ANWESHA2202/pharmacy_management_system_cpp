#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class customer
{ private:
  int id;
  char name[40];
  char address[60];
  long int phn;
  double amount;
public:
   void addcustomer ();
   void show ();
   
    int getid ()
  {
    return id;
  }
  friend void modify ();
  friend void write ();
  friend void display1 ();
};

void
customer::addcustomer ()
{
  cout << "Enter customer id:\t";
  cin >> id;
  cin.ignore ();
  cout << "Enter customer name:\t";
  cin.getline (name, 40);
  cout << "Enter customer address:\t";
  cin.getline (address, 60);

  cout << "Enter customer phone no:";
  cin >> phn;
  cin.ignore ();
  cout << "Enter customer amount:\t";
  cin >> amount;


}


void customer::show ()
{
  cout << "CUTOMER ID:\t" << id << endl;
  cout << "CUSTOMER NAME:\t" << name << endl;
  cout << "ADDRESS:\t" << address << endl;
  cout << "PHONE NO:\t" << phn << endl;
  cout << "AMOUNT:\t\t" << amount << endl;
  cout << "-----------------------------" << endl;
  cout << "-----------------------------" << endl;

}


void write ()
{
  char ch = 'y';
  customer c;

  fstream fout;


  fout.open ("customer1", ios::out | ios::binary | ios::app);
  if (!fout)
    {
      cout << "ERRORE FILE NOT OPEN!!!!" << endl;
      exit (0);
    }

  while ((ch == 'y' || ch == 'Y'))
    {
      c.addcustomer ();
      fout.write ((char *) &c, sizeof (c));
      cout << "Do you want add more customer detail(y/n)?:";
      cin >> ch;

    }
  fout.seekg (0);
  fout.close ();
}


void display1 ()
{
  customer c1;
  ifstream fin;
  fin.open ("customer1", ios::binary);
  if (!fin)
    {
      cout << "ERRORE FILE NOT OPEN!!!!" << endl;
      exit (0);
    }

  while (fin.read ((char *) &c1, sizeof (c1)))
    {

      c1.show ();
    }

  fin.close ();
}


void modify ()
{
  int flag = 0;
  fstream f;
  int cid;
  customer c2;
  f.open ("customer1", ios::in | ios::out | ios::binary | ios::ate);
  if (!f)
    {
      cout << "ERRORE FILE NOT OPEN!!!!" << endl;
      exit (0);
    }
  f.seekg (0);
  f.read ((char *) &c2, sizeof (c2));
  cout << "enter the id of customer whose record to be updated: ";
  cin >> cid;
  while (f.read ((char *) &c2, sizeof (c2)))
    {
      if (c2.getid () == cid)
	{
	  cout << "\nNAME:" << c2.
	    name << "\tADDRESS:" << c2.address << "\tPHONE NO:" << c2.
	    phn << "\tAMOUNT:" << c2.amount << endl;
	  cout << "\nEnter new detail of customer" << endl;

	  cout << "New Name:\t";
	  cin.ignore ();
	  cin >> c2.name;

	  cout << "New address:\t";
	  cin.ignore ();
	  cin >> c2.address;

	  cout << "New phone no:\t";
	  cin.ignore ();
	  cin >> c2.phn;

	  cout << "New Amount:\t";
	  cin.ignore ();
	  cin >> c2.amount;


	  f.seekp (-sizeof (c2), ios::cur);
	  f.write ((char *) &c2, sizeof (c2));
	  flag = 1;
	}
    }


  if (flag == 0)
    {
      cout << "\n" << cid << "CUSTOMER ID NOT EXIST !!!" << endl;
    }
}


/*int main ()
{
  customer a1;

  int select;

  cout << "MENU DRIVEN :" << endl;
  cout << "1.Write customer detail:" << endl;
  cout << "2.Read customer detail:" << endl;
  cout << "3.Modify customer detail:" << endl;
  cout << "Exit" << endl;
  cout << "\n\nEnter choice:\t";
  cin >> select;
  cout << "\n";

  switch (select)
    {
    case 1:
      a1.write ();
      cout << endl;
      break;
    case 2:
      cout << "           CUSTOMER DETAILS" << endl;
      cout << "______________" << "\n\n";
      a1.read ();
      cout << endl;
      break;

    case 3:
      a1.modify ();
      //a1.read();
      cout << endl;
      break;

    default:
      cout << "WRONG CHOICE!!!" << endl;
      exit (0);


    }

  return 0;
  getch ();

}*/
