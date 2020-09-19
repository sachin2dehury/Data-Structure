//============================================================================
// Name        : Tree Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Tree Problems in C++,inc[i][j][istrue]i-style
//============================================================================


#include <bits/stdc++.h>

using namespace std;

class Tree{

	private:
		class node{
			public:
				int data;
				node* right;
				node* left;

				node(int data){
					this->data=data;
					right=nullptr,left=nullptr;
				}
		};

	public:

		Tree() {
		/* Construct below tree
						1
					  /   \
					/       \
				  2           3
				/   \       /   \
			   4     5     6     7
			  / \   / \   / \   / \
			 8   9 10 11 12 13 14 15
			*/

			node* root = nullptr;
			root = new node(1);
			root->left = new node(2);
			root->right = new node(3);
			root->left->left = new node(4);
			root->left->right = new node(5);
			root->right->left = new node(6);
			root->right->right = new node(7);
			root->left->left->left = new node(8);
			root->left->left->right = new node(9);
			root->left->right->left = new node(10);
			root->left->right->right = new node(11);
			root->right->left->left = new node(12);
			root->right->left->right = new node(13);
			root->right->right->left = new node(14);
			root->right->right->right = new node(15);
		}

		node* MultiLevelLinkedList(node* root){
			queue<node*> q;
			node* t=root;
			if(!root)
				return t;
			q.push(root);
			while(!q.empty()){
				root=q.front();
				while(root){
					if(root->left)
						q.push(root);
					if(root->right)
						root=root->right;
					else
						break;
				}
				root->right=q.front()->left;
				q.front()->left=nullptr;
				q.pop();
			}
			return t;
		}

		map<int,vector<int>> TreeLeftView(node* root){
			queue<pair<node*,int>> q;
			map<int,vector<int>> v;
			if(!root)
				return v;
			int l=0;
			q.push({root,l});
			while(!q.empty()){
				root=q.front().first;
				l=q.front().second;
				q.pop();
				v[l].push_back(root->data);
				if(root->left)
					q.push({root->left,l+1});
				if(root->right)
					q.push({root->right,l+1});
			}
			return v;
		}

		bool isCompleteTree(node* root){
			queue<node*> q;
			if(!root)
				return 0;
			q.push(root);
			while(!q.empty()){
				root=q.front();
				q.pop();
				bool l=0,r=0;
				if(root->left)
					q.push(root->left),l=1;
				if(root->right)
					q.push(root->right),r=1;
				if(!l && l^r)
					return 0;
			}
			return 1;
		}

		map<int,vector<int>> DiagonalView(node* root){
			queue<pair<node*,int>> q;
			map<int,vector<int>> v;
			int l=0;
			if(!root)
				return v;
			while(root){
				q.push({root,l});
				root=root->right;
			}
			while(!q.empty()){
				root=q.front().first;
				l=q.front().second;
				q.pop();
				if(root){
					v[l].push_back(root->data);
					root=root->left;
					while(root){
						q.push({root,l+1});
						root=root->right;
					}
				}
			}
			for(auto i : v){
				for(int j : i.second)
					cout<<j<<' ';
				cout<<endl;
			}
			return v;
		}

		map<int,vector<int>> CornerView(node* root){
			queue<pair<node*,int>> q;
			map<int,vector<int>> v;
			int l=0;
			if(!root)
				return v;
			q.push({root,l});
			while(!q.empty()){
				root=q.front().first;
				l=q.front().second;
				q.pop();
				v[l].push_back(root->data);
				if(root->left)
					q.push({root->left,l+1});
				if(root->right)
					q.push({root->right,l+1});
			}
			for(auto i : v){
				for(int j : i.second)
					cout<<j<<' ';
				cout<<endl;
			}
			return v;
		}

		int TreeHeight(node* root){
			queue<pair<node*,int>> q;
			int h=0;
			if(root==nullptr)
				return h;
			q.push({root,h+1});
			while(!q.empty()){
				root=q.front().first;
				h=q.front().second;
				q.pop();
				if(root->left)
					q.push({root->left,h+1});
				if(root->right)
					q.push({root->right,h+1});
			}
			return h;
		}

		bool DeleteTree(node *root){
			queue<node*> q;
			if(root==nullptr)
				return 0;
			q.push(root);
			while(!q.empty()){
				root=q.front();
				q.pop();
				if(root->left)
					q.push(root->left);
				if(root->right)
					q.push(root->right);
				delete root;
			}
			return 1;
		}

