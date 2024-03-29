#include <bits/stdc++.h>
using namespace std;

struct DisjointSet{
    vector<int> parent;
    vector<int> counts;
    DisjointSet(int size): parent(size), counts(size, 1){
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    int merge(int a, int b){
        int parentA = find(a), parentB = find(b);
        if(parentA == parentB)
            return counts[parentA];
        else{
            if(counts[parentB] > counts[parentA]){
                counts[parentB] += counts[parentA];
                parent[parentA] = parentB;
                return counts[parentB];
            }else{
                counts[parentA] += counts[parentB];
                parent[parentB] = parentA;
                return counts[parentA];
            }
        }
    }
};


// simple version
struct DisjointSet{
    vector<int> parent;
    vector<int> counts;
    DisjointSet(int size): parent(size), counts(size, 1){
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    int merge(int childIdx, int parentIdx){
        int newChildIdx = find(childIdx), newParentIdx = find(parentIdx);
        if(newChildIdx == newParentIdx)
            return counts[newChildIdx];
        else{
            counts[newParentIdx] += counts[newChildIdx];
            parent[newChildIdx] = newParentIdx;
            return counts[newParentIdx];
        }
    }
};

// class version
class DisjoinSet {
public:
    vector<int> parents;
    vector<int> size;
    
    DisjoinSet(int n) {
        size = vector<int>(n, 1);
        
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
        }
    }
    
    int getParent(int v) {
        if (parents[v] == v) {
            return v;
        }
        
        return parents[v] = getParent(parents[v]);
    }
    
    void merge(int m, int n) {
        int pm = getParent(m);
        int pn = getParent(n);
        if (size[pm] < size[pn]) {
            swap(pm,pn);
        }
        parents[pn] = pm;
        size[pm] += size[pn];
    }
    
};

