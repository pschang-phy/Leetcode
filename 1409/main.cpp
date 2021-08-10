class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P(m);
        iota(P.begin(), P.end(), 0);

        vector<int> result(queries.size());
        int count = 0;
        for (int i = 0; i < queries.size(); i++) {
            result[i] = P[queries[i] - 1];
            count = 0;
            for (auto& p : P) {
                if (p < result[i]) {
                    p += 1;
                    count += 1;
                    if (count == result[i]) {
                        break;
                    }
                }
            }
            P[queries[i] - 1] = 0;
        }

        return result;
    }
};
