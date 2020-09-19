//============================================================================
// Name        : Array Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Array Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

class StackUsingQueue{
	private:
		queue<int> q;
		queue<int> s;
	public:
		void push(int x){
			while(!q.empty()){
				s.push(q.front());
				q.pop();
			}
			q.push(x);
			while(!s.empty()){
				q.push(s.front());
				s.pop();
			}
		}
		int pop(){
			int x=q.front();
			q.pop();
			return x;
		}
		bool isEmpty(){
			return q.empty();
		}
		int size(){
			return q.size();
		}
};

class KStacks{
	private:
		vector<int> v;
		vector<int> t;
		int n;
		int k;
	public:
		KStacks(int k,int n){
			this->k=k;
			this->n=n;
			v.resize(k*n);
			t.resize(k);
			for(int i=0;i<k;i++)
				t[i]=i*n;
		}
		void push(int k,int x){
			v[t[k-1]]=x;
			t[k-1]++;
		}
		int pop(int k,int x){
			t[k-1]--;
			return v[t[k-1]-1];
		}
		bool isEmpty(int k){
			return t[k-1]==(k-1)*n;
		}
		bool isFull(int k){
			return t[k-1]==k*n-1;
		}
};

class MinStack{
	private:
		stack<int> s;
		int k=INT_MAX;
	public:
		void push(int x){
			if(s.empty()){
				k=x;
				s.push(x);
			}
			else if(k<x){
				s.push(2*x-k);
				k=x;
			}
		}
		int pop(){
			int x=s.top();
			s.pop();
			if(x<k){
				int t=k;
				k=2*k-s.top();
				return t;
			} else {
				return x;
			}
		}
		bool isEmpty(){
			return s.empty();
		}
		int size(){
			return s.size();
		}
};

class StackUsingDequeue{
	private:
		deque<int> q;
	public:
		void push(int x){
			q.push_back(x);
		}
		int pop(){
			int x=q.back();
			q.pop_back();
			return x;
		}
		bool isEmpty(){
			return q.empty();
		}
		int size(){
			return q.size();
		}
};

vector<int> NGR(vector<int> &a,int n){
	stack<int> s;
	vector<int> v(n);
	for(int i=n-1;i>=0;i--){
		if(s.empty())
			v[i]=-1;
		else if(s.top()>a[i])
			v[i]=s.top();
		else {
			while(!s.empty() && s.top()<=a[i])
				s.pop();
			if(s.empty())
				v[i]=-1;
			else
				v[i]=s.top();
		}
		s.push(a[i]);
	}
	for(int i : v)
		cout<<i<<' ';
	return v;
}

int Celebrity(vector<vector<bool>> &a){
	int n=a.size();
	int l=0;
	int h=n-1;
	while(l<h){
		if(a[l][h])
			l++;
		else
			h--;
	}
	for(int i=0;i<n;i++){
		if((!a[i][l] || a[l][i]) && i!=l)
			return -1;
	}
	return l;
}

void pushBottom(stack<int> &s,int x){
	if(s.empty())
		s.push(x);
	else {
		int i=s.top();
		s.pop();
		pushBottom(s, i);
		s.push(x);
	}
}

void ReverseStackRecursion(stack<int> &s){
	if(s.empty())
		return;
	int x=s.top();
	s.pop();
	ReverseStackRecursion(s);
	pushBottom(s, x);
}

void ReverseStack(vector<int> &a){
	stack<int> s;
	for(int i : a)
		pushBottom(s, i);
//		s.push(i);
//	ReverseStackRecursion(s);
	while(!s.empty()){
		cout<<s.top()<<' ';
		s.pop();
	}
}

void pushSorted(stack<int> &s,int x){
	if(s.empty() || x<s.top())
		s.push(x);
	else {
		int i=s.top();
		s.pop();
		pushSorted(s, x);
		s.push(i);
	}
}

void SortStackRecursion(stack<int> &s){
	if(s.empty())
		return;
	int x=s.top();
	s.pop();
	SortStackRecursion(s);
	pushSorted(s,x);
}

void SortStack(vector<int> &a){
	stack<int> s;
	for(int i : a)
		s.push(i);
	SortStackRecursion(s);
	while(!s.empty()){
		cout<<s.top()<<' ';
		s.pop();
	}
}

