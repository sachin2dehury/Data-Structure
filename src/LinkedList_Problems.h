//============================================================================
// Name        : Array Problems.cpp
// Author      : Sachin Dehury
// Version     : Interview Problems
// Copyright   : Your copyright notice
// Description : Array Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

struct node{
	public:
		int data;
		node* next;
		node* prev;
		node(int x){
			data=x;
			next=nullptr;
			prev=nullptr;
		}
		void push(node* root,int x){
			while(root->next){
				root=root->next;
			}
			root->next=new node(x);
		}
		void PrintNext(node* root){
			node* h=root;
			while(root){
				cout<<root->data<<' ';
				root=root->next;
				if(root==h)
					break;
			}
		}
		void PrintPrev(node* root){
			node* h=root;
			while(root){
				cout<<root->data<<' ';
				root=root->prev;
				if(root==h)
					break;
			}
		}
};

int NthNodeFromEnd(node* root,int n){
	int c=0;
	node* t=root;
	while(root){
		root=root->next;
		c++;
	}
	root=t;
	for(int i=0;i<c-n;i++){
		root=root->next;
	}
	return root->data;
}

bool isPalindrome(node* root){
	string v;
	while(root){
		v.push_back(root->data);
		root=root->next;
	}
	int j=v.length()-1;
	for(int i=0;i<j;i++){
		if(v[i]!=v[j-i])
			return 0;
	}
	return 1;
}

node* ReverseLinkedList(node* root){
	node* p=nullptr;
	node* t=nullptr;
	while(root){
		t=root->next;
		root->next=p;
		p=root;
		root=t;
	}
	return p;
}

node* GroupReverseLinkedList(node* root,int k){
	node* p=nullptr;
	node* t=nullptr;
	node* h=root;
	int c=k;
	while(root && c--){
		t=root->next;
		root->next=p;
		p=root;
		root=t;
	}
	if(root)
		h->next=GroupReverseLinkedList(root, k);
	return p;
}

bool LoopDetection(node* root){
	node* t=root;
	while(t && t->next){
		root=root->next;
		t=root->next;
		if(t==root)
			return 1;
	}
	return 0;
}

int LoopLength(node* root){
	node* t=root;
	int l=1;
	while(t && t->next){
		root=root->next;
		t=root->next;
		if(t==root)
			break;
	}
	root=t;
	while(root){
		root=root->next;
		l++;
		if(t==root)
			return l;
	}
	return 0;
}

void DeleteLinkedList(node* &root){
	node* p=nullptr;
	while(root){
		p=root;
		root=root->next;
		delete(p);
	}
}

void RemoveDuplicates(node* root){
	node* p=nullptr;
	while(root){
		p=root->next;
		while(p && root->data==p->data){
			root->next=p->next;
			delete(p);
			p=root->next;
		}
		root=root->next;
	}
}

void RemoveDuplicateUnsorted(node* root){

}

node* MoveLasttoFirst(node* &root){
	node *h=root;
	node *p=nullptr;
	while(root->next){
		p=root;
		root=root->next;
	}
	root->next=h;
	p->next=nullptr;
	return root;
}

node* Add(node* &root){
	stack<node*> s;
	node* h=root;
	while(root->next){
		s.push(root);
		root=root->next;
	}
	while(root->data+1==10 && !s.empty()){
		root->data=0;
		root=s.top();
		s.pop();
	}
	if(s.empty()){
		node* p=new node(1);
		p->next=root;
		root->data=0;
		root=p;
	} else {
		root->data++;
		root=h;
	}
	return root;
}

vector<int> Intersection(node* a,node* b){
	unordered_set<int> s;
	vector<int> v;
	while(a){
		s.insert(a->data);
		a=a->next;
	}
	while(b){
		if(s.find(b->data)!=s.end())
			v.push_back(b->data);
		b=b->next;
	}
	for(int i : v)
		cout<<i<<' ';
	return v;
}

int MiddleElement(node* root){
	node* t=root->next;
	while(t && t->next){
		root=root->next;
		t=t->next->next;
	}
	return root->data;
}

