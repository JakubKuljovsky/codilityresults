
#include <cmath>


int solution(std::vector<int>& A)
{
    int sizeOfA = A.size();

    // trivial cases 
    if (sizeOfA < 3)
    {
        return 0;
    }

    // count factors - all factors for array division
    std::vector<int> countFactors;
    int numberOfFactor{ 0 };
    int sN = sqrt(sizeOfA) + 1;


    for (int i = 1; i < sN; ++i)
    {
        if (sizeOfA % i == 0)
        {
            countFactors.push_back(i);

            if (sizeOfA / i > i)
            {
                countFactors.push_back(sizeOfA / i);
            }
        }
    }

    // sort them
    std::sort(countFactors.begin(), countFactors.end(), [](int first, int second) { return first > second;});

    // find all peaks
    std::vector<int> peaks;
    for (unsigned int i = 1; i < sizeOfA - 1; ++i)
    {
        if (A[i - 1] < A[i] and A[i] > A[i + 1])
        {
            peaks.push_back(i);
        }
    }


    // trivial cases 
    if (peaks.size() == 0)
    {
        return 0;
    }

 
    for (unsigned int i = 0; i < countFactors.size(); ++i)
    {
        int lengthOfSegments = sizeOfA / countFactors[i];

        //peak distribution in segments
        int segment{0};
        for (unsigned int j = 0; j < peaks.size(); ++j)
        {
            //  peak / segment -> (segment where is peak) - 1
            if (peaks[j] / lengthOfSegments == segment) segment++;
        }

        if (segment == countFactors[i])
        {
            return countFactors[i];
        }
    }
    // only one big segment
    return 1;
}