pair<int,int> MergeInterval(vector<pair<int,int>> &a){
//	sort(a.begin(),a.end(),[](auto &x,auto &y){return x.first>y.first;});
	stack<pair<int,int>> s;
	for(auto i : a){
		if(s.empty())
			s.push(i);
		else if(s.top().second>=i.first && i.second>=s.top().first){
			auto k=s.top();
			s.pop();
			s.push({min(i.first,k.first),max(i.second,k.second)});
		}
		else
			s.push(i);
	}
//	while(!s.empty()){
//		cout<<s.top().first<<' '<<s.top().second<<'\n';
//		s.pop();
//	}
	return s.top();
}

int LargestAreaHistogram(vector<int> &a){
	int n=a.size();
	vector<int> u(n);
	vector<int> v(n);
	stack<int> s;
	for(int i=0;i<n;i++){
		if(s.empty())
			u[i]=-1;
		else if(a[s.top()]<a[i])
			u[i]=s.top();
		else {
			while(!s.empty() && a[s.top()]>=a[i])
				s.pop();
			if(s.empty())
				u[i]=-1;
			else
				u[i]=s.top();
		}
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	for(int i=n-1;i>=0;i--){
		if(s.empty())
			v[i]=n;
		else if(a[s.top()]<a[i])
			v[i]=s.top();
		else {
			while(!s.empty() && a[s.top()]>=a[i])
				s.pop();
			if(s.empty())
				v[i]=n;
			else
				v[i]=s.top();
		}
		s.push(i);
	}
	int k=INT_MIN;
	for(int i=0;i<n;i++){
		v[i]=(v[i]-u[i]-1)*a[i];
		k=max(k,v[i]);
		cout<<v[i]<<' ';
	}
	return k;
}

int DifferenceNSRandNSL(vector<int> &a){
	int n=a.size();
	vector<int> u(n);
	vector<int> v(n);
	stack<int> s;
	for(int i=0;i<n;i++){
		if(s.empty())
			u[i]=0;
		else if(s.top()<a[i])
			u[i]=s.top();
		else {
			while(!s.empty() && s.top()>=a[i])
				s.pop();
			if(s.empty())
				u[i]=0;
			else
				u[i]=s.top();
		}
		s.push(a[i]);
	}
	while(!s.empty())
		s.pop();
	for(int i=n-1;i>=0;i--){
		if(s.empty())
			v[i]=0;
		else if(s.top()<a[i])
			v[i]=s.top();
		else {
			while(!s.empty() && s.top()>=a[i])
				s.pop();
			if(s.empty())
				v[i]=0;
			else
				v[i]=s.top();
		}
		s.push(a[i]);
	}
	int k=INT_MIN;
	for(int i=0;i<n;i++){
		v[i]=(v[i]-u[i]);
		k=max(k,v[i]);
		cout<<v[i]<<' ';
	}
	return k;
}

int LongestParanthesis(string &a){
	int n=a.length();
	stack<int> s;
	s.push(-1);
	int m=0;
	for(int i=0;i<n;i++){
		if(a[i]=='(')
			s.push(i);
		else {
			s.pop();
			if(s.empty())
				s.push(i);
			else
				m=max(m,i-s.top());
		}
	}
	return m;
}

bool RedundantBrackets(string &a){
	int n=a.length();
	stack<char> s;
	if(n<3)
		return 0;
	else {
		for(char i : a){
			if(i==')'){
				if(s.top()=='(')
					return 1;
				while(!s.empty() && s.top()!='(')
					s.pop();
				s.pop();
			}
			else
				s.push(i);
		}
	}
	return 0;
}

string RemoveBrackets(string &a){
	bool f=0;
	int n=a.length();
	string b;
	stack<char> s;
	for(int i=0;i<n;i++){
		if(a[i]=='('){
			while(!s.empty() && s.top()=='(')
				s.pop();
			if(s.top()=='+')
				f=0;
			else
				f=1;
		}
		else if(a[i]==')')
			;
		else if(f) {
			if(a[i]=='-')
				b.push_back('+');
			else if(a[i]=='+')
				b.push_back('-');
			else
				b.push_back(a[i]);
		}
		else if(a[i]=='+' || a[i]=='-') {
			s.push(a[i]);
			b.push_back(a[i]);
		}
		else
			b.push_back(a[i]);
	}
	return b;
}

int MinBracketReversal(string &a){
	int n=a.length();
	if(n%2)
		return -1;
	stack<char> s;
	for(char i : a){
		if(i=='}'){
			if(!s.empty() && s.top()=='{')
				s.pop();
			else
				s.push(i);
		}
		else
			s.push(i);
	}
	int m=s.size();
	n=0;
	while(!s.empty() && s.top()=='{'){
		s.pop();
		n++;
	}
	return m/2+n%2;
}

///Problems Remaining

