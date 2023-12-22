#include <iostream>

const int size = 10;
int arr[size] = { -7, -5, -3, -2, 1, 3, 4, 6, 9, 11 };
int k = 4;

std::pair<int, int> two_sum1(int arr[], const int size, int k) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (k == (arr[i] + arr[j])) {
                return std::make_pair(i, j);
            }
        }
    }

    return std::make_pair(-1, -1);
}

std::pair<int, int> two_sum2(int arr[], const int size, int k) {
    int first = 0;
    int second = size - 1;

    while (first < second) {
        int sum = arr[first] + arr[second];
        if (sum == k) {
            return std::make_pair(first, second);
        } else if (sum < k) {
            ++first;
        } else if (sum > k) {
            --second;
        }
    }

    return std::make_pair(-1, -1);
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < size; ++i) {
        std::cout
            << "ARR[" << i << "] = " << arr[i] 
            << std::endl
        ;
    }

    std::pair<int, int> pair = two_sum2(arr, size, k);

    std::cout
        << std::endl
    ;

    std::cout
        << "ARR[" << pair.first << "] + " 
        << "ARR[" << pair.second << "] = "
        << k
        << std::endl
    ;

    return 0;
}
