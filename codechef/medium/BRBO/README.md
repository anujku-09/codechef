# BRBO

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Chef Counts Subsequences

Chef has two strings: a source string and a target string. Chef wants to find out in how many distinct ways the target string can be formed as a subsequence of the source string. A subsequence is formed by deleting zero or more characters from the source string without changing the order of the remaining characters. Help Chef count the number of such distinct subsequences.

Chef needs to write a program that, given the source and target strings, returns the total count of distinct subsequences of the source string that are exactly equal to the target string.

## Function Declaration
### Function Name

$countDistinctSubsequences$ — This function calculates the number of distinct subsequences of the $sourceString$ that match the $targetString$.

### Parameters
- $sourceString$ (String): The original string from which subsequences are formed.
- $targetString$ (String): The target string to be matched as a subsequence of $sourceString$
- Both strings contain only English letters and have lengths up to 1000 characters.
### Return Value
- Returns an $int$ representing the count of distinct subsequences in $sourceString$ equal to $targetString$.
- The output is a non-negative integer indicating how many different ways the target can be formed by deleting characters from the source without reordering.
## Input Format
- The first line contains a single integer $T$ — the number of test cases.
- Each test case consists of two lines: The first line contains the string $sourceString$. The second line contains the string $targetString$.
## Output Format
- For each test case, print a single line containing the number of distinct subsequences of $sourceString$ which equal $targetString$.
- Chef wants you to output the exact count for each test case.
## Constraints
- $1 \leq T \leq 10^5$
- $1 \leq |sourceString|, |targetString| \leq 1000$
- Both sourceString and targetString consist only of English letters (uppercase and lowercase).
- The result fits within a 32-bit signed integer.

Help Chef implement the $countDistinctSubsequences$ function to solve this problem efficiently!

### Sample 1:
Input
Output

```
2
abcde
ace
babgbag
bag
```

```
1
5
```

### Explanation:
- For "abcde" and "ace": There's only one way to form "ace" by picking 'a', 'c', and 'e' in order from "abcde".
- For "babgbag" and "bag": The subsequence "bag" appears 5 times by choosing different combinations of 'b', 'a', and 'g' from the string.
### Sample 2:
Input
Output

```
3
rabbbit
rabbit
aaaaa
aa
gggggggggg
gg
```

```
3
10
45
```

### Explanation:
- t=1: "rabbit" appears 3 times as a subsequence in "rabbbit" by deleting different 'b's.
- t=2: "aa" appears 10 times in "aaaaa" by choosing any 2 out of 5 'a's.
- t=3: "gg" appears 45 times in "gggggggggg" by choosing any 2 out of 10 'g's.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T05:57:32.165Z  

```c_cpp
int countDistinctSubsequences(string sourceString, string targetString) {
    int n = sourceString.size();
    int m = targetString.size();
    if(m > n) {
        return 0;
    }
    vector<int> dp (m + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = min(i + 1, m); j >= 1;j--) {
            if(sourceString[i] == targetString[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp[m];
}
```

---

[View on CodeChef](https://www.codechef.com/problems/BRBO)