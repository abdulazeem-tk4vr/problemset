1. Largest Element in an Array {

    Brute Force : Intro sort
    Time Complexity = O (n*log n)
        {
            sort(arr.begin(), arr.end());
            return arr[n-1];
        }

    Optimised Solution : Single Iteration using Max variable
    Time Complexity : O(n)
}

2. Second Smallest and Second Largest Element {

    Brute Force : Intro sort to get 2nd and 2nd last element
    Time Complexity : O(n*Log n)

    Better Approach : 
      for(i=0;i<n;i++)
    {
        small=min(small,arr[i]);
        large=max(large,arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
            second_small=arr[i];
        if(arr[i]>second_large && arr[i]!=large)
            second_large=arr[i];
    }
    Time Complexity : O(2n)

    Optimised Approach : 

        if(arr[i]<small){
            second_small = small;
            small = arr[i];
        } else if (arr[i] < second_small && arr[i]!=small){
            second_small = arr[i]
        }


}

3. Check if an Array is Sorted {
    bool isSorted(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1])
            return false;
        }

        return true;
    }
    Time Complexity : O(n)
    Space Complexity : O(1)

}

4. Remove duplicates from Sorted array {
    
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
    Time Complexity : O(n)
    Space Complexity : O(1)
}

20. Stock Buy and Sell { 

    Tip : " Keep track of the minimal elemment from the beginning"
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX;
        int profit = 0;
        int n = prices.size();
        for(int i = 0; i<n; i++){
            lowest = min(lowest, prices[i]);
            profit = max(profit, prices[i]-lowest);
        }

        return profit;
    }

    Time Complexity : O(n)
    Space Complexity : O(1)

}

21. Rearrange Negs and Positives {

    Tip : "Keep track of positives and negatives indexes and store them in a different array"

    #Easy Variation - Equal Positives and Negatives

    vector<int> rearrangeArray(vector<int>& A) {
        int n = A.size();

        // Define array for storing the ans separately.
        vector<int> ans(n, 0);

        // positive elements start from 0 and negative from 1.
        int posIndex = 0, negIndex = 1;
        for (int i = 0; i < n; i++) {

            // Fill negative elements in odd indices and inc by 2.
            if (A[i] < 0) {
                ans[negIndex] = A[i];
                negIndex += 2;
            }

            // Fill positive elements in even indices and inc by 2.
            else {
                ans[posIndex] = A[i];
                posIndex += 2;
            }
        }

        return ans;
    }

    #Tougher Variation

    Tip : " Keep track of positives and negative numbers in separate arrays. Check for count of pos and neg elements. Whichever is smaller, fill the array up first with that count. Then the remaining with the count of the larger"

    vector<int> rearrangeArray(vector<int>& A) {
        int n = A.size();

        // Define array for storing the ans separately.
        vector<int> pos, neg;

        for(int i=0; i<n; i++){
            if(A[i]>0){
                pos.push_back(A[i]);
            } else {
                neg.push_back(A[i]);
            }
        }

        int pos_len = pos.size();
        int neg_len = neg.size();

        if(pos_len > neg_len){
            for(int i=0; i<pos_len; i++){
                A.push_back(pos[2*i]);
                A.push_back(neg[2*i+1]);
            }
            for(int i=neg_len; i<pos_len; i++){
                A.push_back(pos[i]);
            }
        } else {
             for(int i=0; i<pos_len; i++){
                A.push_back(pos[2*i]);
                A.push_back(neg[2*i+1]);
            }
            for(int i=pos_len; i<neg_len; i++){
                A.push_back(neg[i]);
            }
        }

        return A;
    }

}

22. Next Permutation - code {
    Better : next_permutation(arr.begin(), arr.end())

    Optimal : 
}

23. Leaders in an array  {

    Tip : "Keep track of the max element from the right and keep comparing it with every index in the array"

    vector<int> printLeaders(int arr[], int n) {

    vector<int> ans;

    // Last element of an array is always a leader,
    // push into ans array.
    int max = arr[n - 1];
    ans.push_back(arr[n - 1]);

    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > max) {
            ans.push_back(arr[i]);
            max = arr[i];
        }

    return ans;
}
}

24. Set Matrix Zero - code

25. Longest Consecutive Sequence in an Array  {

    Tip : "Keep track of all elements using a set, for each element check if the next element is present in the set, only start count if there isnt a preceding element"

    int longestSuccessiveElements(vector<int>& a) {
    // Write your code here.
    unordered_set<int> st;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    int len = 0;
    int maxi = INT_MIN;
    int x;

    for (auto it : st) {

        if (st.find(it - 1) == st.end()) {
            len = 1;
            x = it;
            while ((st.find(x + 1) != st.end())) {
                len++;
                x = x + 1;
            }
            maxi = max(maxi, len);
        }
    }

    return maxi;
}

    Time Complexity : O(n)
    Space Complexity : O(N)

}

26. Rotate Matrix by 90 degrees {
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
}

27. Spiral Traversal of Matrix {
    
}