		vector<int> LevelOrder(node* root){
			queue<node*> q;
			vector<int> v;
			if(root==nullptr)
				return v;
			q.push(root);
			while(!q.empty()){
				root=q.front();
				q.pop();
				v.push_back(root->data);
				if(root->left)
					q.push(root->left);
				if(root->right)
					q.push(root->right);
			}
			return v;
		}

		void InvertAlternetTree(node* left,node* right,bool level){
			if(!left || !right)
				return;
			if(level){
				int t=left->data;
				left->data=right->data;
				right->data=t;
			}
			InvertAlternetTree(left->left, right->right, !level);
			InvertAlternetTree(right->left, left->right, !level);
		}

		void InvertAlternetTree(node* root){
			if(root!=nullptr)
				InvertAlternetTree(root->left,root->right,1);
		}

		vector<int> ReverseLevelOrder(node* root){
			queue<node*> q;
			stack<int> s;
			vector<int> v;
			if(root==nullptr)
				return v;
			q.push(root);
			while(!q.empty()){
				root=q.front();
				q.pop();
				s.push(root->data);
				if(root->right)
					q.push(root->right);
				if(root->left)
					q.push(root->left);
			}
			while(!s.empty()){
				v.push_back(s.top());
				s.pop();
			}
			return v;
		}

		node* ReverseTree(node* root){
			stack<node*> s;
			node *t=nullptr;
			if(root==nullptr)
				return root;
			s.push(root);
			while(!s.empty()){
				root=s.top();
				s.pop();
				t=root->left;
				root->left=root->right;
				root->right=t;
				if(root->left)
					s.push(root->left);
				if(root->right)
					s.push(root->right);
			}
			return root;
		}

		vector<int> Ancestors(node* root,int data){
			stack<node*> s;
			unordered_map<int,int> v;
			vector<int> k;
			if(root==nullptr)
				return k;
			s.push(root);
			v[root->data]=-1;
			while(!s.empty()){
				root=s.top();
				s.pop();
				if(root->left){
					v[root->left->data]=root->data;
					s.push(root->left);
				}
				if(root->right){
					v[root->right->data]=root->data;
					s.push(root->right);
				}
			}
			while(v[data]!=-1){
				k.push_back(v[data]);
				data=v[data];
			}
			return k;
		}

		bool EqualTree(node* a,node *b){
			stack<pair<node*,node*>> s;
			if(a==nullptr && b==nullptr)
				return 1;
			if(a==nullptr || b==nullptr)
				return 0;
			s.push({a,b});
			while(!s.empty()){
				a=s.top().first;
				b=s.top().second;
				s.pop();
				if(a->data!=b->data)
					return 0;
				if(a->left && b->left)
					s.push({a->left,b->left});
				else if(a->left || b->left)
					return 0;
				if(a->right && b->right)
					s.push({a->right,b->right});
				else if(a->right || b->right)
					return 0;
			}
			return 1;
		}

		vector<int> InOrder(node *root){
			stack<node*> s;
			vector<int> v;
			while(!s.empty() || root!=nullptr)
			{
				if(root!=nullptr){
					s.push(root);
					root=root->left;
				}
				else {
					root=s.top();
					s.pop();
					v.push_back(root->data);
					root=root->right;
				}
			}
			return v;
		}

		vector<int> PreOrder(node * root){
			stack<node*> s;
			vector<int> v;
			while(!s.empty() || root!=nullptr){
				if(root!=nullptr){
					s.push(root);
					v.push_back(root->data);
					root=root->left;
				}
				else {
					root=s.top();
					s.pop();
					root=root->right;
				}
			}
			return v;
		}

		vector<int> PostOrder(node *root){
			stack<node*> s;
			vector<int> v;
			while(!s.empty() || root!=nullptr){
				if(root!=nullptr){
					s.push(root);
					root=root->left;
				}
				else {
					root=s.top();
					s.pop();
					root=root->right;

				}
			}
			return v;
		}

		vector<int> InbetweenLevel(node* root,int start,int end){
			queue<pair<node*,int>> q;
			vector<int> v;
			if(!root)
				return v;
			q.push({root,1});
			while(!q.empty()){
				root=q.front().first;
				int l=q.front().second;
				q.pop();
				if(l>=start && l<=end)
					v.push_back(root->data);
				if(root->left)
					q.push({root->left,l+1});
				if(root->right)
					q.push({root->right,l+1});
			}
		}
};
