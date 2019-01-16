/****************************************************
File Name:prog07_jac571.cpp

Lab Section Number: L08
Lab Section Instructor: Sandhya Rani Doti

Author: Jorge Caviedes
Date: 4/11/2017
Problem Number: 1
CS 1428 Spring 2017
Lecture Instructor: Priebe


The program will read in grade_data.txt input file, grade each exam and print out the score for that exam
on a new text file called grade_report.txt.
It will also keep track of how many students earned each score (0-10) and print a report after the grading.
*****************************************************/

#include <iostream>
#include <fstream>

using namespace std;

//**********  Function Prototypes  ******************

//function gradeExam
//input parameter - the test key and the test
//compares the key with the test and returns a score
//
int gradeExam(string key, string test, const int MAX_QUESTS);



//function calcHigh
//input parameter - testScores array and max number of questions
//Finds the highest score achieved out of all tests taken
int calcHigh (int testScores[], const int MAX_QUESTS);


//function calcLow
//input parameter - testScores array and max number of questions
//finds the lowest score achieved out of all tests taken
int calcLow (int testScores[], const int MAX_QUESTS);


//function calcMean
//input parameter - testScores array and max number of questions
//finds the mean score out of all tests taken
double calcMean (int testScores[], const int MAX_QUESTS);


//******************  MAIN  *****************************

int main ()
{
    const int MAX_QUESTS = 10;
    int testScores[MAX_QUESTS + 1];
    int grade;
    int high;
    int low;
    double mean;

    for (int i = 0; i < MAX_QUESTS +1; i++)
      testScores[i] = 0;

    ifstream inFile;
    inFile.open("grade_data.txt");
    ofstream outFile;
    outFile.open("grade_report.txt");

    string key;
    inFile >> key;

    cout << "Key: " << key << endl;

    string test;
    int count = 0;
    while (!inFile.eof())
    {
        inFile >> test;
        count++;
        grade = gradeExam(key, test, MAX_QUESTS);
        cout << grade << endl;
        testScores[grade] = testScores[grade] + 1;
        outFile << "Student " << count << " - " << grade << endl;
        cout << testScores[grade] << endl;
    }
    cout << count << endl;
//cout << testScores[MAX_QUESTS + 1];

    outFile << endl;
    outFile << "Grade Report" << endl;
    outFile << "------------" << endl;
    for (int i = 10; i >= 0; i--)
    {
        outFile << i << " - " << testScores[i] << endl;
    }
    outFile << endl;
    high = calcHigh(testScores, MAX_QUESTS);
    outFile << "High score - " << high << endl;
    low = calcLow(testScores, MAX_QUESTS);
    outFile << "Low score - " << low << endl;
    mean = calcMean(testScores, MAX_QUESTS);
    outFile << "Mean score - " << mean << endl;

    outFile.close();
}

int gradeExam (string key, string test, const int MAX_QUESTS)
{
    int grade = 0;
    for (int i = 0; i < test.length(); i++)
      {
         if (key[i] == test[i])
         {
            grade++;
         }
      }
    return grade;
}

int calcHigh (int testScores[], const int MAX_QUESTS)
{
    int high = 0;
    for (int i = 10; i >= 0; i--)
    {
      if (testScores[i] != 0)
      {
          if (i > high)
            high = i;
      }
    }

   return high;
}

int calcLow (int testScores[], const int MAX_QUESTS)
{
    int low = 10;
    for (int i = 0; i < MAX_QUESTS + 1; i++)
    {
        if (testScores[i] != 0)
        {
            if (i < low)
               low = i;
        }
    }
    return low;
}

double calcMean (int testScores[], const int MAX_QUESTS)
{
   int total = 0;
   int totStudents = 0;

   for (int i = 0; i < MAX_QUESTS + 1; i++)
   {
      total = total + (testScores[i] * i);
      totStudents = totStudents + testScores[i];
   }

   double mean = static_cast<double>(total) / totStudents;

   return mean;
}
