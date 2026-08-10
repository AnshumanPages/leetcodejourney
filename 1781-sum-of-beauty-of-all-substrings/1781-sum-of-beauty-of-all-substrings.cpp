class Solution {
public:


    int maxnumber(  int freq[]){
        int maxi=0;
        for(int i=0;i<26;i++){
             maxi=max(maxi, freq[i]);
        }
        return maxi;
    }

     int minnumber(int freq[]){
        int mini=INT_MAX;
        for(int i=0;i<26;i++){
             if(freq[i] > 0) {
            mini = min(mini, freq[i]);
        }
        }
        return mini;
    }

    int  beautySum(string s) {
        int sum=0;
        for(int i=0; i<s.size();i++){
            int freq[26]={};
            for(int j=i;j<s.size(); j++){
                
                 freq[s[j]-'a']++;
                int beauty = maxnumber(freq)-minnumber(freq);
                sum+=beauty;


            }
        }
        return sum;
    }
};