class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(noofsubarray(nums,mid) > k){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return low; 
    }


    int noofsubarray(vector<int>& nums , int totalnumber){
        int subarray=1;
        int number=0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]+ number <= totalnumber){
                number+=nums[i];
            }
            else{
                subarray++;
                number=nums[i];
            }
        }
        return subarray;
    }
};