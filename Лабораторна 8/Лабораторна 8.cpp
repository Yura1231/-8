#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
    
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    
    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    
    int countLessThan3 = std::count_if(arr.begin(), arr.end(), [](int x) { return x < 3; });
    std::cout << "1. Number of elements less than 3: " << countLessThan3 << std::endl;

   
    auto lastNegative = std::find_if(arr.rbegin(), arr.rend(), [](int x) { return x < 0; });
    if (lastNegative != arr.rend()) {
        int sumAfterLastNegative = std::accumulate(lastNegative.base(), arr.end(), 0);
        std::cout << "2. Sum of integers after the last negative element: " << sumAfterLastNegative << std::endl;
    }
    else {
        std::cout << "2. No negative elements found." << std::endl;
    }

    
    auto maxElement = *std::max_element(arr.begin(), arr.end());
    std::transform(arr.begin(), arr.end(), arr.begin(), [maxElement](int x) {
        if (x != maxElement && std::abs(x - maxElement) <= 0.2 * maxElement) {
            return x;
        }
        else {
            return maxElement + 1; 
        }
        });

   
    auto partitionPoint = std::partition(arr.begin(), arr.end(), [maxElement](int x) {
        return x != maxElement && std::abs(x - maxElement) <= 0.2 * maxElement;
        });

    
    std::cout << "3. Transformed array:" << std::endl;
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

