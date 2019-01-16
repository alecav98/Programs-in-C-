/****************************************************
The program will take input from a text file,
use the numbers from the input file to calculate some data,
and output the results in a html webpage. This program
uses score_info.txt.
*****************************************************/

#include <iostream>
#include <fstream>

using namespace std;

/****************
function - printWebStart

parameters - the output file stream, the title of the web page
returns - nothing

prints the HTML for the beginning of a web page to the output file
****************/

void printWebStart(ofstream &oFile, string pageTitle)
{
   oFile << "<html>" << endl;
   oFile << "<head>" << endl;

   oFile << "<title>" << pageTitle << "</title>" << endl;

   oFile << "</head>" << endl;
   oFile << "<body>" << endl;

}

/****************
function - printWebEnd

parameters - the output file stream
returns - nothing

prints the HTML for the end of a web page to the output file
****************/

void printWebEnd(ofstream &oFile)
{
    oFile << "</body>" << endl;
    oFile << "</html>" << endl;
}

/****************
function - calcAverage

parameters - the total of the exams (int), the number of exams (int)
returns - the average of the exams (double)

Returns the average of the exam scores when passed in the total and the number of exams
****************/

double calcAverage(int total, int numExams)
{
    //YOUR CODE GOES HERE
    double average;

    average = (static_cast<double>(total))/numExams;

    return average;
}

/****************
function - processData

parameters - the output file stream
returns - nothing

Reads in the data and prints the report in HTML to the output file
****************/
void processData(ofstream &oFile)
{
    ifstream inFile;
    inFile.open("score_info.txt");

    string fName;
    string lName;
    int grade;
    int numExams;
    int total = 0;

    inFile >> fName;
    inFile >> lName;

    oFile << "<b> Grade Report for </b>" << "<br/>" << "<br/>" << endl;
    oFile << fName << " " << endl;

     //YOUR CODE GOES HERE

    oFile << lName << "<br/>" << endl;
    oFile << "<br/>" << endl;

    inFile >> numExams;

    for (int i = 0; i < numExams; i++)
   {
      inFile >> grade;

      oFile << "Exam " << i + 1 << " - " << grade << "<br/>" << endl;
      total = total + grade;
   }

    double average = calcAverage(total, numExams);
    oFile << "<br/>" << endl;
    oFile << "Average - " << average << "<br/>" << endl;

    if (average >= 89.5)
    {
        oFile << "Grade - A" << endl;
        oFile << "<br/>" << "<br/>" << fName << " " << lName << " - <b> Passed </b>" << endl;
    }
    else if (average >= 70)
    {
        oFile << "Grade - C" << endl;
        oFile << "<br/>" << "<br/>" << fName << " " << lName << " - <b> Passed </b>" << endl;
    }
    else if (average < 70)
    {
        oFile << "Grade - F" << endl;
        oFile << "<br/>" << "<br/>" << fName << " " << lName << " - <b> Failed </b>" << endl;
    }
    else if (average < 0)
    {
        oFile << "Invalid input, try again." << endl;
    }
    else if (average > 100)
    {
        oFile << "Invalid input, try again." << endl;
    }
}


/**************************************************************************************/

int main()
{
    ofstream outFile;
    outFile.open("prog04_output_jac571.html");

    printWebStart(outFile, "Grade Report");

    processData(outFile);

    printWebEnd(outFile);

    outFile.close();

//take this line out after you get the program to run
cout << "Hello World!" << endl;

    return 0;
}
