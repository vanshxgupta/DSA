#include <iostream>
#include <vector>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> duplicates;
    int n = nums.size();

    // XOR all elements with their corresponding indices
    for (int i = 0; i < n; ++i) {
        int index = std::abs(nums[i]) - 1;
        if (nums[index] < 0)
            duplicates.push_back(index + 1);
        else
            nums[index] = -nums[index];
    }

    // Restore the array
    for (int i = 0; i < n; ++i)
        nums[i] = std::abs(nums[i]);

    return duplicates;
}

int main() {
    // Example usage
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> duplicates = findDuplicates(nums);

    std::cout << "Duplicate elements are: ";
    for (int num : duplicates)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}