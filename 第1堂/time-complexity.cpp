#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

long long int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

long long int fibonacciDP(int n) {
    vector<long long int> dp(n+1, 0);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    auto start = high_resolution_clock::now();
    cout << "Fibonacci DP Result (" << n << "): " << fibonacciDP(n) << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by DP Method: " << duration.count() << " milliseconds\n";

    start = high_resolution_clock::now();
    cout << "Fibonacci Recursive Result (" << n << "): " << fibonacciRecursive(n) << "\n";
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by Recursive Method: " << duration.count() << " milliseconds\n";

    return 0;
}
