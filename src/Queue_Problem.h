//============================================================================
// Name        : Queue Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Queue Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

class QueueUsingStack{
	private:
		stack<int> q;
		stack<int> s;
	public:
		void push(int x){
			if(s.empty())
				s.push(x);
			else {
				while(!s.empty()){
					q.push(s.top());
					s.pop();
				}
				s.push(x);
				while(!q.empty()){
					s.push(q.top());
					q.pop();
				}
			}
		}
		int pop(){
			int x=s.top();
			s.pop();
			return x;
		}
		bool isEmpty(){
			return s.empty();
		}
		int size(){
			return s.size();
		}
};

struct node{
	public:
		int data;
		node* r;
		node* l;
		node(int x){
			data=x;
			r=nullptr;
			l=nullptr;
		}
};

void LevelOrder(node* root){
	if(!root)
		return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		cout<<root->data<<' ';
		q.pop();
		if(root->l)
			q.push(root->l);
		if(root->r)
			q.push(root->r);
	}
}

void ReverseQueueRecursion(queue<int> &q){
	if(q.empty())
		return;
	int x=q.front();
	q.pop();
	ReverseQueueRecursion(q);
	q.push(x);
}

void ReverseQueue(vector<int> &a){
	queue<int> q;
	for(int i : a)
		q.push(i);
	ReverseQueueRecursion(q);
	while(!q.empty()){
		cout<<q.front()<<' ';
		q.pop();
	}
}

void ReverseFirstK(vector<int> &a,int k){
	queue<int> q;
	stack<int> s;
	for(int i : a)
		q.push(i);
	int n=q.size();
	for(int i=0;i<k;i++){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	for(int i=k;i<n;i++){
		q.push(q.front());
		q.pop();
	}
	while(!q.empty()){
		cout<<q.front()<<' ';
		q.pop();
	}
}

void InterleavedQueue(vector<int> &a){
	queue<int> q;
	queue<int> s;
	for(int i : a)
		q.push(i);
	int n=q.size()/2;
	for(int i=0;i<n;i++){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.front());
		s.pop();
		q.push(q.front());
		q.pop();
	}
	while(!q.empty()){
		cout<<q.front()<<' ';
		q.pop();
	}
}

bool isSafe(int x,int y,int m,int n){
	return (x>=0 && x<m && y>=0 && y<n);
}

int RottenOrange(vector<vector<int>> &a){
	int m=a.size();
	int n=a[0].size();
	int k=0;
	queue<pair<int,int>> q;
	vector<pair<int,int>> move={
			{0,1},{1,0},{0,-1},{-1,0}
	};
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==2)
				q.push({i,j});
		}
	}
	while(!q.empty()){
		bool f=0;
		auto v=q.front();
		q.pop();
		for(auto i : move){
			int x=i.first+v.first;
			int y=i.second+v.second;
			if(isSafe(x,y,m,n) && a[x][y]==1){
				a[x][y]=2;
				q.push({x,y});
				f=1;
			}
		}
		k+=f;
	}
	return k/4+1;
}

int MaxLevelOrderSum(node* root){
	if(!root)
		return 0;
	queue<pair<node*,int>> q;
	unordered_map<int,int> v;
	int k=0;
	q.push({root,k});
	while(!q.empty()){
		root=q.front().first;
		k=q.front().second;
		v[k]+=root->data;
		q.pop();
		if(root->l)
			q.push({root->l,k+1});
		if(root->r)
			q.push({root->r,k+1});
	}
	for(auto i : v)
		k=max(i.second,k);
	return k;
}

void MinDistnce(vector<vector<bool>> &a){
	int m=a.size();
	int n=a[0].size();
	int d[m][n];
	queue<pair<int,int>> q;
	vector<pair<int,int>> move={
			{0,1},{1,0},{0,-1},{-1,0}
	};
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]) {
				q.push({i,j});
				d[i][j]=0;
			}
		}
	}
	while(!q.empty()){
		auto v=q.front();
		q.pop();
		for(auto i : move){
			int x=i.first+v.first;
			int y=i.second+v.second;
			if(isSafe(x,y,m,n) && !a[x][y]){
				a[x][y]=1;
				d[x][y]=1+d[v.first][v.second];
				q.push({x,y});
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<d[i][j]<<' ';
		cout<<'\n';
	}
}

void FirstNegative(vector<int> &a,int k){
	int n=a.size();
	for(int i=0;i<=n-k;i++){
		int v=0;
		for(int j=i;j<i+k && j<(int)a.size() ;j++){
			if(a[j]<0){
				v=a[j];
				break;
			}
		}
		cout<<v<<' ';
	}
}

bool TreeAnagram(node* root1,node* root2){
	if(!root1 && !root2)
		return 1;
	queue<pair<node*,int>> q;
	map<int,set<int>> v;
	map<int,set<int>> u;
	int k=0;
	q.push({root1,k});
	while(!q.empty()){
		root1=q.front().first;
		k=q.front().second;
		v[k].insert(root1->data);
		q.pop();
		if(root1->l)
			q.push({root1->l,k+1});
		if(root1->r)
			q.push({root1->r,k+1});
	}
	k=0;
	q.push({root2,k});
	while(!q.empty()){
		root2=q.front().first;
		k=q.front().second;
		u[k].insert(root2->data);
		q.pop();
		if(root2->l)
			q.push({root2->l,k+1});
		if(root2->r)
			q.push({root2->r,k+1});
	}
	vector<int> t1;
	vector<int> t2;
	for(auto i : v)
		for(auto j : i.second)
			t1.push_back(j);
	for(auto i : u)
		for(auto j : i.second)
			t2.push_back(j);
	if(t1.size()!=t2.size())
		return 0;
	for(int i=0;i<(int)t1.size();i++){
		if(t1[i]!=t2[i])
			return 0;
	}
	return 1;
}

int SubArrayMaxMinSum(vector<int> &a,int k){
	int n=a.size();
	int s=0;
	for(int i=0;i<n-k;i++){
		int mn=INT_MAX;
		int mx=INT_MIN;
		for(int j=i;j<k && j<n;j++){
			mn=min(mn,a[j]);
			mx=max(mx,a[j]);
		}
		s+=mx+mn;
	}
	cout<<s;
	return s;
}

void FirstNonRepeating(string &a){
	vector<bool> v(26);
	queue<char> q;
	for(char i : a){
		if(!v[i-'a']){
			q.push(i);
			v[i-'a']=1;
			cout<<q.front()<<' ';
		} else {
			q.pop();
			cout<<"-1 ";
		}
	}
}

int StartPoint(vector<pair<int,int>> &a){
	queue<pair<int,int>> q;
	int n=a.size();
	int x=-1;
	for(int i=0;i<n;i++){
		q.push(a[i]);
		x++;
		int p=0;
		while(!q.empty()){
			auto k=q.front();
			q.pop();
			if(k.first+p<k.second){
				q.push(k);
				break;
			}
			else if(k.first+q.front().first+p<k.second+q.front().second){
				q.push(k);
				break;
			}
			else
				p=k.first-k.second;
		}
	}
	return x;
}


