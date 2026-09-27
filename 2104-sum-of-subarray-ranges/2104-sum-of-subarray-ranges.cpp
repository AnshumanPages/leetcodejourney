class Solution {
public:

    long long sumSubarrayMax(vector<int>& nums) {
        int n = nums.size();

        vector<int> pge(n), nge(n);
        stack<int> st;

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }

        long long ans2 = 0;

        for (int i = 0; i < n; i++) {
            long long left2 = i - pge[i];
            long long right2 = nge[i] - i;

            ans2 += (long long)nums[i] * left2 * right2;
        }

        return ans2;
    }


    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse(n), nse(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        long long ans1 = 0;

        for (int i = 0; i < n; i++) {
            long long left1 = i - pse[i];
            long long right1 = nse[i] - i;

            ans1 += (long long)nums[i] * left1 * right1;
        }

        return ans1;
    }


    long long subArrayRanges(vector<int>& nums) {
        long long maximum = sumSubarrayMax(nums);
        long long minimum = sumSubarrayMins(nums);

        return maximum - minimum;
    }
};