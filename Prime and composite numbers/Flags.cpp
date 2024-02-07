

int solution(vector<int> &A) {
    if (A.size() < 3)
    {
        return 0;
    }

    int numberOfFlags{1};
    int numberOfSetFlags{0};
    int maxNumberOfFlags{0};

    for (unsigned int i = 1; i < A.size() - 1; ++i)
    {
        if (A[i -1] < A[i] and A[i] > A[i + 1])
        {
            numberOfSetFlags++;
            if (numberOfSetFlags == numberOfFlags)
            {
                maxNumberOfFlags = std::max(maxNumberOfFlags, numberOfFlags);
                numberOfSetFlags = 0;
                i = 0;
                numberOfFlags++;

            }
            else
            {
                i += numberOfFlags - 1;
            }
        } 
    }

    return  maxNumberOfFlags;
}
