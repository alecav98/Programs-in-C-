/****************************************************
File Name:prog08_jac571.cpp

Lab Section Number: L08
Lab Section Instructor: Sandhya Rani Doti

Author: Jorge Caviedes
Date: 4/27/2017
Problem Number: 1
CS 1428 Spring 2017
Lecture Instructor: Priebe


The program will store the list of cities in an array of structures and then use that array to write a series of functions.
The functions will get the data, print it out, calculate distance from one city to the next, calculate total distance
and calculate a shorter path than the current one.
*****************************************************/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct City
{
    string name;
    double xCoordinate;
    double yCoordinate;
};

//reads the initial data from the input file
//returns false if the file is not opened correctly
bool getData(string inputFile, City cities[], int &numCities);

//prints the cities in order, one per line
void printRoute(City cities[], int numCities);

//calculates the distance from one city to the next
double getDistance(City city1, City city2);

//calculates the total distance from the first city to the last city
double totalDistance(City cities[], int numCities);

//uses an algorithm to make the total distance shorter than the initial distance, if possible.
void improveRoute(City cities[], int numCities);


int main ()
{
    //string fileName = "route_data.txt";
    const int MAX_CITIES = 100;
    City cities[MAX_CITIES];
    int numCities = 0;
    string inputFile;
    float currentVal;
    float newVal;

    getData(inputFile, cities, numCities);

    cout << "The current route is: " << endl << endl;
    printRoute(cities, numCities);

//    getDistance(city1, city2);
    cout << "The current total distance is: " << totalDistance(cities, numCities) << endl << endl;
    currentVal = totalDistance(cities, numCities);

    improveRoute(cities, numCities);

    cout << "The new route is: " << endl << endl;
    printRoute(cities, numCities);

    cout << "The new total distance is: " << totalDistance(cities, numCities) << endl<< endl;
    newVal = totalDistance(cities, numCities);

    cout << "There was a " << ((newVal)/currentVal) * 100 << "% improvement in efficiency." << endl;

    return 0;
}

bool getData (string inputFile, City cities[], int &numCities)
{
    string fileName = "route_data.txt";
    ifstream inFile;
    inFile.open(fileName.c_str());
    string name;

    while (inFile >> name)
    {
        cities[numCities].name = name;
        inFile >> cities[numCities].xCoordinate;
        inFile >> cities[numCities].yCoordinate;
        numCities++;
    }
    if (!inFile)
        return false;
}

void printRoute(City cities[], int numCities)
{
    for (int i = 0; i < numCities; i++)
    {
        cout << cities[i].name << " ";
        cout << cities[i].xCoordinate << " ";
        cout << cities[i].yCoordinate << endl;
    }
}

double getDistance(City city1, City city2)
{
    double distance1;
    double distance2;
    double total;

    distance1 = pow((city2.xCoordinate - city1.xCoordinate), 2);
    distance2 = pow((city2.yCoordinate - city1.yCoordinate), 2);

    total = sqrt(distance1 + distance2);

    return total;
}

double totalDistance(City cities[], int numCities)
{
    double difference;
    double total = 0;

    for(int i = 0; i < numCities - 1; i++)
    {
        difference = getDistance(cities[i], cities[i+1]);
        total += difference;
    }
    return total;
}

void improveRoute(City cities[], int numCities)
{
    for (int i = 0; i < numCities - 1; i++)
    {
        int closest = i + 1;
        double distance = getDistance(cities[i], cities[closest]);
        for (int j = i + 1; j < numCities; j++)
        {
            if ((getDistance(cities[i], cities[j]) < distance))
            {
                closest = j;
                distance = getDistance(cities [i], cities[j]);
            }
        }
        swap(cities[i+1], cities[closest]);
    }
}
