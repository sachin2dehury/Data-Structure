//============================================================================
// Name        : Sort Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Sort Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

void Merge(vector<int> &a,int l,int m,int h,vector<int> &v){
	int i=l;
	int j=m+1;
	int k=l;
	while(i<=m && j<=h){
		if(a[i]<=a[j]){
			v[k]=a[i];
			i++;
		} else {
			v[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=m){
		v[k]=a[i];
		i++;
		k++;
	}
	while(j<=h){
		v[k]=a[j];
		j++;
		k++;
	}
	for(int i=l;i<=h;i++){
		a[i]=v[i];
	}
}

void Partition(vector<int> &a,int l,int h,vector<int> &v){
	if(l<h){
		int m=l+(h-l)/2;
		Partition(a, l, m, v);
		Partition(a, m+1, h, v);
		Merge(a, l, m, h, v);
	}
}

void MergeSort(vector<int> &a){
	int l=0;
	int h=a.size()-1;
	vector<int> v(h+1);
	Partition(a, l, h, v);
	for(int i : v)
		cout<<i<<' ';
}

void Swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}

int Pivot(vector<int> &a,int l,int h){
	int i=l;
	for(int j=l;j<h;j++){
		if(a[j]<a[h]){
			Swap(a[j],a[i]);
			i++;
		}
	}
	Swap(a[i], a[h]);
	return i;
}

void Partition(vector<int> &a,int l,int h){
	if(l<h){
		int p=Pivot(a, l, h);
		Partition(a, l, p-1);
		Partition(a, p+1, h);
	}
}

void QuickSort(vector<int> &a){
	int l=0;
	int h=a.size()-1;
	Partition(a, l, h);
	for(int i : a)
		cout<<i<<' ';
}

void IterativeMergeSort(vector<int> &a){
	int n=a.size();
	vector<int> v=a;
	for(int m=1;m<n;m*=2){
		for(int i=0;i<n-1;i+=2*m){
			int l=i;
			int h=min(n-1,2*m+i-1);
			Merge(a, l, i+m-1, h, v);
		}
	}
	for(int i : v)
		cout<<i<<' ';
}


//int main(int argc, char **argv) {
//	vector<int> a={5,4,3,2,1};
//	QuickSort(a);
//	return 0;
//}

