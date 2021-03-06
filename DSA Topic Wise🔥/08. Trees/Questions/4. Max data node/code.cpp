#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Ques - Find the max data node in a tree.

template <typename T>
class TreeNode{
public:
  T data;
  vector<TreeNode<T> *> children;

  TreeNode(T data){
    this->data = data;
  }

  ~TreeNode()  {
    for (int i = 0; i < children.size(); i++)
      delete children[i];
  }
};

TreeNode<int>* takeInputLevelWise(){
  int rootData;
  cout << "Enter Root Data:\n";
  cin >> rootData;

  TreeNode<int> * root = new TreeNode<int>(rootData);

  queue<TreeNode<int>*> pendingNode;
  pendingNode.push(root);

  while(!pendingNode.empty()){
    TreeNode<int> *front = pendingNode.front();
    pendingNode.pop();

    int numChild;
    cout << "Enter number of children of " << front -> data << "\n";
    cin >> numChild;

    for(int i = 0; i < numChild; i++){
      int childData;

      cout << "Enter " << i << "th child of " << front -> data << "\n";
      cin >> childData;

      TreeNode<int>* child = new TreeNode<int>(childData);
      front -> children.push_back(child);

      pendingNode.push(child);
    }

  }

  return root;
}

void printNodeLevelWise(TreeNode<int>* root){

  queue<TreeNode<int> *> pendingNode;
  pendingNode.push(root);

  while(!pendingNode.empty()){
    TreeNode<int>* front = pendingNode.front();
    pendingNode.pop();
    
    cout << front -> data << ":";

    for(int i = 0; i < front -> children.size(); i++){
      pendingNode.push(front -> children[i]);
      
      if(i == (front -> children.size() - 1))
        cout << front -> children[i] -> data;
      else
        cout << front -> children[i] -> data << ",";
      
    }
    cout << "\n"; 
  }

}

TreeNode<int>* maxDataNode(TreeNode<int>* root){

  TreeNode<int> *max=new TreeNode<int>(root->data);

  for(int i = 0; i <  root -> children.size(); i++){
    TreeNode<int> *child = maxDataNode(root -> children[i]);
    
    if((max -> data) < (child -> data))
      max = child;
  }

  return max;
}

int main(){

  TreeNode<int> *root = takeInputLevelWise();

  printNodeLevelWise(root);

  cout << "Max Data Node is " << maxDataNode(root) -> data;
  
  delete root;

  return 0;
}