# JQJTY01

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Largest Rectangle in Histogram

You are given an array $A_1, A_2, \dots, A_N$ of length $N$. $A$ represents a histogram which means the height of the $i^{th}$ bar will be $A_i$ units and the width of each bar is $1$ unit.

Find the area of the largest rectangle in the histogram.

## Function Declaration
### Function Name

$largestRectangleArea$ – This function calculates the maximum rectangular area possible within the given histogram.

### Parameters

$N$ : An integer representing the number of bars in the histogram.
$A$ : An array of integers representing the heights of the histogram bars.

### Return Value

Returns an integer: the area of the largest rectangle that can be formed in the histogram.

### Constraints:

$1 \leq T \leq 10$
$1 \le N \le 10^5$
$0 \le A_i \le 10^9$

 *The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled automatically.* 

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first line of each test case contains an integer $N$ - the length of the array $A$.
- The second line of each test case contains $N$ space-separated integers $A_1,A_2,\ldots,A_N$.
### Output Format

For each test case, output on a new line the area of the largest rectangle in the histogram.

### Subtasks
- Subtask 1 (30 points): $1 \leq N \leq 1000$
- Subtask 2 (70 points): No further constraints.
### Sample 1:
Input
Output

```
3
4
2 6 8 4
4
5 10 5 2
2
5 5

```

```
12
15
10

```

### Explanation:

 **Test case $1$** : Largest rectangle will create using $A_2$, $A_3$. So height will be $\min(6, 8) = 6$, width will be $2$. So area will be $12$.

 **Test case $2$** : Largest rectangle will create using $A_1$, $A_2$, $A_3$. So height will be $\min(5, 10, 5) = 5$, width will be $3$. So area will be $15$.

 **Test case $3$** : Largest rectangle will create using $A_1$, $A_2$. So height will be $\min(5, 5) = 5$, width will be $2$. So area will be $10$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T18:50:33.007Z  

```c_cpp
long long largestRectangleArea(int N, vector<int>& A) {
    vector<int> left(N), right(N);
    stack<int> st;

    // Step 1: Left mein pehla chhota element ka index dhoondo
    for (int i = 0; i < N; i++) {
        while (!st.empty() && A[st.top()] >= A[i]) {
            st.pop();
        }
        if (st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }

    // Stack khali karo dobara use karne ke liye
    while (!st.empty()) st.pop();

    // Step 2: Right mein pehla chhota element ka index dhoondo
    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty() && A[st.top()] >= A[i]) {
            st.pop();
        }
        if (st.empty()) right[i] = N;
        else right[i] = st.top();
        st.push(i);
    }

    // Step 3: Har bar ka area nikalo aur max le lo
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long height = A[i];
        long long width = right[i] - left[i] - 1;
        ans = max(ans, height * width);
    }
    return ans;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/JQJTY01)