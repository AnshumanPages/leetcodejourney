class Solution {
public:
 const long long mod = 1000000007;
    long long power(long long x ,long long y){
       
        if(y==0) return 1;
        long long ans=power(x,y/2);
        ans*=ans;
        ans%=mod;
        if(y%2==1) ans*=x;
        ans%=mod;
        return ans;


    }
    int countGoodNumbers(long long n) {
       long long even=(n+1)/2;
       long long odd=(n/2);
       return (power(4,odd)*power(5,even))%mod;

    }
};