//============================================================================
// Name        : Heap Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Heap Problems in C++,inc[i][j][istrue]i-style
//============================================================================


#include <bits/stdc++.h>

using namespace std;

class Heap_Problems{
	public:
		int K_Smallest(vector<int> &a,int &n,int &k)
		{
			priority_queue<int> v;
			for(int i : a)
			{
				v.push(i);
				if((int)v.size()>k)
					v.pop();
			}
			return v.top();
		}
		int K_Largest(vector<int> &a,int &n,int &k)
		{
			priority_queue<int,vector<int>,greater<int>> v;
			for(int i : a)
			{
				v.push(i);
				if((int)v.size()>k)
					v.pop();
			}
			return v.top();
		}
		vector<int> K_Sorted(vector<int> &a,int &n,int &k)
		{
			priority_queue<int,vector<int>,greater<int>> v;
			vector<int> s;
			for(int i : a)
			{
				v.push(i);
				if((int)v.size()>k)
					s.push_back(v.top()),v.pop();
			}
			while(!v.empty()){
				s.push_back(v.top()),v.pop();
			}
			return s;
		}
		vector<int> K_Closest(vector<int> &a,int &n,int &k,int &m)
		{
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> v;
			vector<int> s;
			for(int i : a)
			{
				v.push({abs(i-m),i});
				if((int)v.size()>=k)
					s.push_back(v.top().second),v.pop();
			}
			return s;
		}
		vector<int> Top_K_Frequent(vector<int> &a,int &n,int &k)
		{
			unordered_map<int,int> m;
			priority_queue<pair<int,int>> v;
			vector<int> s;
			for(int i : a)
				m[i]++;
			for(auto i : m)
			{
				v.push({i.second,i.first});
				if((int)v.size()>=k)
					s.push_back(v.top().second),v.pop();
			}
			return s;
		}
		vector<int> Frequency_Sort(vector<int> &a,int &n)
		{
			unordered_map<int,int> m;
			priority_queue<pair<int,int>> v;
			vector<int> s;
			for(int i : a)
				m[i]++;
			for(auto i : m)
				v.push({i.second,i.first});
			while(!v.empty()){
				s.push_back(v.top().second),v.pop();
			}
			return s;
		}
		vector<pair<int,int>> K_Closest_Origin(vector<pair<int,int>> &a,int &n,int &k)
		{
			priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> v;
			vector<pair<int,int>> s;
			int t=0;
			for(auto i : a)
			{
				t=i.first*i.first+i.second*i.second;
				v.push({t,i});
				if((int)v.size()>=k)
					s.push_back(v.top().second),v.pop();
			}
			return s;
		}
		int Connect_Ropes(vector<int> &a,int &n)
		{
			priority_queue<int,vector<int>,greater<int>> v;
			int s=0;
			for(int i : a)
				v.push(i);
			while(v.size()>1){
				int a=v.top();
				v.pop();
				int b=v.top();
				v.pop();
				v.push(a+b);
				s=s+a+b;
			}
			return s;
		}
		int Sum_Between_Ks(vector<int> &a,int &n,int &k,int &m)
		{
			int x=K_Smallest(a, n, k);
			int y=K_Smallest(a, n, m);
			int s=0;
			for(int i : a)
				if(i>x && i<y)
					s+=i;
			return s;
		}
};

class Random_Problems{
	public:

		class node{
			public:
				int data;
				node *next;
				node(int data){
					this->data=data;
					next=nullptr;
				}
		};



		node* MergeLinkedList(node** list,int k){
			priority_queue<int,vector<int>,greater<int>> q;
			node* root=nullptr;
			for(int i=0;i<k;i++){
				root=list[i];
				while(root){
					q.push(root->data);
					root=root->next;
				}
			}
			node* t=nullptr;
			for(int i=0;i<k;i++){
				root=list[i];
				if(i)
					t->next=root;
				while(root){
					t=root;
					root->data=q.top();
					q.pop();
					root=root->next;
				}
			}
			return list[0];
		}

		void Display(node* root){
			while(root){
				cout<<root->data<<' ';
				root=root->next;
			}
		}


		bool isMinHeap(vector<int> &a,int &n){
			for(int i=n-1;i>n/2-1;i--){
				if(a[i/2]>a[i])
					return 0;
			}
			return 1;
		}

		bool isMaxHeap(vector<int> &a,int &n){
			for(int i=n-1;i>n/2-1;i--){
				if(a[i/2]<a[i])
					return 0;
			}
			return 1;
		}

		vector<int> CreateMaxHeap(vector<int> &a,int &n){
			for(int j=n/2-1;j>=0;j--){
				int i=j;
				while(i<n/2){
					int k=a[2*i+1]>a[2*i+2] ? (2*i+1) : (2*i+2);
					if(a[i]<a[k]){
						int t=a[i];
						a[i]=a[k];
						a[k]=t;
						i=k;
					}
				}
			}
			return a;
		}

		vector<int> CreateMinHeap(vector<int> &a,int &n){
			for(int j=n/2-1;j>=0;j--){
				int i=j;
				while(i<n/2){
					int k=a[2*i+1]<a[2*i+2] ? (2*i+1) : (2*i+2);
					if(a[i]>a[k]){
						int t=a[i];
						a[i]=a[k];
						a[k]=t;
						i=k;
					}
				}
			}
			return a;
		}

		vector<int> MergeList(vector<vector<int>> &a,int &n){
			priority_queue<int,vector<int>,greater<int>> q;
			vector<int> v;
			for(auto i : a)
				for(auto j : i)
					q.push(j);
			while(!q.empty()){
				v.push_back(q.top());
				q.pop();
			}
			return v;
		}

};
