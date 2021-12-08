#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long euclid_gcd(long long a, long long b) {
  if (b == 0)
    return a;

  long long a_prime = a % b;

  return euclid_gcd(b, a_prime);
}

long long euclid_lcm(int a, int b) {
  return (a / euclid_gcd(a, b)) * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << euclid_lcm(a, b) << std::endl;
  return 0;
}
