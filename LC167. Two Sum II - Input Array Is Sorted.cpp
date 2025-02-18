class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int left=0;
            int right=numbers.size()-1;
            while(left<right){
                int res=numbers[left]+numbers[right];
                if(res==target){
                    return {left+1,right+1};
                }else if(res>target) right--;
                else left++;
            }
            return {};
        }
    };