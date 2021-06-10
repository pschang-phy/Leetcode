class Solution {
public:
    int minPartitions(string n) {
        char maximum = n[0];
        for (int i = 0; i < n.length(); i++) {
            if (n[i] > maximum) {
                maximum = n[i];
            }
        }

        return maximum - '0';
    }
};
