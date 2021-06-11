class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> leftRightSkyline;
        for (auto row : grid) {
            leftRightSkyline.push_back(*max_element(row.begin(), row.end()));
        }

        int maxTotalSum = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            int maxTopBottom = grid[0][i];
            for (int j = 1; j < grid.size(); j++) {
                if (grid[j][i] > maxTopBottom) {
                    maxTopBottom = grid[j][i];
                }
            }

            for (int j = 0; j < grid.size(); j++) {
                if (maxTopBottom < leftRightSkyline[j]) {
                    maxTotalSum += (maxTopBottom - grid[j][i]);
                } else {
                    maxTotalSum += (leftRightSkyline[j] - grid[j][i]);
                }
            }
        }

        return maxTotalSum;
    }
};
