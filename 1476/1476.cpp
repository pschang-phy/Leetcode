class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        for (auto & row : rectangle) {
            m_Rectangle.push_back(std::move(row));
        }
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int row = row1; row <= row2; row++) {
            std::fill(m_Rectangle[row].begin() + col1, m_Rectangle[row].begin() + col2 + 1, newValue);
        }
    }

    int getValue(int row, int col) {
        return m_Rectangle[row].at(col);
    }

private:
    vector<vector<int>> m_Rectangle;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
