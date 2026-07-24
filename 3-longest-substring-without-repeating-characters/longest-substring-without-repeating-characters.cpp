#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_map;
        int i = 0;
        int j = 0;
        int max_len = 0; // Renamed from 'max' to avoid conflict with std::max
        
        while(j < s.length()){
            char_map[s[j]]++; // Equivalent to map.put() and getOrDefault()
            
            if(char_map.size() == j - i + 1){
                max_len = max(max_len, j - i + 1);
                j++;
            }
            else if(char_map.size() < j - i + 1){
                while(char_map.size() < j - i + 1){
                    char_map[s[i]]--;
                    if(char_map[s[i]] == 0) {
                        char_map.erase(s[i]); // Equivalent to map.remove()
                    }
                    i++;
                }
                j++;
            }
        }
        return max_len;
    }
};