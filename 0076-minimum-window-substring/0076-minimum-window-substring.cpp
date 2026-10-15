
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) return "";

        int hash[256] = {0};

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        int l = 0, r = 0;
        int cnt = 0;
        int minlen = INT_MAX;
        int start = 0;

        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            while (cnt == m) {
                int len = r - l + 1;

                if (len < minlen) {
                    minlen = len;
                    start = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        if (minlen == INT_MAX) return "";

        return s.substr(start, minlen);
    }
};
