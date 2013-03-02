#include <iostream>
#include <string>
#include <cstdlib>
#include "project.h"

using namespace std;



const string PROBLEMS[]={
    "Multiples of 3 and 5",
    "Even Fibonacci",
    "Largest Prime Factor",
    "Largest Palindrome Product",
    "Smallest Multiple",
    "Sum and Square Difference",
    "The 10001st Prime Number",
    "Largest Product in Series",
    "Special Phythagoran Triplet",
    "Summation of Primes",
    "Largest product in a grid",
    "Highly Divisible triangular number",
    "Large Sum",
    "Longest Collatz sequence",
    "Diophantine reciprocals A",
    "Power Digit sum",
    "Number letter counts",
    "Maximun Path sum I",
    "Counting sundays",
    "Factorial Digit sum",
    "Name Score",
    "Exit"
};

const int NUM_PROBLEMS = 21;

const int EXIT = NUM_PROBLEMS + 1;
int main (){
    project pro;
    project2 pro2;
    int ch=0;

    bool done=false;

    while (done == false){
        system("cls");

        for(int i=0; i<(NUM_PROBLEMS+1); i++){
            cout << (i+1) << ". " << PROBLEMS[i]<< endl;

        }

    cout<< "Choose a problem: ";

    cin >> ch;

        switch (ch){

            case 1:

                pro.multiples_3_and_5();
                system("pause");
                break;

            case 2:
                pro.even_fibonacce();
                system("pause");
                break;

            case 3:

                pro.largest_prime_factor();
                system("pause");
                break;

            case 4:

                pro.largest_palindrome_product();
                system("pause");
                break;

            case 5:

                pro.smallest_multiple();
                system("pause");
                break;

            case 6:

                pro.sum_square_diff();
                system("pause");
                break;

            case 7:

                pro.the_10001st_prime();
                system("pause");
                break;

            case 8:

                pro.largest_product_in_series();
                system("pause");
                break;

            case 9:

                pro.special_pytho_triplet();
                system("pause");
                break;

            case 11:

                pro2.largest_product_grid();
                system("pause");
                break;

            case 12:

                pro2.divisible_triangular_number();
                system("pause");
                break;

            case 13:

                pro2.largest_sum();
                system("pause");
                break;

            case 14:

                pro2.longest_collatz_sequence();
                system("pause");
                break;

            case 15:

                pro2.diophantine_reciprocals_a();
                system("pause");
                break;

            case 16:

                pro2.power_digit_sum();
                system("pause");
                break;

            case 17:

                pro2.number_letter_counts();
                system("pause");
                break;

            case 18:

                pro2.max_path_sum_one();
                system("pause");
                break;

            case 19:

                pro2.counting_sundays();
                system("pause");
                break;

            case 20:

                pro2.factorial_digit_sum();
                system("pause");
                break;

            case 21:
                pro2.name_score();
                system("pause");
                break;

            case EXIT:
            done=true;
            break;
        }
    }//closing bracket of while
return 0;
}// closing bracket of main
