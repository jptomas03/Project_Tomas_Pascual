#ifndef project_H
#define project_H


class project
{
    public:
        project();

    void multiples_3_and_5();//done1
    void even_fibonacce();//done2
    void largest_prime_factor();//done3
    void largest_palindrome_product();//done4
    void smallest_multiple();//done5
    void sum_square_diff();//done6
    void the_10001st_prime();//done7
    void largest_product_in_series();//done8
    void special_pytho_triplet();//done9
    bool primeno(int num);
    void summation_of_primes();//done10
};


class project2
{
  public:
   project2();

   void largest_product_grid(); //done
   int getdivisors(int num1); //for solution 12
   void divisible_triangular_number(); //done
   void largest_sum(); //done
   void longest_collatz_sequence(); //done
   void diophantine_reciprocals_a();
   int convertCharToNum(char num1); //for solution 16
   char convertNumToChar(int num1); //for solution 16
   void power_digit_sum();//done
   void number_letter_counts();
   int maxsum (int num1, int num2, int up); // for solution 18
   int path(int num, int tri[][15]); // for solution 18
   void max_path_sum_one();// done
   void counting_sundays(); //done
   void factorial_digit_sum();
   void name_score(); //done
};
#endif // project_H
