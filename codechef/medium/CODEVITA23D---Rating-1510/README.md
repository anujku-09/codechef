# CODEVITA23D - Rating 1510

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Square Free Number

In the theory of numbers, square free numbers have a special place. A square free number is one that is not divisible by a perfect square (other than $1$). Thus $72$ is divisible by $36$ (a perfect square), and is not a square free number, but $70$ has factors $1, 2, 5, 7, 10, 14, 35$ and $70$. As none of these are perfect squares (other than $1$), $70$ is a square free number.

For some algorithms, it is important to find out the square free numbers that divide a number. Note that $1$ is not considered a square free number.

In this problem, you are asked to write a program to find the number of square free numbers that divide a given number.

### Input Format
- The only line of the input is a single integer $N$ which is divisible by no prime number larger than $19$.
### Output Format
- One line containing an integer that gives the number of square free numbers (not including $1$).
### Constraints
- $N \lt 10^9$
### Sample 1:
Input
Output

```
20
```

```
3
```

### Explanation:

$N=20$

If we list the numbers that divide $20$, they are

$1, 2, 4, 5, 10, 20$

$1$ is not a square free number, $4$ is a perfect square, and $20$ is divisible by $4$, a perfect square. $2$ and $5$, being prime, are square free, and $10$ is divisible by $1,2,5$ and $10$, none of which are perfect squares. Hence the square free numbers that divide $20$ are $2, 5, 10$. Hence the result is $3$.

### Sample 2:
Input
Output

```
72
```

```
3
```

### Explanation:

$N=72$. The numbers that divide $72$ are

$1, 2, 3, 4, 6, 8, 9, 12, 18, 24, 36, 72$

$1$ is not considered square free. $4, 9$ and $36$ are perfect squares, and $8,12,18,24$ and $72$ are divisible by one of the. Hence only $2, 3$ and $6$ are square free. (It is easily seen that none of them are divisible by a perfect square). The result is $3$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-24T16:26:50.409Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n;
	cin >> n;
	long long primes = 0;
	for(long long d = 2; d * d <= n; d++){
	    if(n % d == 0) {
	        primes++;
	        while(n % d == 0) {
	            n /= d;
	        }
	    }
	}
	if(n > 1) {
	    primes++;
	}
	long long ans = (1LL << primes )- 1;
	cout << ans << endl;
	return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CODEVITA23D)