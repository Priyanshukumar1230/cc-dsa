class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(int start, int k, int n) {

        if (subset.size() == k && n == 0) {
            ans.push_back(subset);
            return;
        }

        if (subset.size() == k || n <= 0)
            return;

        for (int i = start; i <= 9; i++) {

            subset.push_back(i);

            backtrack(i + 1, k, n - i);

            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        backtrack(1, k, n);

        return ans;
    }
};