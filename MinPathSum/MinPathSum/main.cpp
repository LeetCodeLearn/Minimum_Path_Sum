//
//  main.cpp
//  MinPathSum
//
//  Created by 李佳 on 14/12/6.
//  Copyright (c) 2014年 LiJia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        if (grid.size() == 0)
            return 0;
        if (grid[0].size() == 0)
            return 0;
        vector<vector<int>> minSumResult;
        for (int i = 0; i < grid.size();  ++i)
        {
            vector<int> sumVec;
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (i == 0 && j == 0)
                    sumVec.push_back(grid[i][j]);
                else
                {
                    int minValue = grid[i][j];
                    
                    int leftMin = minValue;
                    int topMin = minValue;
                    if (i - 1 >= 0)
                        topMin += minSumResult[i - 1][j];
                    else
                        topMin += INT_MAX / 2;
                    
                    if (j - 1 >= 0)
                        leftMin += sumVec[j - 1];
                    else
                        leftMin += INT_MAX / 2;
                    minValue = min(leftMin, topMin);
                    sumVec.push_back(minValue);
                }
            }
            minSumResult.push_back(sumVec);
        }
        return minSumResult[grid.size() - 1][grid[0].size() - 1];
    }
};

int main(int argc, const char * argv[])
{
    vector<vector<int>> vec{{1,2}, {1, 1}};
    Solution obj;
    std::cout << obj.minPathSum(vec) << std::endl;
    return 0;
}
