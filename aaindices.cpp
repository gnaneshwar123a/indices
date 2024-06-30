
#include <iostream>
#include <vector>
#include <unordered_map>

// Function to find two indices such that their values add up to the target
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    // Create an unordered map to store the indices of the elements
    std::unordered_map<int, int> num_map;
    
    // Traverse through the array
    for (int i = 0; i < nums.size(); ++i) {
        // Calculate the complement of the current element
        int complement = target - nums[i];
        
        // Check if the complement exists in the map
        if (num_map.find(complement) != num_map.end()) {
            // If found, return the indices
            return {num_map[complement], i};
        }
        
        // If not found, add the current element to the map
        num_map[nums[i]] = i;
    }
    
    // If no solution is found, return an empty vector
    // (Though the problem guarantees one solution)
    return {};
}

int main() {
    int n, target;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    
    std::vector<int> nums(n);
    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    
    std::cout << "Enter the target value: ";
    std::cin >> target;
    
    std::vector<int> result = twoSum(nums, target);
    
    if (!result.empty()) {
        std::cout << "Output: [" << result[0] << ", " << result[1] << "]\n";
        std::cout << "The elements are: " << nums[result[0]] << " and " << nums[result[1]] << " which add up to " << target << ".\n";
    } else {
        std::cout << "No solution found.\n";
    }
    
    return 0;
}
