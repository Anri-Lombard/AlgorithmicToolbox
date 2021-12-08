#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size();

    int index1=-1;
    for (int i=0; i<n; i++) {
        if (index1 == -1 || numbers[index1] < numbers[i])
            index1 = i;
    }

    int index2 = -1;
    for (int j=0; j<n; j++) {
        if ((numbers[j] != numbers[index1]) && (numbers[index2] < numbers[j]))
            index2 = j;
    }

    return ((long long)numbers[index1]) * numbers[index2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
