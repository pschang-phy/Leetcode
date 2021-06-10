class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        int i = 0;

        for (auto & q : queries) {
            for (auto & p : points) {
                if ((p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]) <= q[2] * q[2]) {
                    ans[i] += 1;
                }
            }
            i += 1;
        }

        return ans;
    }
};
