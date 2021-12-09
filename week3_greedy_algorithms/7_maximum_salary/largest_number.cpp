#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using std::vector;
using std::string;

bool is_better(long long a, long long b) {
  return b >= a;
}

string largest_number(vector<string> a) {
  //write your code here
  // std::stringstream ret;
  // for (size_t i = 0; i < a.size(); i++) {
  //   ret << a[i];
  // }
  // string result;
  // ret >> result;
  // return result;

  string result;
  while (!a.empty()) {
    int max_number = -999999;
    for (int i =0; i< a.size(); i++) {
      if (is_better(std::stol(a[i]), max_number)) {
        max_number = std::stol(a[i]);
      }
    }
    result += max_number;
    a.erase(std::remove(a.begin(), a.end(), std::to_string(max_number)), a.end());
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
