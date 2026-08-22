class Solution {
public:

    void generate(string curr, int open, int close, int n,
                  vector<string>& ans) {

        // If we have used all parentheses
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // We can add '(' if we still have some left
        if (open < n) {
            generate(curr + '(', open + 1, close, n, ans);
        }

        // We can add ')' only when there is an unmatched '('
        if (close < open) {
            generate(curr + ')', open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate("", 0, 0, n, ans);

        return ans;
    }
};