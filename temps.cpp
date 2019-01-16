/****************************************************
File Name:temps_jac571.cpp

Lab Section Number: L08
Lab Section Instructor: Sandhya Rani Doti

Author: Jorge Caviedes
Date: 3/29/2017
Problem Number: 1
CS 1428 Spring 2017
Lecture Instructor: Priebe



The program will compute and print out: the average daily high temperature for the
entire month, the number of days over 100 for the month, and the maximum
temperature for the month and on what day it occurred.
*****************************************************/

#include <iostream>
#include <fstream>

using namespace std;

//comment goes here
void getData(double temps[], int &numTemps, string &month)
{
   ifstream inFile;
   inFile.open("summer_temps.txt");
   numTemps = 30;
   inFile >> month;
    //cout << month << endl;

    for(int i=0; i <numTemps; i++)
    {
        inFile >> temps[i];
    }

}

int getOverHundred(double temps [], int numTemps, double MAX_SCORE)
{
   int total = 0;
   for (int i = 0; i < numTemps; i++)
   {
      if (temps[i] > MAX_SCORE)
        total++;
   }

   return total;
}


int findHighest(double temps [], int numTemps)
{
   int high = 0;

   for (int i = 1; i < numTemps; i++)
   {
      if (temps[i] > temps[high])
         high = i;
   }

   return high;
}


double calcAverage(double temps[], int numTemps)
{
   int total = 0;

   for (int i = 0; i < numTemps; i++)
   {
      total = total + temps[i];
   }

   double average = (total) / numTemps;

   return average;
}


int main()
{
   const int MAX_DAYS = 31;
   const double MAX_SCORE = 100.0;
   double temps[MAX_DAYS];
   int numTemps = 0;
   int high;
   string month;

   getData(temps, numTemps, month);

  // for (int i = 0; i < numTemps; i++)
      //cout << i << " " << temps[i] << endl;


   //for (int i = 0; i < numTemps; i++)
     // cout << i << " " << temps[i] << endl;

   //returns the index of the highest exam grade
   int highest = findHighest(temps, numTemps);

   cout << "Maximum temperature: " << temps[highest] << " (occurred on "<< month << " " << highest +1 << ")" << endl;

   double average = calcAverage(temps, numTemps);

   cout << "Average daily high temperature in " << month << ": " << average << endl;

   int days = getOverHundred(temps, numTemps, 100.0);

   cout << "Number of days over a hundred in " << month << ": " << days << endl;



}
