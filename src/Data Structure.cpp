//============================================================================
// Name        : Heap Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Heap Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

void ratMaze(vector<vector<int>> &a,int i, int j, int x,int y,string s){
	if(i==x && j==y){
		cout<<s<<'\n';
		return;
	}
	if(i>x || j>y)
		return;
	if(i<x && a[i+1][j])
		ratMaze(a, i+1, j, x, y, s+'D');
	if(j<y && a[i][j+1])
		ratMaze(a, i, j+1, x, y, s+'R');
}
//
//int main(int argc, char **argv) {
//	vector<vector<int>> a={{1, 0, 0, 0},
//            {1, 1, 0, 1},
//            {1, 1, 0, 0},
//            {0, 1, 1, 1}};
//	int i=0,j=0;
//	int x=3,y=3;
//	string s="";
//	ratMaze(a, i, j, x, y, s);
//	return 0;
//}
