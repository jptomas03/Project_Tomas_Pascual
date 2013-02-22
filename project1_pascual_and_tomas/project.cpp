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

void project2::divisible_triangular_number() //solution 12
{

}

void project2::largest_sum() //solution 13
{
    string a[100] ={"37107287533902102798797998220837590246510135740250",
                    "46376937677490009712648124896970078050417018260538",
                    "74324986199524741059474233309513058123726617309629",
                    "91942213363574161572522430563301811072406154908250",
                    "23067588207539346171171980310421047513778063246676",
                    "89261670696623633820136378418383684178734361726757",
                    "28112879812849979408065481931592621691275889832738",
                    "44274228917432520321923589422876796487670272189318",
                    "47451445736001306439091167216856844588711603153276",
                    "70386486105843025439939619828917593665686757934951",
                    "62176457141856560629502157223196586755079324193331",
                    "64906352462741904929101432445813822663347944758178",
                    "92575867718337217661963751590579239728245598838407",
                    "58203565325359399008402633568948830189458628227828",
                    "80181199384826282014278194139940567587151170094390",
                    "35398664372827112653829987240784473053190104293586",
                    "86515506006295864861532075273371959191420517255829",
                    "71693888707715466499115593487603532921714970056938",
                    "54370070576826684624621495650076471787294438377604",
                    "53282654108756828443191190634694037855217779295145",
                    "36123272525000296071075082563815656710885258350721",
                    "45876576172410976447339110607218265236877223636045",
                    "17423706905851860660448207621209813287860733969412",
                    "81142660418086830619328460811191061556940512689692",
                    "51934325451728388641918047049293215058642563049483",
                    "62467221648435076201727918039944693004732956340691",
                    "15732444386908125794514089057706229429197107928209",
                    "55037687525678773091862540744969844508330393682126",
                    "18336384825330154686196124348767681297534375946515",
                    "80386287592878490201521685554828717201219257766954",
                    "78182833757993103614740356856449095527097864797581",
                    "16726320100436897842553539920931837441497806860984",
                    "48403098129077791799088218795327364475675590848030",
                    "87086987551392711854517078544161852424320693150332",
                    "59959406895756536782107074926966537676326235447210",
                    "69793950679652694742597709739166693763042633987085",
                    "41052684708299085211399427365734116182760315001271",
                    "65378607361501080857009149939512557028198746004375",
                    "35829035317434717326932123578154982629742552737307",
                    "94953759765105305946966067683156574377167401875275",
                    "88902802571733229619176668713819931811048770190271",
                    "25267680276078003013678680992525463401061632866526",
                    "36270218540497705585629946580636237993140746255962",
                    "24074486908231174977792365466257246923322810917141",
                    "91430288197103288597806669760892938638285025333403",
                    "34413065578016127815921815005561868836468420090470",
                    "23053081172816430487623791969842487255036638784583",
                    "11487696932154902810424020138335124462181441773470",
                    "63783299490636259666498587618221225225512486764533",
                    "67720186971698544312419572409913959008952310058822",
                    "95548255300263520781532296796249481641953868218774",
                    "76085327132285723110424803456124867697064507995236",
                    "37774242535411291684276865538926205024910326572967",
                    "23701913275725675285653248258265463092207058596522",
                    "29798860272258331913126375147341994889534765745501",
                    "18495701454879288984856827726077713721403798879715",
                    "38298203783031473527721580348144513491373226651381",
                    "34829543829199918180278916522431027392251122869539",
                    "40957953066405232632538044100059654939159879593635",
                    "29746152185502371307642255121183693803580388584903",
                    "41698116222072977186158236678424689157993532961922",
                    "62467957194401269043877107275048102390895523597457",
                    "23189706772547915061505504953922979530901129967519",
                    "86188088225875314529584099251203829009407770775672",
                    "11306739708304724483816533873502340845647058077308",
                    "82959174767140363198008187129011875491310547126581",
                    "97623331044818386269515456334926366572897563400500",
                    "42846280183517070527831839425882145521227251250327",
                    "55121603546981200581762165212827652751691296897789",
                    "32238195734329339946437501907836945765883352399886",
                    "75506164965184775180738168837861091527357929701337",
                    "62177842752192623401942399639168044983993173312731",
                    "32924185707147349566916674687634660915035914677504",
                    "99518671430235219628894890102423325116913619626622",
                    "73267460800591547471830798392868535206946944540724",
                    "76841822524674417161514036427982273348055556214818",
                    "97142617910342598647204516893989422179826088076852",
                    "87783646182799346313767754307809363333018982642090",
                    "10848802521674670883215120185883543223812876952786",
                    "71329612474782464538636993009049310363619763878039",
                    "62184073572399794223406235393808339651327408011116",
                    "66627891981488087797941876876144230030984490851411",
                    "60661826293682836764744779239180335110989069790714",
                    "85786944089552990653640447425576083659976645795096",
                    "66024396409905389607120198219976047599490197230297",
                    "64913982680032973156037120041377903785566085089252",
                    "16730939319872750275468906903707539413042652315011",
                    "94809377245048795150954100921645863754710598436791",
                    "78639167021187492431995700641917969777599028300699",
                    "15368713711936614952811305876380278410754449733078",
                    "40789923115535562561142322423255033685442488917353",
                    "44889911501440648020369068063960672322193204149535",
                    "41503128880339536053299340368006977710650566631954",
                    "81234880673210146739058568557934581403627822703280",
                    "82616570773948327592232845941706525094512325230608",
                    "22918802058777319719839450180888072429661980811197",
                    "77158542502016545090413245809786882778948721859617",
                    "72107838435069186155435662884062257473692284509516",
                    "20849603980134001723930671666823555245252804609722",
                    "53503534226472524250874054075591789781264330331690"};
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

void project2::power_digit_sum() //solution 16
{

}

void project2::number_letter_counts() //solution 17
{

}

void project2::max_path_sum_one() //solution 18
{

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

}
