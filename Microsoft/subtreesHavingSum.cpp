int numberOfCount(Node*root, int X, int &count){
    if(root == NULL){
        return 0;
    }
    int left = numberOfCount(root->left,X,count);
    int right = numberOfCount(root->right,X,count);
    int sum = root->data + left + right;
    if(sum == X){
        count++;
    }
    return sum;
}

//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
	int count = 0;
	numberOfCount(root,X,count);
	return count;
}