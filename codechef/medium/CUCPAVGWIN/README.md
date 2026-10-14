# CUCPAVGWIN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Solar Farm Best Window

The  **Helios solar farm**  logs its net power output once every hour. Hour $i$ contributed $output_i$ units of energy. The number can be negative: at night, and whenever the panels are being cleaned, the site draws power from the grid instead of feeding it in.

The operations team reports performance in  **windows of exactly $K$ consecutive hours**. A window is judged by its average output — the sum of the $K$ hourly readings inside it divided by $K$ — and the team wants to quote the best window the farm has ever managed.

### Task

Among all windows of exactly $K$ consecutive hours in the log, find the  **largest average output**.

### Important Requirements
- The $K$ hours of a window must be consecutive in the log.
- Every window has exactly $K$ hours — shorter stretches near the ends do not count.
- Readings may be negative, so the best average may be negative as well.
### Input Format

The first line contains two space-separated integers $N$ and $K$ — the number of hours in the log and the length of a window.

The second line contains $N$ space-separated integers $output_1, output_2, \ldots, output_N$, the net output recorded in each hour.

### Output Format

Print the largest average output over any window of $K$ consecutive hours, with  **exactly 5 digits after the decimal point**.

### Constraints
- $1 \le K \le N \le 10^5$
- $-10^4 \le output_i \le 10^4$
### Sample 1:
Input
Output

```
5 4
1 12 -5 -6 50

```

```
12.75000

```

### Sample 2:
Input
Output

```
1 1
5

```

```
5.00000

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T12:46:55.062Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += a[i];
    }

    long long max_sum = current_sum;

    for (int i = k; i < n; i++) {
        current_sum += a[i] - a[i - k];
        max_sum = max(max_sum, current_sum);
    }

    double best_avg = (double)max_sum / k;
    cout << fixed << setprecision(5) << best_avg << "\n";

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPAVGWIN)