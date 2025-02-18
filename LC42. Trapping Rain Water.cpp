class Solution {
    public:
        int trap(vector<int>& height) {
            int left=0,right=height.size()-1;
            int lmax=0,rmax=0,waterSum=0;
            while(left<right){
                if(height[left]<=height[right]){
                    if(height[left]>=lmax) lmax=height[left];
                    else waterSum=waterSum+lmax-height[left];
                    left++;
                }else{
                    if(height[right]>=rmax) rmax=height[right];
                    else waterSum=waterSum+rmax-height[right];
                    right--;
                }
            }
            return waterSum;
        }
    };