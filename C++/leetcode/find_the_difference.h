#pragma once

// https://leetcode.com/problems/find-the-difference/description/
// You are given two strings s and t.
// String t is generated by random shuffling string s and then add one more letter at a random position.
// Return the letter that was added to t.
//
// Example 1:
// Input: s = "abcd", t = "abcde"
// Output: "e"
// Explanation: 'e' is the letter that was added.
//
// Example 2:
// Input: s = "", t = "y"
// Output: "y"

class Solution {
public:

    char hash_map_approach(const std::string& s, const std::string& t) {
        std::unordered_map<char, int> char_appearance;

        for (auto ch : t) {
            char_appearance[ch]++;
        }

        for (auto ch : s) {
            if (char_appearance.find(ch) != char_appearance.end()) {
                char_appearance.at(ch)--;
            } else {
                return ch;
            }
        }
        char target = std::max_element(char_appearance.begin(), char_appearance.end(), [](const auto& left, const auto& right) {
            return left.second < right.second;
        })->first;
        return target;
    }

    char sort_approach(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        const std::size_t base_size = s.size();

        for (std::size_t index = 0; index < base_size; ++index) {
            const char source_ch = s.at(index);
            const char target_ch = t.at(index);
            if (source_ch != target_ch) {
                return target_ch;
            }
        }
        return t.back();
    }

    char findTheDifference(string s, const string t) {
        return hash_map_approach(s, t);
    }
};