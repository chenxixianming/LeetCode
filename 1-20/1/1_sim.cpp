#include <cstdio>

void twoSumRaw(int* nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                return;
            }
        }
    }
}

int main() {
    int nums[] = {2, 7, 11, 15};
    twoSumRaw(nums, 4, 9);
    return 0;
}