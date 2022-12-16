/*
 * File: Traverse.cpp
 * ------------------
 * This program reimplements the breadth-first search using an
 * explicit queue, and depth-first search algorithm using an explicit stack
 */

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include "csc300222fall/assignment5/simplegraph.h"
using namespace std;

void bfs(Node *start) {
   // TODO, make sure that your implementation is based on queue
   queue<Node*> q;
   set<Node*> visited;
   q.push(start);
   while(!q.empty())
   {
      Node* n = q.front();
      q.pop();
      if (visited.count(n) != 1)
      {
         cout << n->name << endl;
         visited.insert(n);
         for (auto a : n->arcs)
         {
            q.push(a->finish);
         }
      }
   }
}

void dfs(Node *start) {
   // TODO, make sure that your implementation is based on stack
   stack<Node*> stk;
   set<Node*> visited;
   stk.push(start);
   while (!stk.empty())
   {
      Node* n = stk.top();
      stk.pop();
      if (visited.count(n) != 1)
      {
         cout << n->name << endl;
         visited.insert(n);
         for (auto a : n->arcs)
         {
            stk.push(a->finish);
         }
      }
   }
}


int main(){
   SimpleGraph airline;
   readGraph(airline, cin);
   cout << "DFS at Portland ...." << endl;
   dfs(airline.nodeMap.at("Portland"));
   cout << "BFS at Portland ...." << endl;
   bfs(airline.nodeMap.at("Portland"));
   return 0;
}
