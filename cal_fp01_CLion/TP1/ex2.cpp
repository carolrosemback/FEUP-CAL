// By: Gonçalo Leão

#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = A[0];
    i = 0;
    j = 0;

    for(int k = 0; k < n; k++)
    {
        for(int m = k; m < n; m++)
        {
            int currentIndex = k;
            int currentsum = 0;
            while(currentIndex <= m)
            {
                currentsum += A[currentIndex];
                currentIndex++;
            }
            if(currentsum >= maxSum)
            {
                i = k;
                j = m;
                maxSum = currentsum;
            }
        }
    }
    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}