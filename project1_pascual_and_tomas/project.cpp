#include "project.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;
project::project()
{
}

void project::multiples_3_and_5() // solution 1
{
int sum = 0;

    for(int i = 0; i < 1000; i++)
    {
        if(i%3 == 0 || i%5 == 0)
        {
            sum += i;
        }
    }

    cout << " The sum of all divisible of 3 and 5: "<< sum << endl;
}

void project::even_fibonacce() // solution 2
{
    int sum = 0, present = 1, previous = 1, temp;
        while(present < 4000000)
        {
            if(present%2 == 0)
            {
                sum += present;
            }

            temp = present;
            present += previous;
            previous = temp;
        }

        cout << "The sum of all even numbers in fibonacci sequence: " << sum << endl;
}

void project::largest_prime_factor() // solution 3
{

    long long largest_prime = 0LL;
    long long num = 600851475143LL;
    long long num1 = num;
    int i, k;

    for(i = 2; i <= num; i++)
    {

        if(num%i == 0)
        {
            for(k = 2; k < i; k ++)
            {
                if(i%k == 0)
                {
                    break;
                }

                else if(k == i - 1)
                {
                    largest_prime = i;
                    num /=i;
                    cout << "The prime factor of " << num1 << ": "<< i << endl;
                    i--;

                }
            }
        }
    }

    cout << "The Largest Prime factor of " << num1 << ": " << largest_prime << endl;

}

void project::largest_palindrome_product() //solution 4
{
    int numbers[2];
    int highest = 0;

    for(int i = 100 ; i < 1000; i++)
    {
        numbers[0] = i;
        for(int k = 100; k < 1000; k++)
        {
            ostringstream convert;
            string palindrome;
            string final_palindrome = "";
            numbers[1] = k;
            int product = numbers[0]*numbers[1];
            convert << product;
            palindrome = convert.str();
            int range = palindrome.length();
            for(int x = 0; x < range; x++)
            {
                final_palindrome = palindrome.at(x) + final_palindrome;
                if(palindrome == final_palindrome)
                {
                    if(product > highest)
                    {
                        highest = product;
                    }
                }
            }
        }
    }
    cout <<"The Largest Palindrome of 3-digit product: " << highest << endl;
}

void project::smallest_multiple() //solution 5
{
    int i = 1;
    bool c = false;
    while(!c)
    {
        for(int k = 1; k <= 20; k++)
        {

            if(i%k == 0)
            {
                if(k == 20)
                {
                    c = true;
                    break;
                }
            }

            else
            {
                break;
            }
        }
        i++;
    }
    i--;
    cout << "The smalles multiple number: " << i << endl;
}

void project::sum_square_diff() //solution 6
{
    int sum = 0;
    int sqr = 0;
    int temp = 0;
    for(int i = 1; i <= 100; i++)
    {
        sum += i;
        temp = i*i;
        sqr += temp;
    }

    sum *= sum;
    cout << "The Difference of Sum and sqr of 1st 100 natural numbers: "<<sum - sqr << endl;

}

void project::the_10001st_prime() //solution 7
{
    int x = 2;
    for(int i = 0; i < 10001; i++)
    {
        bool a = 0;
        while(!a)
        {
            for(int k = 2; k <= x; k++)
            {

                if(k == x)
                    a = true;

                else if(x%k == 0)
                    break;
            }
            x++;
        }
    }
    x--;
    cout << "The 10,001st Prime factor: "<< x << endl;
}

void project::largest_product_in_series() // solution 8
{

    ifstream ReadFile;
    string line, str;
    string numbers = "";
    int index = 0;
    int temp = 0;
    int y = 0;
    int product = 1;
    int product2 = 1;
    int getnumber[5];
    int highestproduct[5];
    ReadFile.open("4digits.txt");

    while(ReadFile.good())
    {
        getline(ReadFile, line);
        str = line;
        numbers += str;
    }
        string a;
        for(int i = 0; i < 1000 - 4;i++)
        {
            product2 = 1;

            index = i;
            for(int k = 0; k < 5; k++)
            {
                a = numbers.at(index);
                stringstream(a) >> temp;
                y = temp;
                getnumber[k] = y;
                product2 *= getnumber[k];
                index++;
             }

            if(product < product2)
            {
                product = product2;
                for(int k = 0; k < 5; k++)
                {
                    highestproduct[k] = getnumber[k];
                }
            }

        }
      cout << "The highest product of 5 consecutive digits: "<<product << endl;

}

void project::special_pytho_triplet() //solution 9
{
    bool test = false;
    int a, b, c;
    for(a = 1; a < 1000/3; a++)
    {
        for(b = 2; b < 1000/2; b++)
        {
            c = 1000 - a - b;

            if(a*a + b*b == c*c)
            {
                test = true;
                break;
            }
        }
        if(test)
        {
            break;
        }
    }

    cout << "The product of abc: "<<a*b*c << endl;
}

bool project::prime(int x)
{
    if(x == 2)
    {
        return true;
    }

    if(x%2 == 0 || x == 1)
    {
        return false;
    }

    int y = sqrt(x) + 1;
    for(int i = 3; i < y; i++)
    {
        if(x%i == 0)
        {
          return false;

        }
    }

    return true;
}
void project::summation_of_primes()//solution 10
{

    long long sum = 2;
    int x = 3;
    int range = 2000000;

    while(x <= range)
    {
        if(primeno(x)){sum+=x;}

        x+=2;
    }
    cout << "The Sum of all primes below " << range << ": " << sum << endl;
}
