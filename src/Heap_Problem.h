//============================================================================
// Name        : Heap Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Heap Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int MinSumSquare(string &a,int k){
	unordered_map<char,int> v;
	priority_queue<int> q;
	for(char i :a)
		v[i]++;
	for(auto i : v)
		q.push(i.second);
	while(k && !q.empty()){
		int i=q.top();
		q.pop();
		k--;
		i--;
		q.push(i);
	}
	int s=0;
	while(!q.empty()){
		int i=q.top();
		q.pop();
		s+=i*i;
	}
	cout<<s;
	return s;
}

int KLargest(vector<int> &a,int k){
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i : a){
		q.push(i);
		if((int)q.size()>k)
			q.pop();
	}
	return q.top();
}

bool isHeap(vector<int> &a){
	int n=a.size()/2;
	for(int i=0;i<n;i++){
		int x=2*i+1;
		int y=2*i+2;
		if(a[i]>max(a[x],a[y]))
			return 0;
	}
	return 1;
}

int ConnectRopes(vector<int> &a){
	priority_queue<int> q;
	for(int i : a)
		q.push(i);
	int s=0;
	while(q.size()>1){
		int i=q.top();
		q.pop();
		int j=q.top();
		q.pop();
		q.push(i+j);
		s+=i;
	}
	cout<<s;
	return s;
}

void MergeArray(vector<int> &a,vector<int> &b){
	priority_queue<int> q;
	for(int i : a)
		q.push(i);
	for(int i : b)
		q.push(i);
	while(!q.empty()){
		cout<<q.top()<<' ';
		q.pop();
	}
}

int MaxDistinctElement(vector<int> &a,int k){
	unordered_map<int,int> u;
	for(int i : a)
		u[i]++;
	priority_queue<int> q;
	for(auto i : u)
		q.push(i.second);
	for(int i=0;i<k;i++){
		int x=q.top()-1;
		q.pop();
		q.push(x);
	}
	int s=0;
	while(!q.empty()){
		if(q.top()==1)
			s++;
		q.pop();
	}
	cout<<s;
	return s;
}

void Median(vector<int> &a){
	int n=a.size();
	double s;
	for(int i=0;i<n;i++){
		s+=a[i];
		cout<<s/(i+1)<<' ';
	}
}

void LargestTripletProduct(vector<int> &a){
	priority_queue<int> q;
	for(int i : a){
		q.push(i);
		if(q.size()<3)
			cout<<-1<<' ';
		else {
			int x=q.top();
			q.pop();
			int y=q.top();
			q.pop();
			int z=q.top();
			q.push(x);
			q.push(y);
			cout<<x*y*z<<' ';
		}
	}
}

void BuildMinHeap(vector<int> &a){
	int n=a.size();
	for(int i=n/2-1;i>=0;i--)
	{
		int k=a[2*i+1]<a[2*i+2] ? 2*i+1: 2*i+2;
		while(i<n/2 && a[k]<a[i]){
			int t=a[i];
			a[i]=a[k];
			a[k]=t;
			cout<<i<<'\n';
			i=k;
			k=a[2*i+1]<a[2*i+2] ? 2*i+1: 2*i+2;
		}
	}
	for(int i : a)
		cout<<i<<' ';
}

int KContiguosSum(vector<int> &a,int k){
	int s=0;
	vector<int> v;
	v.push_back(0);
	for(int i : a){
		s+=i;
		v.push_back(s);
	}
	priority_queue<int,vector<int>,greater<int>> q;
	int n=a.size();
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			q.push(v[j]-v[i-1]);
			if((int)q.size()>k)
				q.pop();
		}
	}
	return q.top();
}

int MinSum(vector<int> &a){
	priority_queue<int,vector<int>,greater<int>> q;
	int s1=0;
	int s2=0;
	for(int i : a)
		q.push(i);
	while(!q.empty()){
		s1=s1*10+q.top();
		q.pop();
		if(!q.empty()){
			s2=s2*10+q.top();
			q.pop();
		}
		cout<<s1<<' '<<s2<<'\n';
	}
	return s1+s2;
}

///Problems

//int main(int argc, char **argv) {
//	vector<vector<int>> a={
//	{ 4, 7, 9, 12, 15 },
//    { 0, 8, 10, 14, 20 },
//    { 6, 12, 16, 30, 50 }
//	};
//	return 0;
//}
