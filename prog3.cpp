/****************************************************
File Name:prog3__jac571.cpp

Lab Section Number: L08
Lab Section Instructor: Sandhya Rani Doti

Author: Jorge Caviedes
Date: 2/10/2017
Problem Number: 1
CS 1428 Spring 2017
Lecture Instructor: Priebe



The program will calculate the rat's IQ and then print
it out on the screen.
*****************************************************/

#include <iostream>
#include <fstream>

using namespace std;

double calcIQScore(int numCorrectAns, int secondsTaken)
{
   const int CORRECT_ANSWER = 10;
   const int BONUS_POINTS = 5;
   const int AVERAGE_NUM_SECONDS = 30;

   int ratIQ;

   ratIQ = (numCorrectAns * CORRECT_ANSWER);

   if (secondsTaken < AVERAGE_NUM_SECONDS)
   {
      ratIQ += (BONUS_POINTS);
   }

   return ratIQ;
}

void printResults(string name, int ratIQ)
{
   cout << name << " has a ratIQ of " << ratIQ << "." << endl;
}

int main()
{
   ifstream inFile;
   inFile.open("test.txt");

   int numTests;

   inFile >> numTests;

//out << "num tests " << numTests << endl;

   string name;
   int numCorrectAns;
   int secondsTaken;

   for (int i = 0; i < numTests; i++)
   {
      inFile >> name;
      inFile >> numCorrectAns;
      inFile >> secondsTaken;

      int ratIQ = calcIQScore(numCorrectAns, secondsTaken);

//cout << name <<" " << "has a ratIQ of " << ratIQ << endl;

      printResults(name, ratIQ);

   }

}
