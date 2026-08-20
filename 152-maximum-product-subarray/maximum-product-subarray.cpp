class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int worst = nums[0];
        int best = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int a = nums[i] * best;
            int b = nums[i] * worst;
            int c = nums[i];

            best = max(c, max(a, b));
            worst = min(c, min(a, b));

            ans = max(ans, best);
        }

        return ans;
    }
};