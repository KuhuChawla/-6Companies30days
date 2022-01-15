 Node * getRoot(Node * n){
        while(n!=NULL){
            if(n->left){
                return n->left;
            }
            if(n->right){
                return n->right;
            }
            n= n->nextRight;
        }
        return n;
    }
    void connect(Node *root)
    {
       if(!root){
           return;
       }
       if(root->left){
           root->left->nextRight = (root->right ? root->right : getRoot(root->nextRight));
       }
       if(root->right){
           root->right->nextRight = getRoot(root->nextRight);
       }
       connect(root->left);
       connect(root->right);
    }    