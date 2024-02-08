

int solution(int K, vector<int> &A) {
   int count{0};
   int ropeLength{0};

   for (unsigned int i = 0; i < A.size(); ++i)
   {
       ropeLength += A[i];
       if (ropeLength >= K)
       {
            ropeLength = 0;
            count++;
       }
   }
   return count;
}
