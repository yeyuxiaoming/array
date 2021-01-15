/*1296给你一个整数数组?nums?和一个正整数?k，请你判断是否可以把这个数组划分成一些由?k?个连续数字组成的集合。
如果可以，请返回?True；否则，返回?False。
*/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        map<int,int> mp;
        for(auto &num : nums) {
            ++mp[num];
        }
        for(auto iter = mp.begin(); iter != mp.end(); ++iter) {
            int f = iter->first;
            int s = iter->second;
            if(s > 0) {
                auto it = next(iter);//next返回iter的下一个
                for(auto i = 1; i < k; i++,it++) {
                    if(it != mp.end() && it->first == f + i && it->second >= s) {
                        it->second -= s;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

