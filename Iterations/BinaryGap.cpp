/*
BinaryGap: Find longest sequence of zeros in binary representation of an integer.
-----------------------------------------------------------------------------------------------
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that 
is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 
The number 529 has binary representation 1000010001 and contains two binary gaps: one of 
length 4 and one of length 3. The number 20 has binary representation 10100 and contains one
binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. 
The number 32 has binary representation 100000 and has no binary gaps.

Write a function:
  int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function
should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation
10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should
return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:
 * N is an integer within the range [1..2,147,483,647].
*/

// The principle of solving this problem will be that 
// I gradually remove the digits from the end of the number 
// using modulo operations and dividing by 2, which will give me 1 or 0.
// by counting the zeros in the gap and comparing the size of the gaps, 
// I get the biggest gap size.
int solution(int N) {
   // biggestGapSize holds the largest gapSize.
   int biggestGapSize{0};
   // startCounting is true if one of the digits was already 1
   bool startCounting{false};
   // gapSize is the counter for the current gap.
   int gapSize{0};

   while (N != 1)
   {
       // In these two lines, we store the lowest digit in the variable binaryDigit
       // and remove it from the entered number N.
       int binaryDigit{N % 2};
       N /= 2;

       if (startCounting == true and binaryDigit == 0)
       {
            // If the variable binaryDigit is zero and the variable startCounting is true, 
            // then it means that we are in a gap, so we add one to the variable gap
            // and go to the next binaryDigit.
            gapSize++;
       }
       else if (startCounting == true and binaryDigit == 1) 
       {
            // If the variable binaryDigit is equal to 1 and the variable startCounting is true,
            // then we are at the end of the gap,
            // we compare the current gap size with the largest gap size and keep the largest.
            biggestGapSize = std::max(gapSize, biggestGapSize);
            gapSize = 0;
       }
       else if (binaryDigit == 1)
       {
           // If the binaryDigit variable is equal to 1 but the startCounting variable is false,
           // then we are at the beginning of the first gap and we can start counting the gap sizes.
           startCounting = true;
       }
   }

   // Since we are going from behind, our last digit is one and closes the gap.
   return  std::max(gapSize, biggestGapSize);
}
