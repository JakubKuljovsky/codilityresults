
#include <cmath>

int solution(int N) {

   int numberOfFactor{0};
   int sN = sqrt(N) + 1;

   for (int i = 1; i < sN; ++i)
   {
       if (N % i == 0)
       {
            numberOfFactor++;

            if (N / i > i)
            {
                numberOfFactor++;
            }
       }
   }

   return numberOfFactor;
}
