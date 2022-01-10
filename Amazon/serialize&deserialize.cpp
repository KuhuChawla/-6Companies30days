class Solution
{
    public:
    vector<int> sol;
    void helperFunc(Node* root){
        if(root!=NULL){
            helperFunc(root->left);
            sol.push_back(root->data);
            helperFunc(root->right);
        }
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        
        helperFunc(root);
        return sol;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       struct Node *ans = new Node(0);
       Node *temp = ans;
       int n = A.size();
       for(int i=0;i<n;i++){
           temp->right = new Node(A[i]);
           temp = temp->right;
       }
       return ans->right;
    }

};