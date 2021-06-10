class Solution {
public:
    vector<int> minOperations(string boxes) {
        std::vector<int> ballsLocation;
        for (int i = 0; i < boxes.length(); i++) {
            if (boxes[i] - '0' > 0) {
                ballsLocation.push_back(i);
            }
        }

        std::vector<int> answer(boxes.length(), 0);
        for (int i = 0; i < boxes.length(); i++) {
            for (auto loc : ballsLocation) {
                answer[i] += std::abs(i - loc);
            }
        }

        return answer;
    }
};
