class Solution {
public:
vector<vector<int>> ans;
 void fun(vector<int>&nums, vector<int> &subset ,int index){
    if(index==nums.size()){
        ans.push_back(subset);
        return;
        
    }
    subset.push_back(nums[index]);
    fun(nums,subset,index+1);
    subset.pop_back();
     fun(nums,subset,index+1);

 }



    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> subset;
       fun(nums,subset,0);
       return ans;

      
        }
    
};