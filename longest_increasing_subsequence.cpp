// https://app.codesignal.com/challenge/xux4yj5CyE9bP8BHi

int solution(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }

    return maxLength;
}
