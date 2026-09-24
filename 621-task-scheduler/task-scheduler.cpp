class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        // Count frequency
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        // Sort frequencies
        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];

        // Number of empty spaces
        int spaces = (maxFreq - 1) * n;

        // Fill spaces using other tasks
        for (int i = 24; i >= 0; i--) {
            spaces -= min(maxFreq - 1, freq[i]);
        }

        if (spaces > 0)
            return tasks.size() + spaces;

        return tasks.size();
    }
};