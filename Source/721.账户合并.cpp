/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // // init
        // unordered_map<string, int> email2Index;
        // unordered_map<string, string> email2Name;
        // int index = 0, size = accounts.size();
        // vector<int> parentOfIndex, rankOfIndex;
        // for (auto &emails : accounts) {
        //     string name = emails.at(0);
        //     int subSize = emails.size();
        //     for (int i = 1; i < subSize; i++) {
        //         email2Index[emails.at(i)] = index;
        //         email2Name[emails.at(i)] = name;
        //     }
        //     parentOfIndex.push_back(-1);
        //     rankOfIndex.push_back(0);
        //     ++index;
        // }
        // // union -> parent
        // for (int emailIndex = 0; emailIndex < size; emailIndex++) {
        //     int subSize = accounts.at(emailIndex).size();
        //     for (int subIndex = 1; subIndex < subSize; subIndex++) {
        //         int currIndex = email2Index[accounts.at(emailIndex).at(subIndex)];
        //         if (currIndex != emailIndex) {
        //             unionVector(parentOfIndex, rankOfIndex, currIndex, emailIndex);
        //         }
        //     }
        // }
        // // output
        // vector<vector<string>> result;
        // unordered_map<int, vector<string>> tempResult;
        // for (auto &email : email2Index) {
        //     int root = findRoot(parentOfIndex, email.second);
        //     tempResult[root].push_back(email.first);
        // }
        // for (auto &items : tempResult){
        //     vector<string> temp{email2Name[items.second.at(0)]};
        //     sort(items.second.begin(), items.second.end());
        //     temp.insert(temp.end(), items.second.begin(), items.second.end());
        //     result.push_back(temp);
        // }
        // return result;

        // DFS
        // build map
        unordered_map<string, vector<string>> emailGraph;
        unordered_map<string, string> emailName;
        for (auto &account : accounts) {
            int size = account.size();
            string name = account.at(0), mainEmail = account.at(1);
            emailName[mainEmail] = name;
            if ( size == 2 ) { emailGraph[mainEmail]; }
            for (auto &email : unordered_set<string>(account.begin() + 2, account.end())) {
                emailGraph[mainEmail].push_back(email);
                emailGraph[email].push_back(mainEmail);
                emailName[email] = name;
            }
        }
        // DFS
        vector<vector<string>> emailMerge;
        stack<string> dfsStack;
        unordered_set<string> visited;
        for (auto &email : emailGraph) {
            string root = email.first;
            if(visited.find(root) != visited.end()) { continue; }
            vector<string> temp;
            dfsStack.push(root);
            while (!dfsStack.empty()) {
                root = dfsStack.top();
                dfsStack.pop();
                if(visited.find(root) != visited.end()) { continue; }
                visited.insert(root);
                temp.push_back(root);
                for (auto &item : emailGraph[root]) {
                    if(visited.find(item) != visited.end()) { continue; }
                    dfsStack.push(item);
                }
            }
            sort(temp.begin(), temp.end());
            temp.insert(temp.begin(), emailName[root]);
            emailMerge.push_back(temp);
        }
        return emailMerge;
    }
// private:
//     int findRoot(vector<int> &parent, int index) {
//         while (parent[index] != -1) { index = parent[index];}
//         return index;
//     }

//     void unionVector(vector<int> &parent, vector<int> &rank, int i, int j) {
//         int iRoot = findRoot(parent, i), jRoot = findRoot(parent, j);
//         if(iRoot != -1 && iRoot == jRoot) { return; }
//         else {
//             if(rank[iRoot] < rank[jRoot]) { parent[iRoot] = jRoot; }
//             else if(rank[iRoot] > rank[jRoot]) { parent[jRoot] = iRoot; }
//             else { parent[iRoot] = jRoot; ++rank[jRoot]; }
//         }
//     }
};
// @lc code=end

