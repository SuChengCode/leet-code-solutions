#include <vector>   
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
            思路
            - 首先我们能读取到每个词的string，由于map<string,int>的比较可能比较麻烦，我们可以将字符表转换成一个字符串形式，
            例如按照字母顺序排列每个字母和它的频次，形成一个新的字符串比如good -> dgoo，这样就可以直接比较这个字符串来判断是否是anagram关系。

				- 如果一个string的单词的字符表和之前的某个单词的字符表相同，那么它们就是anagram关系，我们可以将它们放在同一个list中。

			- 为了保存所有的字符表以供查询，使用一个unordered_map<string, vector<string>>来保存字符表和对应的单词列表。
        */

		unordered_map<string, vector<string>> anagramMap;

		// 遍历每个单词
        for (string& word : strs) 
        {
			string newWord = word;
			// 统计字符频次
			sort(newWord.begin(), newWord.end()); // 将单词的字符排序，得到一个新的字符串作为key
			// 将排序后的字符串作为key，将原始单词添加到对应的vector中
			anagramMap[newWord].push_back(word);
        }

        // 输出答案
		vector<vector<string>> result;
		// 遍历map，将每个anagram group添加到结果中
		for (auto& pair : anagramMap)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};