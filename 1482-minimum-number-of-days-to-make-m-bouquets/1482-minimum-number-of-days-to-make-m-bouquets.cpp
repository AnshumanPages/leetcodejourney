class Solution {
public:

       bool possibledays(vector<int> &bloomDay ,int day, int m,int k){
        int cnt=0;
        int noofB = 0;
        for(int i=0;i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                cnt++;
                
            }
            else{
                noofB+=(cnt/k);
                cnt=0;
            }
            
        }
         noofB+=(cnt/k);
           return noofB>=m;
       }
        
       
 int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;
        
        int n=bloomDay.size();
       int maxi=INT_MIN;
       int mini= INT_MAX;
       for(int i =0 ;i< n ;i++){
        maxi= max(maxi,bloomDay[i]);
         mini= min(mini,bloomDay[i]);
       }
        
         int low=mini;
        int high = maxi;
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(possibledays(bloomDay,mid,m,k) == true){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }

    
};