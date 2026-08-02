class Solution {
public:
      int totalsum(vector<int> &weights){
        int sum=0;
        for(int i=0 ; i<weights.size(); i++){
            sum+=weights[i];
        }
         return sum;
      }
     
       
       int noofdays(vector<int> &weights ,int cap){
        int load=0;
        int days=1;
         for(int i=0 ; i<weights.size(); i++){
            if((load+weights[i])>cap){
                days+=1;
                load=weights[i];
            }
            else {
                load+=weights[i];
            }
         }
       return days;
       }



    int shipWithinDays(vector<int>& weights, int days) {
       int low=*max_element(weights.begin(),weights.end());
        int high=totalsum(weights);
        while(low<=high){
            int mid=(low+high)/2;
            if(noofdays(weights,mid)<= days){
                high=mid-1;
            }
            else{ low=mid+1;
            }
        }
        return low;
    }
};