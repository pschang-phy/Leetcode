class Solution {
public:
    using Index = pair<int, int>;

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<Index> starts{Index(0, 0)};

        for (int i = 1; i < mat.size(); i++) {
            starts.emplace_back(i, 0);
        }

        for (int i = 1; i < mat.front().size(); i++) {
            starts.emplace_back(0, i);
        }

        for (auto& s : starts) {
            vector<int> matrixDiagonal = getMatrixDiagonal(mat, s.first, s.second);
            sort(matrixDiagonal.begin(), matrixDiagonal.end());
            setMatrixDiagonal(matrixDiagonal, mat, s.first, s.second);
        }

        return mat;
    }

    vector<int> getMatrixDiagonal(const vector<vector<int>>& mat, int rowIdx, int colIdx) {
        const auto rows = mat.size();
        const auto cols = mat.front().size();

        vector<int> matrixDiagonal;
        while (rowIdx < rows && colIdx < cols) {
            matrixDiagonal.push_back(mat[rowIdx][colIdx]);
            rowIdx += 1;
            colIdx += 1;
        }

        return matrixDiagonal;
    }

    void setMatrixDiagonal(const vector<int>& matrixDiagonal, vector<vector<int>>& mat, int rowIdx, int colIdx) {
        const auto rows = mat.size();
        const auto cols = mat.front().size();

        int i = 0;
        while (i < matrixDiagonal.size() && rowIdx < rows && colIdx < cols) {
            mat[rowIdx][colIdx] = matrixDiagonal[i++];
            rowIdx += 1;
            colIdx += 1;
        }
    }
};
