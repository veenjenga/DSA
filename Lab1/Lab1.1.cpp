#include <iostream>
#include <vector>

int summation(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int maximum(const std::vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

int main() {
    int n;
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the integers in the array: ";
    for (int& num : arr) {
        std::cin >> num;
    }

    std::cout << "Summation: " << summation(arr) << std::endl;
    std::cout << "Maximum: " << maximum(arr) << std::endl;

    return 0;
}