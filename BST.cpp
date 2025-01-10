#include "bits/stdc++.h"
using namespace std;
struct BinarySearchTree{
	int data;
	struct BinarySearchTree* left;
	struct BinarySearchTree* right;
	BinarySearchTree(int d){
		data =d;
		left = nullptr;
		right = nullptr;
		}
};
void InsertintotheTree(BinarySearchTree* Node,vector<int>&arr){
	for(int i =1;i<arr.size();i++){	
		while(true){
			BinarySearchTree* curr = Node;
			if(arr[i]<=curr->data){
				if(curr->left == nullptr){
					curr->left = new BinarySearchTree(arr[i]); 
					break;
				}			
				else{
					curr = curr->left;
				}
			
			}
			else if(arr[i]>=curr->data){
				if(curr->right == nullptr){
					curr->right = new BinarySearchTree(arr[i]);
					break; 	
				}	
					
				else{
					 curr = curr->right;
				}
			}
			
		
		}
	}
}

int SearchinTheBinaryTree(BinarySearchTree* Node, int key) {
 if (Node == nullptr) return 0; 
if (Node->data == key) return 1; 
 if (key < Node->data) return SearchinTheBinaryTree(Node->left, key); 
 return SearchinTheBinaryTree(Node->right, key); 
 }
void displayTheBinaryTree(BinarySearchTree* Node){
	// preorder Traversal
	BinarySearchTree* temp;
	if(Node == nullptr){
		cout<<"NOT FOUND"<<endl;
	}
	cout<<temp->data<<" ";
	displayTheBinaryTree(Node->left);
	displayTheBinaryTree(Node->right);
}

int main(){
	BinarySearchTree* Node;
	cout<<"Enter the Number of elements in the tree:"<<endl;
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int  i =0;i<n;i++) cin>>arr[i];
	InsertintotheTree(Node,arr);
	displayTheBinaryTree(Node);
}
