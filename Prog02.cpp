/****************************************************
The program will print the number of box seat tickets sold,
the number of general admission tickets sold, the gross receipts from ticket sales,
the amount paid to the parking manager, the snack bar profit, and the team profit.
*****************************************************/
#include <iostream>

using namespace std;

int main()
{

   int BoxSeatTicketsSold;
   int GeneralAdmissionTicketsSold;
   double ParkingManagerPay;
   double TeamProfit;
   const double costBoxSeatTicket = 10.75;
   const double costGenAdmissionTicket = 5.50;
   double GrossReceipts;
   const double SnackBarProfitPerPerson = 6.25;
   double TotalSnackBarProfit;
   double PercentageOfProfitForParkingManager = 0.12;

   cout << "Please enter the number of box seat tickets sold: ";
   cin >> BoxSeatTicketsSold;
   cout << "Please enter the number of general admission tickets sold: ";
   cin >> GeneralAdmissionTicketsSold;

   GrossReceipts = (costBoxSeatTicket * BoxSeatTicketsSold) + (costGenAdmissionTicket * GeneralAdmissionTicketsSold);
   ParkingManagerPay = GrossReceipts * PercentageOfProfitForParkingManager;
   TotalSnackBarProfit = (SnackBarProfitPerPerson) * (BoxSeatTicketsSold + GeneralAdmissionTicketsSold);
   TeamProfit = GrossReceipts - ParkingManagerPay;


   cout << "The number of box seat tickets sold was "<< BoxSeatTicketsSold << "." << endl;
   cout << "The number of general admission tickets sold was " << GeneralAdmissionTicketsSold << "." << endl;
   cout << "The gross receipts from ticket sales were " << GrossReceipts << "." << endl;
   cout << "The amount paid to the parking manager was " << ParkingManagerPay << "." << endl;
   cout << "The snack bar profit was " << TotalSnackBarProfit << "." << endl;
   cout << "The team profit was " << TeamProfit << "." << endl;

}
