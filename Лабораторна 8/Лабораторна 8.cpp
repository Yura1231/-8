#include <iostream>
#include <algorithm>

int countElementsLessThan3(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 3) {
            count++;
        }
    }
    return count;
}

int sumInt(int arr[], int n) {
    int sum = 0;
    int lastNegativeIndex = -1;

    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            lastNegativeIndex = i;
        }
    }

    if (lastNegativeIndex != -1) {
        for (int i = lastNegativeIndex + 1; i < n; ++i) {
            sum += static_cast<int>(arr[i]);
        }
    }

    return sum;
}

void transformArray(int arr[], int n) {
    int maxElement = *std::max_element(arr, arr + n);

    std::sort(arr, arr + n, [maxElement](int a, int b) {
        return std::abs(a - maxElement) < 0.2 * maxElement;
        });
}

int main() {
    const int n = 10; 
    int myArray[n] = { 1, -2, 5, -3, 0, 4, 6, 2, 1, 7 };

    
    int countLessThan3 = countElementsLessThan3(myArray, n);
    std::cout << "Number of array elements less than 3: " << countLessThan3 << std::endl;

    
    int sumAfterLastNegative = sumInt(myArray, n);
    std::cout << "The sum of the integer parts of the elements after the last negative one: " << sumAfterLastNegative << std::endl;

    
    transformArray(myArray, n);
    std::cout << "Array after conversion: ";
    for (int i = 0; i < n; ++i) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}
