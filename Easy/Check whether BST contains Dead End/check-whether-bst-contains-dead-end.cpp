//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
  void inorder(Node *root,unordered_map<int,int>&m)
  {
      if(root==NULL)
      return;
      inorder(root->left,m);
      m[root->data]++;
      inorder(root->right,m);
  }
  void inorder2(Node *root,unordered_map<int,int>&m,bool &found)
  {
      if(root==NULL)
      return;
      inorder2(root->left,m,found);
      if(root->left==NULL && root->right==NULL)
      {
          int val1=root->data-1;
          int val2=root->data+1;
          if(m.find(val1)!=m.end() && m.find(val2)!=m.end())
          found=true;
      }
      inorder2(root->right,m,found);
  }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        unordered_map<int,int>m;
        m[0]=1;
        inorder(root,m);
        bool found=false;
        inorder2(root,m,found);
        return found;
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends