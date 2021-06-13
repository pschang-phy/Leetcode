class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] < b[0];
             });

        int widestL = 0;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] - points[i - 1][0] > widestL) {
                widestL = points[i][0] - points[i - 1][0];
            }
        }

        return widestL;
    }
};
