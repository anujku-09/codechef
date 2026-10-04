# SLDW0103

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Longest Substring Without Repeating Characters

Given a string $S$ of length $N$, you have to output the length of the  **longest substring**  of $S$ with  **non-repeating characters**.

A  **substring**  is a contiguous sequence of characters within the string. The substring must not contain any character that appears more than once.

 **Example:** 

`S = "abcabcbb"`

- Longest substring without repeating characters: "abc"
- Output: 3
## Function Declaration
### Function Name

$longestUniqueSubstring$ – This function computes the length of the longest contiguous substring of a given string that contains no repeating characters.

### Parameters
- $S$ : A string of length $N$ consisting of characters (typically lowercase English letters, but the logic is character-agnostic).
### Return Value
- Returns an integer representing the maximum length of a substring of $S$ such that each character appears at most once in that substring.
## Constraints
- $2 \leq N \leq 10^5$
- $S$ contains valid characters (no restriction on character set unless specified)
- The solution should be efficient enough to handle large input sizes
### Input Format
- The first and only line of input contains a single string $S$.
### Output Format
- Output the length of the longest substring with no repeating characters.
### Sample 1:
Input
Output

```
abcabcbb
```

```
3
```

### Explanation:

The answer is "abc" with length 3.

### Sample 2:
Input
Output

```
bbbb
```

```
1
```

### Sample 3:
Input
Output

```
abcccdefg
```

```
5
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T14:16:17.309Z  

```c_cpp
class Solution {
public:
    int longestUniqueSubstring(string s) {
        vector<int> last_pos(256, -1);
        int mx_len = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            if(last_pos[c] >= l){
                l = last_pos[c] + 1;
            }
            last_pos[c] = r;
            mx_len = max(mx_len, r - l + 1);
        }
        return mx_len;
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/SLDW0103)