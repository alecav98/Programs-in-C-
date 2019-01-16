/* mathStuff_jac571.cpp

Roger Priebe and Jorge Caviedes
cs1428 10/15/07 (updated 3/11/08)

Finish comments here
the program will compute if a number is prime, find primes
in between 1 and it, find the number's fibonacci number,
and finally print out the prime factorization of the number
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer greater than 1
//returns true if the number is prime, otherwise false
//
bool isPrime (int number);



//function findPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.
void findPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)
//Note: You must use a loop in your solution. Also, if passed a 0, return 0.
int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
//Hint: You will need nested loops for your solution.
void findFactors (int number);


//******************  MAIN  *****************************

int main () {

    int testNum;

    //test for the isPrime function
    cout << "Enter a test number - ";
    cin >> testNum;
    cout << endl;

    if (isPrime(testNum))
       cout << testNum << " is prime." << endl;
    else
       cout << testNum << " is not prime." << endl;

    //test for how many primes
    cout << "Enter n to print the prime numbers between 1 and n: ";
    cin >> testNum;
    cout << endl;

    findPrimes(testNum);

    cout << endl;

    //test for Fibonacci number finder
    cout << "Which Fibonacci number? ";
    cin >> testNum;
    cout << endl;

    cout << "The " << testNum << " Fibonacci number is : " << findFibo(testNum) << endl;

    cout << endl;

    //test for prime factors
    cout << "Factor what number: ";
    cin >> testNum;
    cout << endl;

    findFactors(testNum);

    return 0;
}




//function isPrime
//input parameter - positive integer greater than 1
//returns true if the number is prime, otherwise false
//
bool isPrime (int number)
{
   //YOUR CODE GOES HERE
   int divisor = 2;
   if (number ==1)
   {
       return false;
   }
   else if (number == 2)
   {
       return true;
   }
   else if (number % divisor == 0)
   {
       return false;
   }
   else
   {
       while (divisor <= sqrt(number) && number % divisor != 0)
       {
           divisor++;
       }
       if (divisor > sqrt(number))
          return true;
       else if (number % divisor == 0)
          return false;
   }

}


//function findPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.
void findPrimes (int n)
{
   //YOUR CODE GOES HERE
   for (int i = 1; i < n; i++)
   {
       if (isPrime(i))
       {
           cout << " " << i << ",";
       }
   }
   cout << endl;
}



//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)
//Note: You must use a loop in your solution. Also, if passed a 0, return 0.
int findFibo (int n)
{
   //YOUR CODE GOES HERE
   if (n==0)
   {
       return 0;
   }
   int a = 1, b = 1;
    for (int i = 3; i <= n; i++)
        {
        int c = a + b;
        a = b;
        b = c;
        }
    return b;
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
//Hint: You will need nested loops for your solution.
void findFactors (int number)
{
   //YOUR CODE GOES HERE
   cout << number << " = 1 ";
   int divisor = 1;
   while (number > 1 && !isPrime(number))
   {
       divisor++;
       while (number % divisor == 0)
       {
           cout << "* " << divisor;
           number = number/divisor;
       }
   }
   if (number >1)
      cout << "* " << number << endl;

}
