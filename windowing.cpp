// g++ windowing.cpp -o demo && ./demo

#include <iostream>

const int size = 10;
int arr[size] = { 1, 12, -5, -2, 4, 3, -7, 6, 11, -3 };
int k = 3;

float windowing1(int arr[], const int size, int k)
{
    int max = 0;
    for (int i = 0; i < size - k + 1; ++i) {

        int sum = 0;
        for (int j = i; j < i + k; ++j) {
            sum += arr[j];
        }

        max = std::max(max, sum);

        std::cout
            << "SUM[" << i << " - "<< i + k - 1 << "] = " << sum
            << std::endl
        ;
    }

    return (float) max / k;
}

float windowing2(int arr[], const int size, int k)
{
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }

    std::cout
        << "SUM[0 - " << k - 1 << "] = " << sum
        << std::endl
    ;

    int max = sum;
    for (int i = k; i < size; ++i) {
        sum += arr[i] - arr[i - k];
        max = std::max(max, sum);

        std::cout
            << "SUM[" << i - k + 1 << " - "<< i << "] = " << sum
            << std::endl
        ;
    }

    return (float) max / k;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < size; ++i) {
        std::cout
            << "ARR[" << i << "] = " << arr[i] 
            << std::endl
        ;
    }

    std::cout
        << std::endl
    ;

    float result = windowing2(arr, size, k);

    std::cout
        << std::endl
        << "RESULT: " << result
        << std::endl
    ;

    return 0;
}
