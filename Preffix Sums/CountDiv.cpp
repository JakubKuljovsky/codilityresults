
int solution(int A, int B, int K) {
    int number{0};
    if (A == 0)
    {
        number = B / K;
        number++;
    }
    else
    {
       number = (B / K) - ((A - 1) / K);
    }
    return number;
}
