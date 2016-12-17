#include <iostream>
#include <vector>
#include <ctime>
  
using namespace std;
  
int main()
{
     clock_t start = clock();
  
     const int AIM = 10000;
  
     vector<int> prime_nums;
     prime_nums.push_back(2);
  
     for (int num = 3; prime_nums.size() < AIM; num += 2)
     {
         bool isprime = true;
         for (int i = 3; i <= num / 2; i += 2)
         {
             if (num % i == 0)
             {
                 isprime = false;
                 break;
             }
         }
  
         if (isprime)
             prime_nums.push_back(num);
     }
  
     cout << prime_nums[AIM - 1];
  
     clock_t end = clock();
     cout << "\n----------------" << endl;
     cout << "Time: " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;
}