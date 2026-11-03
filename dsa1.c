#include <stdio.h>
#include <limits.h>

int maxSubArray(const int nums[], int n) {
    if (n <= 0) return 0;

    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < n; i++) {
        // Either extend the previous subarray or start a new one here
        current_sum = (nums[i] > current_sum + nums[i]) ? nums[i] : (current_sum + nums[i]);

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}

int main(void) {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum Subarray Sum: %d\n", maxSubArray(arr, n));
    // Output: 6 (from subarray [4, -1, 2, 1])
    return 0;
}