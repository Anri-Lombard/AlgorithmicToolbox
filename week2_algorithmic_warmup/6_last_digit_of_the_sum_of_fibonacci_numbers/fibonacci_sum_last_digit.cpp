#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long remainder = n % pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int fibonacci_fast(int n) {
    // write your code here
    int lastDigitOfNPlus2 = get_fibonacci_huge_fast(n+2, 10);
    int lastDigitOf2 = get_fibonacci_huge_fast(2, 10);
    
    if (lastDigitOfNPlus2 >= lastDigitOf2) 
        return lastDigitOfNPlus2 - lastDigitOf2;
    else
        return (10 + lastDigitOfNPlus2) - lastDigitOf2;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n) << "\n";
}
