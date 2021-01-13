class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        /*±©Á¦·¨
        int n = nums.size();
        if(n == 0) return 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum >= s) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
        */
        /*Ë«Ö¸Õë*/
        int n = nums.size();
        if(n == 0) return 0;
        int ans = INT_MAX;
        int star = 0, end = 0;
        int sum = 0;
        while(end < n) {
            sum += nums[end];
            while(sum >= s) {
                ans = min(ans, end - star + 1);
                sum -= nums[star];
                star++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

