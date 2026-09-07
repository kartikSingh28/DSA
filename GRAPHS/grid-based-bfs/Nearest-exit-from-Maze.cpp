/*
Nearest Exit in Maze

Given an m×n maze:
'.' = empty cell, '+' = wall.
Given entrance = [row, col].

Move up/down/left/right through empty cells only.
Find the minimum steps from entrance to the nearest border
cell (exit). The entrance itself is not an exit.
Return -1 if no exit is reachable.

Example:
maze = {{'+','+','.','+'},
        {'.','.','.','+'},
        {'+','+','+','.'}}
entrance = {1,2}

Output: 1

Explanation:
Nearest exit is [0,2], reachable in 1 step.
Other exits: [1,0] (2 steps), [2,3] (unreachable).
*/
#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int nearestExit(vector<vector<char>> &maze,vector<int> &entrace){
        int m=maze.size();
        int n=maze[0].size();
        int sx=entrace[0];
        int sy=entrace[1];
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        q.push({sx,sy});
        while(!q.empty()){
            auto it=q.front();
            int currx=it.first;
            int curry=it.second;
            for(int i=0;i<4;i++){
                int neighx=currx+dx[i];
                int neighy=curry+dy[i];
                if(maze[neighx][neighy]!='+' &&(neighx>=0 && neighx<))
            }

        }

    }
};