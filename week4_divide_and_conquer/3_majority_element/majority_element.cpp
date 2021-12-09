#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = left + (right - left) / 2;
  int count_x = 0, count_y = 0;

  long x = get_majority_element(a, left, mid);
  long y = get_majority_element(a, mid + 1, right);

  for (int i=left; i<=right; i++) {
    if (x == a[i]) count_x++;
    else if (y == a[i]) count_y++;
  }

  if (count_x > (right - left)/2) return x;
  if (count_y > (right - left)/2) return y;
  
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
