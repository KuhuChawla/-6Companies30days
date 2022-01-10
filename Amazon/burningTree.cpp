class Solution {
  public:
  int time = INT_MIN;
  void burnTree(Node *root,Node* blockNode, int time1){
      if(root==NULL || root == blockNode ){
          return;
      }
      time = max(time,time1);
      burnTree(root->left,blockNode,time1+1);
      burnTree(root->right,blockNode,time1+1);
  }
int sol(Node* root,int target){
    if(root==NULL){
        return -1;
    }
    if(root->data==target){
            burnTree(root,NULL,0);
            return 1;
        }
        int leftTime = sol(root->left,target);
        if(leftTime!=-1){
            burnTree(root,root->left,leftTime);
            return leftTime+1;
        }
        int rightTime = sol(root->right,target);
        if(rightTime!=-1){
            burnTree(root,root->right,rightTime);
            return rightTime +1;
        }
        return -1;
}
    int minTime(Node* root, int target) 
    {
        sol(root,target);
        return time;
    }
};