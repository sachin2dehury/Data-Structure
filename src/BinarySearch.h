//============================================================================
// Name        : Heap Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Heap Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int BinarySearch(vector<int> &a,int k){
	int l=0;
	int h=a.size()-1;
	while(l<=h){
		int m=l+(h-l)/2;
		if(a[m]==k)
			return m;
		else if(a[m]<k)
			l=m+1;
		else
			h=m-1;
	}
	return -1;
}

int FirstOccurance(vector<int> &a,int k){
	int l=0;
	int h=a.size()-1;
	int x=-1;
	while(l<=h){
		int m=l+(h-l)/2;
		if(a[m]==k)
			h=m-1,x=m;
		else if(a[m]<k)
			l=m+1;
		else
			h=m-1;
	}
	return x;
}

int LastOccurance(vector<int> &a,int k){
	int l=0;
	int h=a.size()-1;
	int x=-1;
	while(l<=h){
		int m=l+(h-l)/2;
		if(a[m]==k)
			l=m+1,x=m;
		else if(a[m]<k)
			l=m+1;
		else
			h=m-1;
	}
	return x;
}

int NumberOfRotation(vector<int> &a){
	int s=a.size();
	int l=0;
	int h=s-1;
	while(l<=h){
		int m=l+(h-l)/2;
		int p=(s+m-1)%s;
		int n=(m+1)%s;
		if(a[m]<a[p] && a[m]<a[n])
			return s-m;
		else if(a[m]<a[h])
			h=m-1;
		else
			l=m+1;
	}
	return 0;
}

int PeakElement(vector<int> &a){
	int l=0;
	int s=a.size();
	int h=s-1;
	while(l<=h){
		int m=l+(h-l)/2;
		if(m==0 || m==s-1){
			if(m==0 && a[m]>a[m+1])
				return a[m];
			else if(m==s-1 && a[m]>a[m-1])
				return a[m];
		} else {
			if(a[m]>a[m-1] && a[m]>a[m+1])
				return a[m];
			else if(a[m]<a[m+1])
				l=m+1;
			else
				h=m-1;
		}
	}
	return -1;
}

int MaxBitonicElement(vector<int> &a){
	int l=0;
	int h=a.size()-1;
	while(l<=h){
		int m=l+(h-l)/2;
		if(a[m]>a[m-1] && a[m]>a[m+1])
			return a[m];
		else if(a[m]<a[m+1])
			l=m+1;
		else
			h=m-1;
	}
	return -1;
}

int Reader(vector<int> &a,int m){
	int k=1;
	int s=0;
	for(int i : a){
		s+=i;
		if(s>m){
			k++;
			s=i;
		}
	}
	return k;
}

int AllocateMinPages(vector<int> &a,int k){
	int h=0;
	for(int i : a)
		h+=i;
	int l=0;
	int p=-1;
	while(l<=h){
		int m=l+(h-l)/2;
		int r=Reader(a, m);
		if(r<=k)
			h=m-1,p=m;
		else
			l=m+1;
	}
	return p;
}
