class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adjList[numCourses];
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> global_visited(numCourses , 0);
        vector<int> current_visited(numCourses , 0);
        bool cyclePresent = false;
        for(int i = 0 ; i < numCourses ; i++){
            if(!global_visited[i]){
                if(cycleDetection(adjList , i , global_visited , current_visited)){
                    cyclePresent =  true;
                    break;
                }
            }
        }
        
        return !cyclePresent ;
    }
    
    bool cycleDetection(vector<int> adjList[] , int curr , vector<int> &global_visited , vector<int> &current_visited){
        global_visited[curr] = 1;
        current_visited[curr] = 1;
        
        for(auto k : adjList[curr]){
            if(!global_visited[k]){
                if(cycleDetection(adjList , k , global_visited , current_visited))  return true;
            }else{
                if(current_visited[k]){
                    return true;
                }
            }
        }
        current_visited[curr] = 0;
        return false;
    }
                 
};