//============================================================================
// Name        : Lab Problems.cpp
// Author      : Sachin Dehury 117CR0160
// Version     : Lab Problems
// Copyright   : Your copyright notice
// Description : Lab Problems in C++,inc[i][j][istrue]i-style
//============================================================================

#include <iostream>

using namespace std;

class node{
	public:
		int data;//stores data
		node* next;//stores link to next node
		node* prev;//stores link to previous node
		node(int data){//to create a node
			this->data=data;
			next=nullptr;
			prev=nullptr;
		}
};

class DoublyLinkedList{//class containing all DoublyLinkedList methods
	private:
		node* head=nullptr;//stores head of the list
		node* tail=nullptr;//stores tail of the list
	public:
		void insertBegin(){
			int data;//to store insert data
			cout<<"Enter Data to insert: \n";
			cin>>data;
			if(head==nullptr){//if list is empty, insert
				head=new node(data);
				tail=head;
				return;
			}//if list is not empty, insert at head
			node* temp=head;
			head=new node(data);
			head->next=temp;
			temp->prev=head;
		}

		void insertEnd(){
			int data;//to store insert data
			cout<<"Enter Data to insert: \n";
			cin>>data;
			if(head==nullptr){//if list is empty, insert
				tail=new node(data);
				head=tail;
				return;
			}//if list is not empty, insert at tail
			node* temp=tail;
			tail=new node(data);
			tail->prev=temp;
			temp->next=tail;
		}

		void insertAfter(){
			int data;//to store insert data
			int after;//to store the node data after which to be inserted
			cout<<"Enter After Data : \n";
			cin>>after;
			cout<<"Enter Data to insert: \n";
			cin>>data;
			if(head==nullptr){//if list is empty, return
				cout<<"List is Empty!\n";
				return;
			}
			else if(tail->data==after){//if after is present in tail
				insertEnd();//insert at end
				return;
			}
			node* temp=head;//for traversal of list
			while(temp!=nullptr){//when temp is not null
				if(temp->data==after)//if after found, quit the loop
					break;
				temp=temp->next;//else move to next node
			}
			if(temp==nullptr){//if after not found in list
				cout<<after<<"Not Found!\n";
				return;
			}//after found in list
			node* next=temp->next;//next node of temp
			node* current=new node(data);//current node to store new data
			current->next=next;//to insert a node between temp and next node
			current->prev=temp;
			temp->next=current;
			next->prev=current;
		}

		void insertBefore(){
			int data;//to store insert data
			int before;//to store the node data before which to be inserted
			cout<<"Enter After Data : \n";
			cin>>before;
			cout<<"Enter Data to insert: \n";
			cin>>data;
			if(head==nullptr){//if list is empty, return
				cout<<"List is Empty!\n";
				return;
			}
			else if(head->data==before){//if before is present in head
				insertBegin();//insert at start
				return;
			}
			node* temp=head;//for traversal of list
			while(temp!=nullptr){//when temp is not null
				if(temp->data==before)//if before found, quit the loop
					break;
				temp=temp->next;//else move to next node
			}
			if(temp==nullptr){//if before not found in list
				cout<<before<<"Not Found!\n";
				return;
			}//before found in list
			node* last=temp->prev;//previous node of temp
			node* current=new node(data);//current node to store new data
			current->next=temp;//to insert a node between temp and last node
			current->prev=last;
			last->next=current;
			temp->prev=current;
		}

		void deleteBegin(){
			if(head==nullptr){//if list is empty, return
				cout<<"List is Empty!\n";
				return;
			}
			node* temp=head;//to store the head temporarily
			head=temp->next;//moves head to next node
			head->prev=nullptr;//sets previous link to null
			delete(temp);//deletes the temp node
		}

		void deleteEnd(){
			if(head==nullptr){//if list is empty, return
				cout<<"List is Empty!\n";
				return;
			}
			node* temp=tail;//to store the tail temporarily
			tail=temp->prev;//moves tail to previous node
			tail->next=nullptr;//sets next link to null
			delete(temp);//deletes the temp node
		}

		void deleteBefore(){
			int data;//to store the node data before which to be deleted
			cout<<"Enter Data to Delete Before: \n";
			cin>>data;
			if(head==nullptr){//if list is empty, return
				cout<<"List is Empty!\n";
				return;
			}
			else if(head->data==data){//if data found at head
				deleteBegin();//delete at start
				return;
			}
			node* temp=head;//to traverse the list
			while(temp!=nullptr){//when temp is not null
				if(temp->data==data)//if data found, quit the loop
					break;
				temp=temp->next;//else move to next node
			}
			if(temp==nullptr){//if data not found in list
				cout<<data<<"Not Found!\n";
				return;
			}//data found in list
			node* current=temp->prev;//stores node to be deleted
			node* last=current->prev;//stores previous node
			last->next=temp;//sets next link to temp
			temp->prev=last;//sets prev link to last
			delete(current);//deletes the current node
		}

