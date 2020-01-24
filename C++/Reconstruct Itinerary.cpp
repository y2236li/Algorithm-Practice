'''
Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.

workflow:
save {current place, arrivable places} into hash table
loop from current place to the one arrivable place with the lowest lexical order until nowhere to go
'''



using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> umap;
        for (vector<string> vs: tickets){
            
            if (umap.find(vs.at(0)) == umap.end()){
                vector<string> tmp_vec(1, vs.at(1));
                umap.insert({vs.at(0), tmp_vec});
            }
            else{
                umap[vs.at(0)].push_back(vs.at(1));
            }
        }
        
        for (vector<string> vs: tickets){
            sort(umap[vs.at(0)].begin(), umap[vs.at(0)].end());
        }
        
        vector<string> res;
        string cur_city = "JFK";
        // cout << umap["JFK"].at(0) << umap["JFK"].at(1) << endl;
        while(umap.find(cur_city) != umap.end() && umap[cur_city].size() > 0){
            // cout << cur_city << endl;
            res.push_back(cur_city);
            string pre_city = cur_city;
            cur_city = umap[cur_city].at(0);
            umap[pre_city].erase(umap[pre_city].begin(), umap[pre_city].begin()+1);
        }
        res.push_back(cur_city);
        return res;
    }
};