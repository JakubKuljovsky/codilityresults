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

// The principle of solving this problem is to gradually remove the digits from the end
// using modulo operations and dividing by 2, which will give either 1 or 0.
// By counting the zeros in the gap and comparing the size of the gaps, 
// we can find the largest gap size.
int solution(int N) {
   // biggestGapSize holds the largest gapSize.
   int biggestGapSize{0};
   // startCounting is true if we have already encountered a 1.
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
            // If binaryDigit is zero and startCounting is true, 
            // we are in a gap, so we increment gapSize 
            // and proceed to the next binaryDigit.
            gapSize++;
       }
       else if (startCounting == true and binaryDigit == 1) 
       {
            // If binaryDigit is 1 and startCounting is true,
            // we've reached the end of a gap.
            // Compare the current gap size with the largest gap size
            // and store the largest.
            biggestGapSize = std::max(gapSize, biggestGapSize);
            gapSize = 0;
       }
       else if (binaryDigit == 1)
       {
           // If binaryDigit is 1 but startCounting is false,
           // we are at the beginning of the first gap and can start counting the gap sizes.
           startCounting = true;
       }
   }

   // Since we are processing from the least significant bit,
   // the last digit is 1, which closes the gap.
   return  std::max(gapSize, biggestGapSize);
}
