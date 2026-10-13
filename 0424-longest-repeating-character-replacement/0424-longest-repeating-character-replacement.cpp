class Solution {
public:
    int characterReplacement(string s, int k) {
       int l=0,r=0,maxlen=0,mmf=0;
       unordered_map<char,int> mpp;
       while(r<s.size()){
        mpp[s[r]-'A']++;
        mmf= max(mmf,mpp[s[r]-'A']);
        while(((r-l+1)-mmf)>k){
             mpp[s[l]-'A']--;
             l++;

        }
        if(((r-l+1)-mmf)<=k){
            maxlen=max(maxlen,r-l+1);
          
        }
          r++;
       } 
       return maxlen;
    }
};