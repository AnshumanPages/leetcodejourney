class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return totalsubarr(nums,goal)-totalsubarr(nums,goal-1);
    }
    int totalsubarr(vector<int>& nums, int goal){
         if (goal < 0) return 0;
        int l=0,r=0,cnt=0,sum=0;
        while(r<nums.size()){
            sum=sum+nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
            
        }
        return cnt;
    }
};