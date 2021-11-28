#include <iostream>
#include <vector>
 
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<int>> edges(n, vector<int>(n, 0));
        vector<int> times;
        vector<int> res;
        vector<int> visited(n, 0);
        for(auto &meeting : meetings){
            edges[meeting[0]][meeting[1]] = meeting[2];
            edges[meeting[1]][meeting[0]] = meeting[2];
            times.push_back(meeting[2]);
        }
        visited[firstPerson] = 1;
        

    }
};
 
int main(){
 
 
}