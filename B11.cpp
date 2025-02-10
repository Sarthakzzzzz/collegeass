#include "bits/stdc++.h"
using namespace std;
struct BST{
	BST* left;
	BST* right;
	string data;
	BST(string val) : data(val),left(nullptr),right(nullptr){}
};
BST* insertBST(BST* node,string val){
	if(node == nullptr){
		return new BST(val);
	}
	if(val<node->data){
		node->left = insertBST(node->left,val);
	}
	else{
		node->right = insertBST(node->right,val);
	}
	return node;
}
BST* dictToBST(const std:: map<string,int>&freq){
		BST* head = nullptr;
		for(const auto &pair: freq){
			head = insertBST(head,pair.first);
		}
		return head;
}
void printBST(BST *node){
	if (node == nullptr) return;
    std::queue<BST*> q;
    q.push(node);
    while(!q.empty()){
    	BST* head = q.front();
    	q.pop();
    	cout<<head->data<<" ";
    	if(head->left!=nullptr){
    		q.push(head->left);
    	}
    	if(head->right!=nullptr){
    		q.push(head->right);
    	}
    }
}
int main() {
   map<string, int> dict = {{"Aditya", 1}, {"kutra", 1}, {"aahe", 1}, {"far", 1}, {"motha", 1}};
   BST* bstRoot = dictToBST(dict);
    printBST(bstRoot);
    return 0;
}
