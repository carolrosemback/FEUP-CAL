// By: Gonçalo Leão

#include "exercises.h"

bool changeMakingGreedy(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    for(int j = 0; j < n; j ++)
        usedCoins[j] = 0;

    for(unsigned int i = n -1; T > 0 && i >= 0; i--)
    {
        if(Stock[i] > 0 && C[i] <= T)
        {
            int n_moed = std::min(Stock[i], T/C[i]);
            usedCoins[i] += n_moed;
            T -= n_moed * C[i];
        }
    }
    if(T>0)
        return false;
    else
        return true;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex4, hasGreedyChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingGreedy(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingGreedy(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex4, hasNoGreedyChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingGreedy(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingGreedy(C,Stock,n,1,usedCoins), false);
}