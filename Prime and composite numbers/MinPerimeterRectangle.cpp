
#include <cmath>

int solution(int N) {

   int sN = sqrt(N) + 1;

   for (int i = sN; i > 1 ; --i)
   {
       if (N % i == 0)
       {
            return  2* (i + (N/i));
       }
   }

   return 2 * (N + 1);
}