		void deleteAfter(){
			int data;//to store the node data after which to be deleted
			cout<<"Enter Data to Delete After: \n";
			cin>>data;
			if(head==nullptr){//if list is empty, return
				cout<<"List is Empty!\n";
				return;
			}
			else if(tail->data==data){//if data found at tail
				deleteEnd();//delete at tail
				return;
			}
			node* temp=head;//to traverse the list
			while(temp!=nullptr){//when temp is not null
				if(temp->data==data)//if data found, quit the loop
					break;
				temp=temp->next;//else move to next node
			}
			if(temp==nullptr){//if data not found in list
				cout<<data<<"Not Found!\n";
				return;
			}//data found in list
			node* current=temp->next;//stores node to be deleted
			node* next=current->next;//stores next node
			temp->next=next;//sets next link to next
			next->prev=temp;//sets previous link to temp
			delete(current);//deletes the current node
		}

		void deleteNode(){
			int data;//to store the data, to be deleted
			cout<<"Enter Data to Delete: \n";
			cin>>data;
			if(head==nullptr){//if list is empty, return
				cout<<"List is Empty!\n";
				return;
			}
			else if(head->data==data){//if data found at head
				deleteBegin();//delete at start
				return;
			}
			else if(tail->data==data){//if data found at tail
				deleteEnd();//delete at tail
				return;
			}
			node* temp=head;//to traverse the list
			while(temp!=nullptr){//when temp is not null
				if(temp->data==data)//if data found, quit the loop
					break;
				temp=temp->next;//else move to next node
			}
			if(temp==nullptr){//if data not found in list
				cout<<data<<"Not Found!\n";
				return;
			}//data found in list
			node* last=temp->prev;//stores previous node
			node* next=temp->next;//stores next node
			last->next=next;//sets next link to next
			next->prev=last;//sets previous link to last
			delete(temp);//deletes the temp node
		}

		void show(){
			if(head==nullptr){//if list is empty, return
				cout<<"List is Empty!\n";
				return;
			}
			node* temp=head;//to traverse the list
			while(temp!=nullptr){//when temp is not null
				cout<<temp->data<<' ';
				temp=temp->next;//else move to next node
			}
			cout<<endl;
		}

		DoublyLinkedList(){//constructor implements user driven list
			int c;//stores choice
			do{//menu driven
				cout<<"1 Insert at Begin: \n";
				cout<<"2 Insert at End: \n";
				cout<<"3 Insert After data: \n";
				cout<<"4 Insert Before data: \n";
				cout<<"5 Delete at Begin: \n";
				cout<<"6 Delete at End: \n";
				cout<<"7 Delete After data: \n";
				cout<<"8 Delete Before data: \n";
				cout<<"9 Delete Node: \n";
				cout<<"10 Display data: \n";
				cout<<"0 Quit the list\n";
				cout<<"Enter Choice: ";
				cin>>c;
				switch (c) {
					case 1:
						insertBegin();
						break;
					case 2:
						insertEnd();
						break;
					case 3:
						insertAfter();
						break;
					case 4:
						insertBefore();
						break;
					case 5:
						deleteBegin();
						break;
					case 6:
						deleteEnd();
						break;
					case 7:
						deleteAfter();
						break;
					case 8:
						deleteBefore();
						break;
					case 9:
						deleteNode();
						break;
					case 10:
						show();
						break;
					case 0://quits the list
						break;
					default:
						cout<<"Invalid Input\n";
						break;
				}
			}while(c!=0);
		}
};

//int main(int argc, char **argv) {
//	int c;//stores choice
//	do{//menu driven
//		cout<<"1.Create DoublyLinkedList\n";
//		cout<<"0.Quit The Program\n";
//		cout<<"Enter your choice : ";
//		cin>>c;
//		switch (c) {
//			case 1:
//				DoublyLinkedList();//creates instance of DoublyLinkedList
//				break;
//			case 0://quits the program
//				break;
//			default:
//				cout<<"Invalid choice!!\n";
//				break;
//		}
//	} while (c!=0);
//	return 0;
//}

