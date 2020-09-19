//============================================================================
// Name        : Heap Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Heap Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

void ReplaceRepeatingValue(vector<int> &a){
	unordered_set<int> s;
	int k=INT_MIN;
	for(int i : a)
		k=max(i,k);
	for(int &i : a){
		if(s.find(i)==s.end())
			s.insert(i);
		else
			i=++k;
	}
	for(int i : a)
		cout<<i<<' ';
}

void ReplaceDuplicate(vector<int> &a){
	unordered_set<int> s;
	unordered_set<int> u;
	u.insert(a.begin(), a.end());
	for(int &i : a){
		if(s.find(i)==s.end())
			s.insert(i);
		else {
			while(u.find(i)!=u.end())
				i++;
			u.insert(i);
		}
	}
	for(int i : a)
		cout<<i<<' ';
}

void TripletAP(vector<int> &a){
	unordered_set<int> s;
	int n=a.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int d=a[j]-a[i];
			if(s.find(a[i]-d)!=s.end())
				cout<<a[i]-d<<' '<<a[i]<<' '<<a[j]<<'\n';
		}
		s.insert(a[i]);
	}
}

void XORTriplets(vector<int> &a){
	int n=a.size();
	unordered_set<int> s;
	int k=0;
	s.insert(a.begin(), a.end());
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int x=a[i]^a[j];
			if(s.find(x)!=s.end() && a[i]!=x && a[j]!=x)
				k++;
		}
	}
	cout<<k/3;
}

bool SubArraySumZero(vector<int> &a){
	int s=0;
	unordered_set<int> v;
	for(int i : a){
		s=s+i;
		if(v.find(s)!=v.end() || s==0)
			return 1;
		else
			v.insert(s);
	}
	return 0;
}

void Divisible(vector<int> &a){
	int n=a.size();
	unordered_set<int> s;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]%a[i]==0 && s.find(a[j])==s.end())
				s.insert(a[j]);
		}
	}
	for(int i : s)
		cout<<i<<' ';
}

void PairProduct(vector<int> &a,int k){
	unordered_map<int,int> v;
	for(int i : a)
		v[i]++;
	for(auto i : a)
		if(v.find(k/i)!=v.end() && (k/i)*i==k)
			cout<<i<<' '<<k/i<<'\n';
}

int LongestSubArrayGreaterThanK(vector<int> &a,int k){
	int c=0;
	int m=0;
	for(int i : a){
		if(i>k)
			c++;
		else
			c=0;
		m=max(m,c);
	}
	cout<<m;
	return m;
}

bool absPairDifference(vector<vector<int>> &a,int k){
	unordered_set<int> s;
	for(auto i : a)
		for(int j : i)
			s.insert(j);
	for(auto i : a)
		for(int j : i)
			if(s.find(k+j)!=s.end())
				return 1;
	return 0;
}

int UniqueNumbers(int n){
	unordered_set<int> s;
	while(s.find(n)==s.end()){
		s.insert(n);
		n++;
		if(n%10==0)
			n/=10;
	}
	for(int i : s)
		cout<<i<<' ';
	cout<<'\n';
	return s.size();
}

///Problems

//int main(int argc, char **argv) {
//	return 0;
//}