bool isCircularLinkedList(node* root){
	node* h=root;
	while(root){
		root=root->next;
		if(root==h)
			return 1;
	}
	return 0;
}

int CountNodeCircularLinkedList(node* root){
	node* h=root;
	int c=0;
	while(root){
		c++;
		root=root->next;
		if(root==h)
			return c;
	}
	return 0;
}

void ConvertToCircularLinkedList(node* root){
	node* h=root;
	while(root->next){
		root=root->next;
	}
	root->next=h;
}

node* DeleteNodeCircularLinkedList(node* &root,int x){
	node* h=root;
	node* p=nullptr;
	if(root->data==x){
		root=root->next;
		delete(h);
		node* p=root;
		while(root->next){
			root=root->next;
			if(h==root->next){
				root->next=p;
				return root=p;
			}
		}
	}
	while(root->next){
		if(root->data==x)
			break;
		p=root;
		root=root->next;
		if(h==root)
			return root=h;
	}
	if(root->data==x){
		p->next=root->next;
		delete(root);
	}
	return root=h;
}

void SwapFirstAndLast(node* root){
	node* h=root;
	while(root->next){
		root=root->next;
		if(h==root->next){
			break;
		}
	}
	int t=root->data;
	root->data=h->data;
	h->data=t;
}

pair<node*,node*> SplitCircularLinkedList(node* root){
	node* h=root;
	int n=0;
	while(root){
		n++;
		root=root->next;
		if(root==h)
			break;
	}
	root=h;
	for(int i=1;i<n/2;i++){
		root=root->next;
	}
	node* p=root->next;
	root->next=h;
	root=p;
	while(root){
		root=root->next;
		if(root->next==h)
			break;
	}
	root->next=p;
	return {h,p};
}

pair<node*,node*> ConvertToDoublyLinkedList(node* root){
	node* t=nullptr;
	node* h=root;
	while(root){
		root->prev=t;
		t=root;
		root=root->next;
	}
	return {h,t};
}

pair<node*,node*> ReverseDoublyLinkedList(node* &h,node* &t){
	node* p=h;
	h=t;
	t=p;
	return {h,t};
}

vector<pair<int,int>> SumPair(node* h,node* t,int s){
	vector<pair<int,int>> v;
	while(h){
		node* p=h->next;
		while(p){
			if(h->data+p->data==s)
				v.push_back({h->data,p->data});
			p=p->next;
		}
		h=h->next;
	}
	for(auto i : v)
		cout<<i.first<<' '<<i.second<<'\n';
	return v;
}

int CountTriplets(node* h,node *t,int s){
	int k=0;
	while(h){
		node* p=h->next;
		node* q=t;
		while(p && q && p!=q){
			if(p->data+q->data+h->data==s){
				cout<<p->data<<' '<<q->data<<' '<<h->data<<'\n';
				k++;
			}
			p=p->next;
			q=q->prev;
		}
		h=h->next;
	}
	return k;
}

pair<node*,node*> RotateDoublyLinkedList(node* &h,node* &t,int k){
	node *p=h;
	while(h && k--){
		h=h->next;
	}
	node *q=h;
	t=q->prev;
	t->next=nullptr;
	q->prev=nullptr;
	while(h->next){
		h=h->next;
	}
	h->next=p;
	p->prev=h;
	return {h=q,t};
}

pair<node*,node*> GroupRotateDoublyLinkedList(node* &h,node* &t,int k){
	//todo();
}

///Problems Left

//int main(int argc, char **argv) {
//	node *root=new node(1);
//	root->push(root, 2);
//	root->push(root, 3);
//	root->push(root, 4);
//	root->push(root, 5);
//	root->push(root, 6);
//	root->PrintNext(root);
//	cout<<endl;
//	auto k=ConvertToDoublyLinkedList(root);
//	RotateDoublyLinkedList(k.first, k.second, 2);
//	root->PrintNext(k.first);
//	cout<<endl;
//	root->PrintPrev(k.second);
//	cout<<endl;
//	return 0;
//}

