class Solution {
public:
//    int findMax(vector<int> &piles){
//         int n=piles.size();
//        int maxi=INT_MIN;
//        for(int i =0 ;i< n ;i++){
//         maxi= max(maxi,piles[i]);

//        }
//        return maxi;
    

    long long calculatetotalHours(vector<int> &piles , int hourly){
        long long totalhours=0;
        for(int i=0 ;i<piles.size(); i++){
        double tf= double(piles[i])/double(hourly);
        totalhours+=ceil(tf);
        }
        return totalhours;
    }


        

    int minEatingSpeed(vector<int>& piles, int h) {
       int low=1;
        int high= *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
         long long totalh=calculatetotalHours(piles,mid);
            if(totalh<=h){
                 high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
