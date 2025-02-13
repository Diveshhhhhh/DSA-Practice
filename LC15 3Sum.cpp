class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1,right=nums.size()-1;
            int target=-nums[i];
            while(left<right){
                int total=nums[left]+nums[right];
                if(total==target){
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[right]==nums[right-1]) right--;
                    while(left<right && nums[left]==nums[left+1]) left++;
                    left++;
                    right--;
                }else if(target>total) left++;
                else right--;
            }
        }
        return res;
    }
};