class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<int> idx(groupSizes.size());
        iota(idx.begin(), idx.end(), 0);

        stable_sort(idx.begin(), idx.end(),
                    [&groupSizes](int i1, int i2) {return groupSizes[i1] < groupSizes[i2];});

        vector<vector<int>> group;
        int at = 0;
        while (at < groupSizes.size()) {
            int groupSize = groupSizes[idx[at]];
            group.push_back(vector<int>(idx.begin() + at, idx.begin() + at + groupSize));
            at += groupSize;
        }
        
        return group;
    }
};
