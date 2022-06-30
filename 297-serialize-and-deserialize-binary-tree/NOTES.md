to serialize i will do preorder traversal of tree and if there is null i will add null and will return;
eg preorder traversal is 1,2,N,N,3,4,N,N,5,N,N (N represent NULL ans , to differentiate between different nodes)
Now to deseralize i add these string into queue
q front will be root then i  recursiverly call root->left and root->right // basically doing preorder only
We have do preorder because it first give us root otherwise other traversal give root->left of root->right with there help we can not create tree.