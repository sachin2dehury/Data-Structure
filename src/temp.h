//============================================================================
// Name        : Heap Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Heap Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

class edge{
	public:
		int src;
		int dst;
		int cost;
		edge(int a,int b,int c=1){
			src=a;
			dst=b;
			cost=c;
		}
};


vector<edge> Edge(){
	vector<edge> v;
    v.push_back({0, 1, 4});
    v.push_back({0, 7, 8});
    v.push_back({1, 2, 8});
    v.push_back({1, 7, 11});
    v.push_back({2, 3, 7});
    v.push_back({2, 8, 2});
    v.push_back({2, 5, 4});
    v.push_back({3, 4, 9});
    v.push_back({3, 5, 14});
    v.push_back({4, 5, 10});
    v.push_back({5, 6, 2});
    v.push_back({6, 7, 1});
    v.push_back({6, 8, 6});
    v.push_back({7, 8, 7});
//	v.push_back({0,1});
//	v.push_back({0,3});
//	v.push_back({1,2});
//	v.push_back({3,4});
//	v.push_back({3,7});
//	v.push_back({4,5});
//	v.push_back({4,6});
//	v.push_back({4,7});
//	v.push_back({5,6});
//	v.push_back({6,7});
	return v;
}

vector<vector<int>> Graph(){
	vector<edge> v=Edge();
	int n=8;
	vector<vector<int>> u(n);
	for(auto i : v){
		u[i.src].push_back(i.dst);
		u[i.dst].push_back(i.src);
	}
	return u;
}

void DFS(vector<vector<int>> &v,int s){
	stack<int> q;
	q.push(s);
	vector<bool> d(v.size());
	while(!q.empty()){
		s=q.top();
		q.pop();
		d[s]=1;
		cout<<s<<' ';
		for(int i : v[s]){
			if(!d[i]){
				q.push(i);
			}
		}
	}
}

void BFS(vector<vector<int>> &v,int s){
	queue<int> q;
	q.push(s);
	vector<bool> d(v.size());
	while(!q.empty()){
		s=q.front();
		q.pop();
		d[s]=1;
		cout<<s<<' ';
		for(int i : v[s]){
			if(!d[i]){
				q.push(i);
			}
		}
	}
}

bool BFSCycle(vector<vector<int>> &v,int s=0){
	queue<int> q;
	q.push(s);
	vector<bool> d(v.size());
	while(!q.empty()){
		s=q.front();
		q.pop();
		d[s]=1;
		cout<<s<<' ';
		for(int i : v[s]){
			if(!d[i]){
				q.push(i);
			} else {
				return 1;
			}
		}
	}
	return 0;
}

bool DFSCycle(vector<vector<int>> &v,int s=0){
	stack<int> q;
	q.push(s);
	vector<bool> d(v.size());
	while(!q.empty()){
		s=q.top();
		q.pop();
		d[s]=1;
		cout<<s<<' ';
		for(int i : v[s]){
			if(!d[i]){
				q.push(i);
			} else {
				return 1;
			}
		}
	}
	return 0;
}

void DFSTwoSource(vector<vector<int>> &v,int s,int d){
	stack<int> q;
	q.push(s);
	vector<int> u(v.size(),INT_MAX-1);
	u[s]=0;
	while(!q.empty()){
		s=q.top();
		q.pop();
		cout<<s<<' ';
		for(int i : v[s]){
			if(u[i]>u[s]+1){
				u[i]=u[s]+1;
				q.push(i);
//				if(i==d)
//					break;
			}
		}
	}
	cout<<endl;
	for(int i : u)
		cout<<i<<' ';
	cout<<endl;
}

void BFSTwoSource(vector<vector<int>> &v,int s,int d){
	queue<int> q;
	q.push(s);
	vector<int> u(v.size(),INT_MAX);
	u[s]=0;
	while(!q.empty()){
		s=q.front();
		q.pop();
		cout<<s<<' ';
		for(int i : v[s]){
			if(u[i]>u[s]+1){
				u[i]=u[s]+1;
				q.push(i);
//				if(i==d)
//					break;
			}
		}
	}
	cout<<endl;
	for(int i : u)
		cout<<i<<' ';
	cout<<endl;
}


void Dijkstra(vector<edge> &v,int s){
	int n=9;
	priority_queue<int> q;
	vector<int> u(n,INT_MAX);
	u[s]=0;
	q.push(s);
	while(!q.empty()){
		s=q.top();
		q.pop();
		for(auto j : v){
			if(j.src==s){
				if(u[j.dst]>u[s]+j.cost){
					u[j.dst]=j.cost+u[s];
					q.push(j.dst);
				}
			}
		}
	}
	cout<<endl;
	for(int i : u)
		cout<<i<<' ';
	cout<<endl;
}

void ChessKnight(int x,int y,int a,int b){
	vector<pair<int,int>> moves={
			{-2,-1},{2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{2,1},{1,2}
	};
	int s=0;
	int n=4;
	queue<pair<pair<int,int>,int>> q;
	q.push({{x,y},0});
	while(!q.empty()){
		auto k=q.front();
		q.pop();
		s=k.second;
		if(k.first.first==a && k.first.second==b)
			break;
		for(auto t : moves){
			int i=k.first.first+t.first;
			int j=k.first.second+t.second;
			if(i>=0 && j>=0 && i<n && j<n){
					q.push({{i,j},k.second+1});
			}
		}
	}
	cout<<s;
}

int MinJumps(vector<int> &a){
	int n=a.size();
	vector<int> v(n,INT_MAX);
	v[0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(i<=j+a[j]) {
				v[i]=v[j]+1;
				break;
			}
		}
	}
	for(int i : v)
		cout<<i<<' ';
	cout<<endl;
	return v[n-1];
}

int Islands(vector<vector<bool>> &a){
	queue<pair<int,int>> q;
	int m=a.size();
	int n=a[0].size();
	int k=0;
	vector<vector<bool>> v(m,vector<bool>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j] && !v[i][j]){
				q.push({i,j});
				k++;
				while(!q.empty()){
					auto s=q.front();
					q.pop();
					int i=s.first;
					int j=s.second;
					if(!v[i][j] && a[i][j]){
						v[i][j]=1;
						q.push({i,j});
					}
				}
			}
		}
	}
	cout<<k;
	return k;
}
//
//int main(int argc, char **argv) {
//	return 0;
//}


