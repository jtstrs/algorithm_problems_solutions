#pragma once

// https://leetcode.com/problems/concatenation-of-array
// Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i]
// and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
// Specifically, ans is the concatenation of two nums arrays.
// Return the array ans.

class Solution {
public:
    std::vector<int32_t> getConcatenation(std::vector<int32_t>& nums) {
        std::vector<int32_t> ans = nums;
        std::copy(nums.begin(), nums.end(), std::back_inserter(ans));
        return ans;
    }
};
