'''Longest Word in Dictionary

Add to List

Question 
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:

Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:

Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

Program workflow:
sort words by length -> store those words with length 1 -> if words[:-1] is in the hash table, store the current word -> store the words with the max length in a vector -> sort the vector alphabetically and choose the smallest one
'''


using namespace std;
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](string s1, string s2){return s1.size() < s2.size();});
        unordered_map <string, int> umap;
        vector<string> sortedItems;
        sortedItems.push_back("");
        if (words.size() == 0) return "";
        for (int i = 0; i < words.size(); ++i){
            // cout << words[i] << words[i].size() << endl;
            if (words[i].size() == 1){
                umap.insert({words[i], 0});
                if (sortedItems.at(0).size() < words[i].size()){
                    sortedItems.clear();
                    sortedItems.push_back(words[i]);
                }
                else if (sortedItems.at(0).size() == words[i].size()) sortedItems.push_back(words[i]);
            }
            else{
                if (umap.find(string(words[i].begin(), words[i].end()-1)) != umap.end()){
                    umap.insert({words[i], 0});
                    if (sortedItems.at(0).size() < words[i].size()){
                    sortedItems.clear();
                    sortedItems.push_back(words[i]);
                    }
                    else if (sortedItems.at(0).size() == words[i].size()) sortedItems.push_back(words[i]);
                }
            }
        }
        sort(sortedItems.begin(), sortedItems.end());
        return sortedItems.at(0);
    }
};
