#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
using namespace std;

void ViewSeating();
void UpdateSeating();
void ShowMenu();
void SeatPrices(double& price, double& price2, double& price3);
void TotalPrices();
void PurchaseTicket();
void SoldCount();
void AvailCount();
void AvailPerRow();

const char sold = '*';			//Seat taken
const char available = '#';		   //Seat open
const int cBlock = 4;
const int aBlock = 5;
const int rows = 12;			   //Number of rows
const int columns = 9;		   //Number of seats per row
const int totalSeats = rows*columns;
char seating[rows][columns];
double totalSales[rows][columns];
double price=12.50, price2=18.00, price3=24.00, totals=0;
int choice = 0, rowChoice = 0, colChoice = 0;


int main()
{
	system("cls");
	cout.imbue(locale("ENGLISH_US"));
	cout << showbase;
	cout << fixed << showpoint << setprecision(2);
	cout << "Welcome to our Theatre" << endl;

	cout << endl << "Seating Chart" << endl << endl;
	cout << "# = Seats available" << endl;
	cout << "* = Seats sold" << endl;
	cout << endl;

	ViewSeating();
	
	ShowMenu();
	
	
	
	
}

void ViewSeating()
{
	cout << setw(cBlock) <<" ";

	for (int i = 0; i < columns; i++)
	{
		cout << setw(aBlock) << i + 1;
	}

	cout << endl << "__________________________________________________"<< endl;

	for (int r = 0; r < rows; r++)
	{
		
		for (int c = 0; c < columns; c++)
		{
			if (c == 0)
			{
				cout << setw(cBlock) << left << "Row "  << setw(cBlock) << left << r + 1;
			}
				seating[r][c] = available;
			
				cout << setw(cBlock) << seating[r][c] << " ";
		}
		cout << endl;
	}
	
	cout << "__________________________________________________" << endl;
	cout << "Seats Sold: "; 
	SoldCount();
	cout << "Seats Available: "; 
	AvailCount();
	cout << endl;
	
}

void UpdateSeating()
{
	cout << setw(cBlock) << right << " ";

	for (int i = 0; i < columns; i++)
	{
		cout << setw(aBlock) << i + 1;
	}

	cout << endl << "__________________________________________________" << endl;

	for (int r = 0; r < rows; r++)
	{

		for (int c = 0; c < columns; c++)
		{
			if (c == 0)
			{
				cout << setw(cBlock) << left << "Row " << setw(cBlock) << left << r + 1;
			}
			
			cout << setw(cBlock) << seating[r][c] << " ";
		}
		cout << endl;
	}

	cout << "__________________________________________________" << endl;

	cout << "Seats Sold: "; 
	SoldCount();
	cout << "Seats Available: "; 
	AvailCount();
	TotalPrices();
	AvailPerRow();

	
	cout << endl;
}

void ShowMenu()
{
	
	cout << endl << endl;
	cout << " \tMAIN MENU\n";
	cout << " 1. View Seat Prices.\n";
	cout << " 2. Purchase a Ticket.\n";
	cout << " 3. View Available Seats.\n";
	cout << " 4. View Available Seats in Each Row.\n";
	cout << " 5. Quit the program.\n";
	cout << "_____________________\n\n";
	cout << "Please enter your choice: ";
	cin >> choice;
	cout << endl << endl;
	while (choice != 5)
	{
		switch (choice)
		{
			case 1:
			{
				SeatPrices(price, price2, price3);
				ShowMenu();
			}
			case 2:
			{
				PurchaseTicket();
			}
			case 3:
			{
				UpdateSeating();
				ShowMenu();
			}
			case 4:
			{
				AvailPerRow();
				ShowMenu();
			}
			case 5:
			{
				break;
			}
		}
	}
}

 void SeatPrices(double& price, double& price2, double& price3)
 {
	

	cout << "The price for each tickets in Row 1-4 is " 
		 << put_money(price3*100) << endl;
	cout << "The price for each tickets in Row 5-8 is "
		<< put_money(price2*100) << endl;
	cout << "The price for each tickets in Row 9-12 is "
		<< put_money(price*100) << endl << endl;
 }

 void TotalPrices()
 {
	double tPrice = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
			 {
				 tPrice = tPrice + totalSales[r][c];
			 }
		 }
		 cout << "Total Sales: " << put_money(tPrice * 100)
		  << endl;
	 
	 
 }

 void PurchaseTicket()
 {
	int purchase = 0;
	char choice;

	cout << "How many tickets would you like to purchase: ";
	cin >> purchase;
	
	do
	{
		for (int i = 0; i < purchase; i++)
		{
			cout << "Pick a Row: ";
			cin >> rowChoice;
			cout << "Pick a Column: ";
			cin >> colChoice;

			seating[rowChoice - 1][colChoice - 1] = sold;
			totalSales[rowChoice-1][colChoice-1] = price3;
			cout << endl;
			
		}
		cout << "Would you like to buy another ticket (Y or N): ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
	UpdateSeating();
 }
 
 void SoldCount()
 {
	 int count = 0;
	 for (int r = 0; r < rows; r++)
	 {
		 for (int c = 0; c < columns; c++)
		 {
			 if (seating[r][c] == sold)
			 {
				 count++;
			 }
		 }	 
	 }
	 cout << count << endl;
 }

 void AvailCount()
 {
	 int count = 0;
	 for (int r = 0; r < rows; r++)
	 {
		 for (int c = 0; c < columns; c++)
		 {
			 if (seating[r][c] == available)
			 {
				 count++;
			 }
		 }
	 }
	 cout << count << endl;
 }

void AvailPerRow()
{
	int countSold = 0;
	int countAvail = columns;
	int count = 0;
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < columns; c++)
			{
				if (r == rowChoice)
				{
					if (seating[r][c] == sold)
					{
						countSold++;
					}
				}	
			}
		}
		count = countAvail - countSold;
}

void DisplayPerRow()
{

}