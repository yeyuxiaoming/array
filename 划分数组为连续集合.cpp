/*1296����һ����������?nums?��һ��������?k�������ж��Ƿ���԰�������黮�ֳ�һЩ��?k?������������ɵļ��ϡ�
������ԣ��뷵��?True�����򣬷���?False��
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
                auto it = next(iter);//next����iter����һ��
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

