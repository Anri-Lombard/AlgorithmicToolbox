#include <iostream>

int get_change(int m) {
  //write your code here
  // int n = 0;
  
  // while (m - 10 >= 0) {
  //   n+=1;
  //   m-=10;
  // }
  // while (m - 5 >= 0) {
  //   n+=1;
  //   m-=5;
  // }
  // n += m;
  // return n;

  // int n = 0;
  // while (m > 0) {
  //   if (m >= 10) m-=10;
  //   else if (m >= 5) m-=5;
  //   else m-=1;
  //   n += 1;
  // }
  // return n;

  return (m/10) + ((m % 10)/5) + (m % 5);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
