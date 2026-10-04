# DSCPPAS276

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Check Palindrome

You are given a string $(S)$. Your task is to determine if the string can be a palindrome after deleting at most one character from it.

### Input Format
- The first line contains one integer $n$, the size of the string - Next line contains string $S$.
### Output Format
- Print whether $S$ can be made palindrome after deleting at most one character.
### Constraints
- $1 \leq |S| \leq 10^5$
### Sample 1:
Input
Output

```
4
abca
```

```
true
```

### Explanation:

We can delete b or c to make it palindrome. after deleting b the S will be aca which is palindrome.

### Sample 2:
Input
Output

```
4
batr
```

```
false
```

### Explanation:

There is no way to make S palindrome after deleting at most 1 character.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T13:26:38.843Z  

```c_cpp
#include <iostream>
#include <string>

using namespace std;

bool isPalindromeRange(string &s, int l, int r){
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(string s) {
    int left = 0;
    int right  = (int)s.length() - 1;
    while(left < right){
        if(s[left] != s[right]) {
            return isPalindromeRange(s, left + 1, right) || isPalindromeRange(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}

int main() {
  int n;
  cin>>n;
    string s;
    cin >> s;
    cout << (validPalindrome(s) ? "true" : "false") << endl;
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/DSCPPAS276)