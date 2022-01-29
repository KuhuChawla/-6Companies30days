int sum(Node* node){
      if(node == NULL){
          return 0;
      }
      int left = sum(node->left);
      int right = sum(node->right);
      int temp = node->data;
      if(left == 0 &&right == 0){
          node->data = 0;
          return temp;
      }
      else{
          node->data = left + right;
          return temp + left + right;
      }
  }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        sum(node);
    }