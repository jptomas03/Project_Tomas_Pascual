#include "project.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <cmath>


using namespace std;
//solution 1-10
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

bool project::primeno(int x)
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
//Solution 11-20
project2::project2()
{

}

void project2::largest_product_grid() //solution 11
{
    int input[20][20] = {
			{ 8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5, 7, 78, 52, 12, 50, 77, 91, 8},
			{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
			{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65},
			{52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91},
			{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
			{24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
			{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
			{67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
			{24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
			{21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
			{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
			{16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
			{86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
			{19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
			{4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
			{88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
			{4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
			{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
			{20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
			{1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}
		};
    long product = 0, temp = 0;

		//for up / down
		int x = 19;
		while(x >= 0)
		{
			for(int a = 0; a < 17; a++)
			{
				temp = (input[a][x] * input[a + 1][x] * input[a + 2][x] * input[a + 3][x]);
				product = product > temp? product : temp;
			}
			x--;
		}

		for(int a = 0; a < 19; a++)
		{
			for(int b = 0; b < 17; b++)
			{
				temp = input[a][b] * input[a][b + 1] + input[a][b + 2] + input[a][b + 3];
				product = product > temp? product : temp;
			}
		}


		for(int a = 3; a < 20; a++)
		{
			for(int b = 3; b < 20; b++)
			{
				temp = input[a][b - 3] * input[a - 1][b - 2] * input[a - 2][b - 1] * input[a - 3][b];
				product = product > temp? product : temp;
			}
		}


		for(int a = 0; a < 17; a++){
			for(int b = 0; b < 17; b++){
				temp = input[a][b] + input[a + 1][b + 1] + input[a + 2][b + 2] + input[a + 3][b + 3];
				product = product > temp? product : temp;
			}
		}
		cout << "Largest product: " << product << endl;

}

int project2::getdivisors(int num1) //for solution 12
{
    int divisor_counted = 0;
    int x = 1;

    while (x <= sqrt(num1))
    {
        if (!(num1 % x))divisor_counted++;
        x++;
    }

    return divisor_counted;
}

void project2::divisible_triangular_number() //solution 12
{
    int divisor = 500;
    divisor /= 2;

    int num = 0;
    int i = 0;
    int j = 1;
    while (num < divisor)
    {
        i = i + j;
        num = getdivisors(i);
        j++;
    }
    cout << i << endl;
}

void project2::largest_sum() //solution 13
{
    long long temp = 0;
    long long carry[50] = {0};
    int k = 49;
    int i = 49;
    long long answer[50] = {0};
    int data[100][50] = {
    {3,7,1,0,7,2,8,7,5,3,3,9,0,2,1,0,2,7,9,8,7,9,7,9,9,8,2,2,0,8,3,7,5,9,0,2,4,6,5,1,0,1,3,5,7,4,0,2,5,0},
    {4,6,3,7,6,9,3,7,6,7,7,4,9,0,0,0,9,7,1,2,6,4,8,1,2,4,8,9,6,9,7,0,0,7,8,0,5,0,4,1,7,0,1,8,2,6,0,5,3,8},
    {7,4,3,2,4,9,8,6,1,9,9,5,2,4,7,4,1,0,5,9,4,7,4,2,3,3,3,0,9,5,1,3,0,5,8,1,2,3,7,2,6,6,1,7,3,0,9,6,2,9},
    {9,1,9,4,2,2,1,3,3,6,3,5,7,4,1,6,1,5,7,2,5,2,2,4,3,0,5,6,3,3,0,1,8,1,1,0,7,2,4,0,6,1,5,4,9,0,8,2,5,0},
    {2,3,0,6,7,5,8,8,2,0,7,5,3,9,3,4,6,1,7,1,1,7,1,9,8,0,3,1,0,4,2,1,0,4,7,5,1,3,7,7,8,0,6,3,2,4,6,6,7,6},
    {8,9,2,6,1,6,7,0,6,9,6,6,2,3,6,3,3,8,2,0,1,3,6,3,7,8,4,1,8,3,8,3,6,8,4,1,7,8,7,3,4,3,6,1,7,2,6,7,5,7},
    {2,8,1,1,2,8,7,9,8,1,2,8,4,9,9,7,9,4,0,8,0,6,5,4,8,1,9,3,1,5,9,2,6,2,1,6,9,1,2,7,5,8,8,9,8,3,2,7,3,8},
    {4,4,2,7,4,2,2,8,9,1,7,4,3,2,5,2,0,3,2,1,9,2,3,5,8,9,4,2,2,8,7,6,7,9,6,4,8,7,6,7,0,2,7,2,1,8,9,3,1,8},
    {4,7,4,5,1,4,4,5,7,3,6,0,0,1,3,0,6,4,3,9,0,9,1,1,6,7,2,1,6,8,5,6,8,4,4,5,8,8,7,1,1,6,0,3,1,5,3,2,7,6},
    {7,0,3,8,6,4,8,6,1,0,5,8,4,3,0,2,5,4,3,9,9,3,9,6,1,9,8,2,8,9,1,7,5,9,3,6,6,5,6,8,6,7,5,7,9,3,4,9,5,1},
    {6,2,1,7,6,4,5,7,1,4,1,8,5,6,5,6,0,6,2,9,5,0,2,1,5,7,2,2,3,1,9,6,5,8,6,7,5,5,0,7,9,3,2,4,1,9,3,3,3,1},
    {6,4,9,0,6,3,5,2,4,6,2,7,4,1,9,0,4,9,2,9,1,0,1,4,3,2,4,4,5,8,1,3,8,2,2,6,6,3,3,4,7,9,4,4,7,5,8,1,7,8},
    {9,2,5,7,5,8,6,7,7,1,8,3,3,7,2,1,7,6,6,1,9,6,3,7,5,1,5,9,0,5,7,9,2,3,9,7,2,8,2,4,5,5,9,8,8,3,8,4,0,7},
    {5,8,2,0,3,5,6,5,3,2,5,3,5,9,3,9,9,0,0,8,4,0,2,6,3,3,5,6,8,9,4,8,8,3,0,1,8,9,4,5,8,6,2,8,2,2,7,8,2,8},
    {8,0,1,8,1,1,9,9,3,8,4,8,2,6,2,8,2,0,1,4,2,7,8,1,9,4,1,3,9,9,4,0,5,6,7,5,8,7,1,5,1,1,7,0,0,9,4,3,9,0},
    {3,5,3,9,8,6,6,4,3,7,2,8,2,7,1,1,2,6,5,3,8,2,9,9,8,7,2,4,0,7,8,4,4,7,3,0,5,3,1,9,0,1,0,4,2,9,3,5,8,6},
    {8,6,5,1,5,5,0,6,0,0,6,2,9,5,8,6,4,8,6,1,5,3,2,0,7,5,2,7,3,3,7,1,9,5,9,1,9,1,4,2,0,5,1,7,2,5,5,8,2,9},
    {7,1,6,9,3,8,8,8,7,0,7,7,1,5,4,6,6,4,9,9,1,1,5,5,9,3,4,8,7,6,0,3,5,3,2,9,2,1,7,1,4,9,7,0,0,5,6,9,3,8},
    {5,4,3,7,0,0,7,0,5,7,6,8,2,6,6,8,4,6,2,4,6,2,1,4,9,5,6,5,0,0,7,6,4,7,1,7,8,7,2,9,4,4,3,8,3,7,7,6,0,4},
    {5,3,2,8,2,6,5,4,1,0,8,7,5,6,8,2,8,4,4,3,1,9,1,1,9,0,6,3,4,6,9,4,0,3,7,8,5,5,2,1,7,7,7,9,2,9,5,1,4,5},
    {3,6,1,2,3,2,7,2,5,2,5,0,0,0,2,9,6,0,7,1,0,7,5,0,8,2,5,6,3,8,1,5,6,5,6,7,1,0,8,8,5,2,5,8,3,5,0,7,2,1},
    {4,5,8,7,6,5,7,6,1,7,2,4,1,0,9,7,6,4,4,7,3,3,9,1,1,0,6,0,7,2,1,8,2,6,5,2,3,6,8,7,7,2,2,3,6,3,6,0,4,5},
    {1,7,4,2,3,7,0,6,9,0,5,8,5,1,8,6,0,6,6,0,4,4,8,2,0,7,6,2,1,2,0,9,8,1,3,2,8,7,8,6,0,7,3,3,9,6,9,4,1,2},
    {8,1,1,4,2,6,6,0,4,1,8,0,8,6,8,3,0,6,1,9,3,2,8,4,6,0,8,1,1,1,9,1,0,6,1,5,5,6,9,4,0,5,1,2,6,8,9,6,9,2},
    {5,1,9,3,4,3,2,5,4,5,1,7,2,8,3,8,8,6,4,1,9,1,8,0,4,7,0,4,9,2,9,3,2,1,5,0,5,8,6,4,2,5,6,3,0,4,9,4,8,3},
    {6,2,4,6,7,2,2,1,6,4,8,4,3,5,0,7,6,2,0,1,7,2,7,9,1,8,0,3,9,9,4,4,6,9,3,0,0,4,7,3,2,9,5,6,3,4,0,6,9,1},
    {1,5,7,3,2,4,4,4,3,8,6,9,0,8,1,2,5,7,9,4,5,1,4,0,8,9,0,5,7,7,0,6,2,2,9,4,2,9,1,9,7,1,0,7,9,2,8,2,0,9},
    {5,5,0,3,7,6,8,7,5,2,5,6,7,8,7,7,3,0,9,1,8,6,2,5,4,0,7,4,4,9,6,9,8,4,4,5,0,8,3,3,0,3,9,3,6,8,2,1,2,6},
    {1,8,3,3,6,3,8,4,8,2,5,3,3,0,1,5,4,6,8,6,1,9,6,1,2,4,3,4,8,7,6,7,6,8,1,2,9,7,5,3,4,3,7,5,9,4,6,5,1,5},
    {8,0,3,8,6,2,8,7,5,9,2,8,7,8,4,9,0,2,0,1,5,2,1,6,8,5,5,5,4,8,2,8,7,1,7,2,0,1,2,1,9,2,5,7,7,6,6,9,5,4},
    {7,8,1,8,2,8,3,3,7,5,7,9,9,3,1,0,3,6,1,4,7,4,0,3,5,6,8,5,6,4,4,9,0,9,5,5,2,7,0,9,7,8,6,4,7,9,7,5,8,1},
    {1,6,7,2,6,3,2,0,1,0,0,4,3,6,8,9,7,8,4,2,5,5,3,5,3,9,9,2,0,9,3,1,8,3,7,4,4,1,4,9,7,8,0,6,8,6,0,9,8,4},
    {4,8,4,0,3,0,9,8,1,2,9,0,7,7,7,9,1,7,9,9,0,8,8,2,1,8,7,9,5,3,2,7,3,6,4,4,7,5,6,7,5,5,9,0,8,4,8,0,3,0},
    {8,7,0,8,6,9,8,7,5,5,1,3,9,2,7,1,1,8,5,4,5,1,7,0,7,8,5,4,4,1,6,1,8,5,2,4,2,4,3,2,0,6,9,3,1,5,0,3,3,2},
    {5,9,9,5,9,4,0,6,8,9,5,7,5,6,5,3,6,7,8,2,1,0,7,0,7,4,9,2,6,9,6,6,5,3,7,6,7,6,3,2,6,2,3,5,4,4,7,2,1,0},
    {6,9,7,9,3,9,5,0,6,7,9,6,5,2,6,9,4,7,4,2,5,9,7,7,0,9,7,3,9,1,6,6,6,9,3,7,6,3,0,4,2,6,3,3,9,8,7,0,8,5},
    {4,1,0,5,2,6,8,4,7,0,8,2,9,9,0,8,5,2,1,1,3,9,9,4,2,7,3,6,5,7,3,4,1,1,6,1,8,2,7,6,0,3,1,5,0,0,1,2,7,1},
    {6,5,3,7,8,6,0,7,3,6,1,5,0,1,0,8,0,8,5,7,0,0,9,1,4,9,9,3,9,5,1,2,5,5,7,0,2,8,1,9,8,7,4,6,0,0,4,3,7,5},
    {3,5,8,2,9,0,3,5,3,1,7,4,3,4,7,1,7,3,2,6,9,3,2,1,2,3,5,7,8,1,5,4,9,8,2,6,2,9,7,4,2,5,5,2,7,3,7,3,0,7},
    {9,4,9,5,3,7,5,9,7,6,5,1,0,5,3,0,5,9,4,6,9,6,6,0,6,7,6,8,3,1,5,6,5,7,4,3,7,7,1,6,7,4,0,1,8,7,5,2,7,5},
    {8,8,9,0,2,8,0,2,5,7,1,7,3,3,2,2,9,6,1,9,1,7,6,6,6,8,7,1,3,8,1,9,9,3,1,8,1,1,0,4,8,7,7,0,1,9,0,2,7,1},
    {2,5,2,6,7,6,8,0,2,7,6,0,7,8,0,0,3,0,1,3,6,7,8,6,8,0,9,9,2,5,2,5,4,6,3,4,0,1,0,6,1,6,3,2,8,6,6,5,2,6},
    {3,6,2,7,0,2,1,8,5,4,0,4,9,7,7,0,5,5,8,5,6,2,9,9,4,6,5,8,0,6,3,6,2,3,7,9,9,3,1,4,0,7,4,6,2,5,5,9,6,2},
    {2,4,0,7,4,4,8,6,9,0,8,2,3,1,1,7,4,9,7,7,7,9,2,3,6,5,4,6,6,2,5,7,2,4,6,9,2,3,3,2,2,8,1,0,9,1,7,1,4,1},
    {9,1,4,3,0,2,8,8,1,9,7,1,0,3,2,8,8,5,9,7,8,0,6,6,6,9,7,6,0,8,9,2,9,3,8,6,3,8,2,8,5,0,2,5,3,3,3,4,0,3},
    {3,4,4,1,3,0,6,5,5,7,8,0,1,6,1,2,7,8,1,5,9,2,1,8,1,5,0,0,5,5,6,1,8,6,8,8,3,6,4,6,8,4,2,0,0,9,0,4,7,0},
    {2,3,0,5,3,0,8,1,1,7,2,8,1,6,4,3,0,4,8,7,6,2,3,7,9,1,9,6,9,8,4,2,4,8,7,2,5,5,0,3,6,6,3,8,7,8,4,5,8,3},
    {1,1,4,8,7,6,9,6,9,3,2,1,5,4,9,0,2,8,1,0,4,2,4,0,2,0,1,3,8,3,3,5,1,2,4,4,6,2,1,8,1,4,4,1,7,7,3,4,7,0},
    {6,3,7,8,3,2,9,9,4,9,0,6,3,6,2,5,9,6,6,6,4,9,8,5,8,7,6,1,8,2,2,1,2,2,5,2,2,5,5,1,2,4,8,6,7,6,4,5,3,3},
    {6,7,7,2,0,1,8,6,9,7,1,6,9,8,5,4,4,3,1,2,4,1,9,5,7,2,4,0,9,9,1,3,9,5,9,0,0,8,9,5,2,3,1,0,0,5,8,8,2,2},
    {9,5,5,4,8,2,5,5,3,0,0,2,6,3,5,2,0,7,8,1,5,3,2,2,9,6,7,9,6,2,4,9,4,8,1,6,4,1,9,5,3,8,6,8,2,1,8,7,7,4},
    {7,6,0,8,5,3,2,7,1,3,2,2,8,5,7,2,3,1,1,0,4,2,4,8,0,3,4,5,6,1,2,4,8,6,7,6,9,7,0,6,4,5,0,7,9,9,5,2,3,6},
    {3,7,7,7,4,2,4,2,5,3,5,4,1,1,2,9,1,6,8,4,2,7,6,8,6,5,5,3,8,9,2,6,2,0,5,0,2,4,9,1,0,3,2,6,5,7,2,9,6,7},
    {2,3,7,0,1,9,1,3,2,7,5,7,2,5,6,7,5,2,8,5,6,5,3,2,4,8,2,5,8,2,6,5,4,6,3,0,9,2,2,0,7,0,5,8,5,9,6,5,2,2},
    {2,9,7,9,8,8,6,0,2,7,2,2,5,8,3,3,1,9,1,3,1,2,6,3,7,5,1,4,7,3,4,1,9,9,4,8,8,9,5,3,4,7,6,5,7,4,5,5,0,1},
    {1,8,4,9,5,7,0,1,4,5,4,8,7,9,2,8,8,9,8,4,8,5,6,8,2,7,7,2,6,0,7,7,7,1,3,7,2,1,4,0,3,7,9,8,8,7,9,7,1,5},
    {3,8,2,9,8,2,0,3,7,8,3,0,3,1,4,7,3,5,2,7,7,2,1,5,8,0,3,4,8,1,4,4,5,1,3,4,9,1,3,7,3,2,2,6,6,5,1,3,8,1},
    {3,4,8,2,9,5,4,3,8,2,9,1,9,9,9,1,8,1,8,0,2,7,8,9,1,6,5,2,2,4,3,1,0,2,7,3,9,2,2,5,1,1,2,2,8,6,9,5,3,9},
    {4,0,9,5,7,9,5,3,0,6,6,4,0,5,2,3,2,6,3,2,5,3,8,0,4,4,1,0,0,0,5,9,6,5,4,9,3,9,1,5,9,8,7,9,5,9,3,6,3,5},
    {2,9,7,4,6,1,5,2,1,8,5,5,0,2,3,7,1,3,0,7,6,4,2,2,5,5,1,2,1,1,8,3,6,9,3,8,0,3,5,8,0,3,8,8,5,8,4,9,0,3},
    {4,1,6,9,8,1,1,6,2,2,2,0,7,2,9,7,7,1,8,6,1,5,8,2,3,6,6,7,8,4,2,4,6,8,9,1,5,7,9,9,3,5,3,2,9,6,1,9,2,2},
    {6,2,4,6,7,9,5,7,1,9,4,4,0,1,2,6,9,0,4,3,8,7,7,1,0,7,2,7,5,0,4,8,1,0,2,3,9,0,8,9,5,5,2,3,5,9,7,4,5,7},
    {2,3,1,8,9,7,0,6,7,7,2,5,4,7,9,1,5,0,6,1,5,0,5,5,0,4,9,5,3,9,2,2,9,7,9,5,3,0,9,0,1,1,2,9,9,6,7,5,1,9},
    {8,6,1,8,8,0,8,8,2,2,5,8,7,5,3,1,4,5,2,9,5,8,4,0,9,9,2,5,1,2,0,3,8,2,9,0,0,9,4,0,7,7,7,0,7,7,5,6,7,2},
    {1,1,3,0,6,7,3,9,7,0,8,3,0,4,7,2,4,4,8,3,8,1,6,5,3,3,8,7,3,5,0,2,3,4,0,8,4,5,6,4,7,0,5,8,0,7,7,3,0,8},
    {8,2,9,5,9,1,7,4,7,6,7,1,4,0,3,6,3,1,9,8,0,0,8,1,8,7,1,2,9,0,1,1,8,7,5,4,9,1,3,1,0,5,4,7,1,2,6,5,8,1},
    {9,7,6,2,3,3,3,1,0,4,4,8,1,8,3,8,6,2,6,9,5,1,5,4,5,6,3,3,4,9,2,6,3,6,6,5,7,2,8,9,7,5,6,3,4,0,0,5,0,0},
    {4,2,8,4,6,2,8,0,1,8,3,5,1,7,0,7,0,5,2,7,8,3,1,8,3,9,4,2,5,8,8,2,1,4,5,5,2,1,2,2,7,2,5,1,2,5,0,3,2,7},
    {5,5,1,2,1,6,0,3,5,4,6,9,8,1,2,0,0,5,8,1,7,6,2,1,6,5,2,1,2,8,2,7,6,5,2,7,5,1,6,9,1,2,9,6,8,9,7,7,8,9},
    {3,2,2,3,8,1,9,5,7,3,4,3,2,9,3,3,9,9,4,6,4,3,7,5,0,1,9,0,7,8,3,6,9,4,5,7,6,5,8,8,3,3,5,2,3,9,9,8,8,6},
    {7,5,5,0,6,1,6,4,9,6,5,1,8,4,7,7,5,1,8,0,7,3,8,1,6,8,8,3,7,8,6,1,0,9,1,5,2,7,3,5,7,9,2,9,7,0,1,3,3,7},
    {6,2,1,7,7,8,4,2,7,5,2,1,9,2,6,2,3,4,0,1,9,4,2,3,9,9,6,3,9,1,6,8,0,4,4,9,8,3,9,9,3,1,7,3,3,1,2,7,3,1},
    {3,2,9,2,4,1,8,5,7,0,7,1,4,7,3,4,9,5,6,6,9,1,6,6,7,4,6,8,7,6,3,4,6,6,0,9,1,5,0,3,5,9,1,4,6,7,7,5,0,4},
    {9,9,5,1,8,6,7,1,4,3,0,2,3,5,2,1,9,6,2,8,8,9,4,8,9,0,1,0,2,4,2,3,3,2,5,1,1,6,9,1,3,6,1,9,6,2,6,6,2,2},
    {7,3,2,6,7,4,6,0,8,0,0,5,9,1,5,4,7,4,7,1,8,3,0,7,9,8,3,9,2,8,6,8,5,3,5,2,0,6,9,4,6,9,4,4,5,4,0,7,2,4},
    {7,6,8,4,1,8,2,2,5,2,4,6,7,4,4,1,7,1,6,1,5,1,4,0,3,6,4,2,7,9,8,2,2,7,3,3,4,8,0,5,5,5,5,6,2,1,4,8,1,8},
    {9,7,1,4,2,6,1,7,9,1,0,3,4,2,5,9,8,6,4,7,2,0,4,5,1,6,8,9,3,9,8,9,4,2,2,1,7,9,8,2,6,0,8,8,0,7,6,8,5,2},
    {8,7,7,8,3,6,4,6,1,8,2,7,9,9,3,4,6,3,1,3,7,6,7,7,5,4,3,0,7,8,0,9,3,6,3,3,3,3,0,1,8,9,8,2,6,4,2,0,9,0},
    {1,0,8,4,8,8,0,2,5,2,1,6,7,4,6,7,0,8,8,3,2,1,5,1,2,0,1,8,5,8,8,3,5,4,3,2,2,3,8,1,2,8,7,6,9,5,2,7,8,6},
    {7,1,3,2,9,6,1,2,4,7,4,7,8,2,4,6,4,5,3,8,6,3,6,9,9,3,0,0,9,0,4,9,3,1,0,3,6,3,6,1,9,7,6,3,8,7,8,0,3,9},
    {6,2,1,8,4,0,7,3,5,7,2,3,9,9,7,9,4,2,2,3,4,0,6,2,3,5,3,9,3,8,0,8,3,3,9,6,5,1,3,2,7,4,0,8,0,1,1,1,1,6},
    {6,6,6,2,7,8,9,1,9,8,1,4,8,8,0,8,7,7,9,7,9,4,1,8,7,6,8,7,6,1,4,4,2,3,0,0,3,0,9,8,4,4,9,0,8,5,1,4,1,1},
    {6,0,6,6,1,8,2,6,2,9,3,6,8,2,8,3,6,7,6,4,7,4,4,7,7,9,2,3,9,1,8,0,3,3,5,1,1,0,9,8,9,0,6,9,7,9,0,7,1,4},
    {8,5,7,8,6,9,4,4,0,8,9,5,5,2,9,9,0,6,5,3,6,4,0,4,4,7,4,2,5,5,7,6,0,8,3,6,5,9,9,7,6,6,4,5,7,9,5,0,9,6},
    {6,6,0,2,4,3,9,6,4,0,9,9,0,5,3,8,9,6,0,7,1,2,0,1,9,8,2,1,9,9,7,6,0,4,7,5,9,9,4,9,0,1,9,7,2,3,0,2,9,7},
    {6,4,9,1,3,9,8,2,6,8,0,0,3,2,9,7,3,1,5,6,0,3,7,1,2,0,0,4,1,3,7,7,9,0,3,7,8,5,5,6,6,0,8,5,0,8,9,2,5,2},
    {1,6,7,3,0,9,3,9,3,1,9,8,7,2,7,5,0,2,7,5,4,6,8,9,0,6,9,0,3,7,0,7,5,3,9,4,1,3,0,4,2,6,5,2,3,1,5,0,1,1},
    {9,4,8,0,9,3,7,7,2,4,5,0,4,8,7,9,5,1,5,0,9,5,4,1,0,0,9,2,1,6,4,5,8,6,3,7,5,4,7,1,0,5,9,8,4,3,6,7,9,1},
    {7,8,6,3,9,1,6,7,0,2,1,1,8,7,4,9,2,4,3,1,9,9,5,7,0,0,6,4,1,9,1,7,9,6,9,7,7,7,5,9,9,0,2,8,3,0,0,6,9,9},
    {1,5,3,6,8,7,1,3,7,1,1,9,3,6,6,1,4,9,5,2,8,1,1,3,0,5,8,7,6,3,8,0,2,7,8,4,1,0,7,5,4,4,4,9,7,3,3,0,7,8},
    {4,0,7,8,9,9,2,3,1,1,5,5,3,5,5,6,2,5,6,1,1,4,2,3,2,2,4,2,3,2,5,5,0,3,3,6,8,5,4,4,2,4,8,8,9,1,7,3,5,3},
    {4,4,8,8,9,9,1,1,5,0,1,4,4,0,6,4,8,0,2,0,3,6,9,0,6,8,0,6,3,9,6,0,6,7,2,3,2,2,1,9,3,2,0,4,1,4,9,5,3,5},
    {4,1,5,0,3,1,2,8,8,8,0,3,3,9,5,3,6,0,5,3,2,9,9,3,4,0,3,6,8,0,0,6,9,7,7,7,1,0,6,5,0,5,6,6,6,3,1,9,5,4},
    {8,1,2,3,4,8,8,0,6,7,3,2,1,0,1,4,6,7,3,9,0,5,8,5,6,8,5,5,7,9,3,4,5,8,1,4,0,3,6,2,7,8,2,2,7,0,3,2,8,0},
    {8,2,6,1,6,5,7,0,7,7,3,9,4,8,3,2,7,5,9,2,2,3,2,8,4,5,9,4,1,7,0,6,5,2,5,0,9,4,5,1,2,3,2,5,2,3,0,6,0,8},
    {2,2,9,1,8,8,0,2,0,5,8,7,7,7,3,1,9,7,1,9,8,3,9,4,5,0,1,8,0,8,8,8,0,7,2,4,2,9,6,6,1,9,8,0,8,1,1,1,9,7},
    {7,7,1,5,8,5,4,2,5,0,2,0,1,6,5,4,5,0,9,0,4,1,3,2,4,5,8,0,9,7,8,6,8,8,2,7,7,8,9,4,8,7,2,1,8,5,9,6,1,7},
    {7,2,1,0,7,8,3,8,4,3,5,0,6,9,1,8,6,1,5,5,4,3,5,6,6,2,8,8,4,0,6,2,2,5,7,4,7,3,6,9,2,2,8,4,5,0,9,5,1,6},
    {2,0,8,4,9,6,0,3,9,8,0,1,3,4,0,0,1,7,2,3,9,3,0,6,7,1,6,6,6,8,2,3,5,5,5,2,4,5,2,5,2,8,0,4,6,0,9,7,2,2},
    {5,3,5,0,3,5,3,4,2,2,6,4,7,2,5,2,4,2,5,0,8,7,4,0,5,4,0,7,5,5,9,1,7,8,9,7,8,1,2,6,4,3,3,0,3,3,1,6,9,0}
    };

    for (int y = 49; y >= 0; y --)
    {
        temp = 0;
        for (int x = 0; x < 100; x ++) temp += data[x][y];

        carry[i] = temp;
        i--;
    }

    for (i = 49; i >= 1; i--)
    {
        answer[k] = carry[i] % 10;
        carry[i] /= 10;
        carry[i-1] += carry[i];
        k--;
    }

    answer[k] = carry[0];
    cout << "The 1st 10 digits in the sum of 100 50-digit number: ";
    for (k = 0; k <= 7; k++) cout << answer[k];

    cout << endl;

}

void project2::longest_collatz_sequence() //solution 14
{
    int highest_chain = 0;
    int number = 0;
    int chain, i;
    unsigned int temp;
    for(i = 1; i < 1000000; i++)
    {
        chain = 0;
        temp = i;
        while (temp > 1)
        {
            if(temp%2 == 0)
            {
                temp /= 2;
                chain++;
            }

            else
            {
                temp = (temp*3) + 1;
                chain++;
            }
        }

        if(chain > highest_chain)
         {
            number = i;
            highest_chain = chain;
         }
    }
   cout << "The Highest number of chain below 1000000 is : " << number << "\n1That has a chain of " << chain << endl;
}

void project2::diophantine_reciprocals_a() //solution 15
{

}

int project2::convertCharToNum(char num1) //for problem 16
{
    int num;
    if(num1 == '1') num = 1;
    else if(num1 == '2') num = 2;
    else if(num1 == '3') num = 3;
    else if(num1 == '4') num = 4;
    else if(num1 == '5') num = 5;
    else if(num1 == '6') num = 6;
    else if(num1 == '7') num = 7;
    else if(num1 == '8') num = 8;
    else if(num1 == '9') num = 9;
    else if(num1 == '0') num = 0;
    return num;
}

char project2::convertNumToChar(int num1) //for problem 16
{
    char num;
    if(num1 == 1) num = '1';
    else if(num1 == 2) num = '2';
    else if(num1 == 3) num = '3';
    else if(num1 == 4) num = '4';
    else if(num1 == 5) num = '5';
    else if(num1 == 6) num = '6';
    else if(num1 == 7) num = '7';
    else if(num1 == 8) num = '8';
    else if(num1 == 9) num = '9';
    else if(num1 == 0) num = '0';

    return num;
}
void project2::power_digit_sum() //solution 16
{
    int carry;
    int range_p = 0;
    int num = 0;
    int sum = 0;
    string product = "2";
    string temp = "";
    char temp2;

    for(int i = 2; i <= 1000; i++)
    {
        carry = 0;
        temp = "";

        range_p = product.length();
        for(int k = range_p - 1; k >= 0; k--)
        {
            num = convertCharToNum(product.at(k));
            num *= 2;
            num = num + carry;
            carry = 0;

            if(num > 9)
            {
                int a = num%10;
                carry = (num - a) / 10;
                temp2 = convertNumToChar(a);
                temp = temp2 + temp;
            }

            else
            {
                temp2 = convertNumToChar(num);
                temp = temp2 + temp;
            }

            if(carry > 0 && k == 0)
            {
                temp2 = convertNumToChar(carry);
                temp = temp2 + temp;
            }
        }
        product = temp;
    }

    range_p = product.length();
    for(int i = 0; i < range_p; i++)
    {
        int a = convertCharToNum(product.at(i));
        sum += a;
    }
    cout << sum << endl;

}

void project2::number_letter_counts() //solution 17
{
    string dictionary1[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string dictionary2[18] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    string dictionary3[10] = { "onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred", "onethousand" };

    int sum_of_all_letters=0;
    int i=0,start,j,k;
    while(i<10){
        sum_of_all_letters+=dictionary1[i].length();
        i++;
        }
        sum_of_all_letters-=4;
    i=0;
    while(i<10){
        sum_of_all_letters+=dictionary2[i].length();
        i++;
    }
    start=10;
    while(start<18){
        sum_of_all_letters+=dictionary2[start].length();
        for(i=1; i<10; i++)
        sum_of_all_letters+=dictionary2[start].length()+dictionary1[i].length();
        start++;
    }
    j=0;
    start=10;
    while(j<9){
        sum_of_all_letters+=dictionary3[j].length();
        for(i=1; i<10; i++)
            sum_of_all_letters+=dictionary3[j].length()+dictionary1[i].length()+3;
        for(k=0; k<10; k++)
            sum_of_all_letters+=dictionary3[j].length()+dictionary2[k].length()+3;
        for(int p=10; p<18; p++)
            sum_of_all_letters+=dictionary3[j].length()+dictionary2[p].length()+3;
        while(start<18){
            for(int a=1; a<10; a++)
                sum_of_all_letters+=dictionary3[j].length()+dictionary2[start].length()+dictionary1[a].length()+3;
            start++;
        }
        start=10;
        j++;
    }
    sum_of_all_letters+=dictionary3[9].length();
    cout<<sum_of_all_letters<<endl;
}

int project2::maxsum (int num1, int num2, int up) { //for problem 18
    int biggest = num1;
    if(num2 > biggest)
        biggest = num2;
    return biggest + up;
}


int project2::path(int num, int tri[][15]) { // for problem 18
    for(int i = num-1; i >= 0; i--) {
        for(int j = 0; j+1 < num && tri[i][j+1] != 0; j++)
            tri[i-1][j] = maxsum(tri[i][j], tri[i][j+1], tri[i-1][j]);
    }
    return tri[0][0];
}

void project2::max_path_sum_one() //solution 18
{
int tri [15][15] = {
    {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
    {99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
    {41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};
    cout << path(15, tri) << endl;
}

void project2::counting_sundays() //solution 19
{
    string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int day1 = 1;
    int count_sunday = 0;
    for(int year = 1901; year <= 2000; year++)
    {
        for(int month1 = 0; month1 < 12; month1++)
        {
            if(month[month1] == "January"  || month[month1] == "March"||
                month[month1] == "May" || month[month1] == "July" ||
                month[month1] == "August" || month[month1] == "October" || month[month1] == "December")
                day1 += 3;

            else if(month[month1] == "February")
            {
                if(year%4 == 0)
                {
                    day1++;
                }
            }

            else if(month[month1] == "April" || month[month1] == "June" || month[month1] == "September"
                     || month[month1] == "November") day1 += 2;

            if(day1 > 7) day1 = day1%7;
            if(day[day1] == "Sunday") count_sunday++;
        }
    }
    cout << "The number of Sundays Fells on first of the month from year 1901 to 2000: " << count_sunday << endl;
}

void project2::factorial_digit_sum() //solution 20
{
 int carry;
    int range_p = 0;
    int num = 0;
    int sum = 0;
    string product = "1";
    string temp = "";
    char temp2;

    for(int i = 2; i <= 9; i++)
    {
        carry = 0;
        temp = "";

        range_p = product.length();
        for(int k = range_p - 1; k >= 0; k--)
        {
            num = convertCharToNum(product.at(k));
            num *= i;
            num = num + carry;
            carry = 0;

            if(num > 9)
            {
                int a = num%10;
                carry = (num - a) / 10;
                temp2 = convertNumToChar(a);
                temp = temp2 + temp;
            }

            else
            {
                temp2 = convertNumToChar(num);
                temp = temp2 + temp;
            }

            if(carry > 0 && k == 0)
            {
                temp2 = convertNumToChar(carry);
                temp = temp2 + temp;
            }
        }
        product = temp;
    }

    for(int i = 10; i <= 99; i++)
    {
        ostringstream convert;
        string another;
        convert << i;
        another = convert.str();
        int range_a = another.length();
        string Array[range_a];
        int product_temp = 0;
        carry = 0;
        int i_a = 0;
        for(int j = range_a - 1; j >= 0; j--)
        {

            temp = "";

            int numa = convertCharToNum(another.at(j));
            carry = 0;
            range_p = product.length();
            for(int k = range_p - 1; k >= 0; k--)
            {
                int numb = convertCharToNum(product.at(k));
                int product_temp = (numa * numb) + carry;
                carry = 0;

                if(product_temp > 9)
                {
                    int a = product_temp%10;
                    carry = (product_temp - a) / 10;
                    temp2 = convertNumToChar(a);
                    temp = temp2 + temp;
                }

                else
                {
                    temp2 = convertNumToChar(product_temp);
                    temp = temp2 + temp;
                }

                if(carry > 0 && k == 0)
                {
                    temp2 = convertNumToChar(carry);
                    temp = temp2 + temp;
                }
            }
            Array[i_a] = temp;
            i_a++;
        }
        int range_1 = Array[0].length();
        int range_2 = Array[1].length();

        if(range_1 == range_2)
        {
            Array[0] = "0" + Array[0];
            Array[1] = Array[1] + "0";
        }

        else
        {
            Array[1] = Array[1] + "0";
        }

        range_1 = Array[0].length();
        range_2 = Array[1].length();
        carry = 0;
        temp = "";
        for(int z = range_1 - 1; z >= 0; z--)
        {

            int numa = convertCharToNum(Array[0].at(z));
            int numb = convertCharToNum(Array[1].at(z));
            int sum = numa + numb + carry;
            carry = 0;

            if(sum > 9)
            {
                int a = sum%10;
                carry = (sum - a) / 10;
                temp2 = convertNumToChar(a);
                temp = temp2 + temp;
            }

            else
            {
                temp2 = convertNumToChar(sum);
                temp = temp2 + temp;
            }

            if(carry == 1 && z == 0)
            {
                temp2 = convertNumToChar(carry);
                temp = temp2 + temp;
            }
        }
        product = temp;
    }

    product = product + "00";
    int b = product.length();

    sum = 0;
    for(int i = 0; i < b; i++)
    {
        int num = convertCharToNum(product.at(i));
        sum += num;
    }

    cout << sum << endl;
}

void project2::name_score() // solution 21
{
    ifstream ReadFile;
    string line, temp = "";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int range_c = alphabet.length();
    int rank = 0, letter = 0, product = 0, range = 0, range_n = 0, i_n = 0;
    long int sum = 0;
    ReadFile.open("names.txt");
    getline(ReadFile,line);
    ReadFile.close();
    range = line.length();

    for(int i = 0; i < range; i++)
    {
        if(line.at(i) == '"')
        {
            range_n++;
        }
    }
    range_n /=2;

    string names[range_n];
    for(int i = 1; i < range; i++)
    {
        if(line.at(i) == '"' || line.at(i) == ',')
        {
            if(temp != "")
            {
                names[i_n] = temp;
                temp = "";
                i_n++;
            }
            continue;
        }
        temp += line.at(i);
    }

    for(int i = 0; i < range_n; i++)
    {
        for(int k = 0; k < range_n;k++)
        {
            if(names[i] > names[k])
            {
                string temp_r = names[k];
                names[k] = names[i];
                names[i] = temp_r;
            }
        }
    }

    for(int i = 0; i < range_n; i++)
    {
        letter = 0;
        rank = range_n - i;
        int range_a = names[i].length();
        for(int k = 0; k < range_a; k++)
        {
            for(int j = 0; j < range_c; j++)
            {
                if(names[i].at(k) == alphabet.at(j))
                {
                    letter += j + 1;
                    break;
                }
            }
        }

        product = rank*letter;
        sum += product;
    }

    cout << "The sum of the product of Rank and letter of names is: " <<  sum << endl;

}
