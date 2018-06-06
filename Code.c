// Definition for arrays:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//
// Definition for binary tree:
// typedef struct tree_##name {
//   type value;
//   struct tree_##name *left;
//   struct tree_##name *right;
// } tree_##name;
//
// tree_##name *alloc_tree_##name(type v) {
//   tree_##name *t = calloc(1, sizeof(tree_##name));
//   t->value = v;
//   return t;
// }
tree_integer * restoreBinary(int inStart, int preStart, int inEnd, arr_integer inorder, arr_integer preorder){
    if(preStart > preorder.size || inStart > inEnd)
        return NULL;
    
    tree_integer * root = alloc_tree_integer(preorder.arr[preStart]);
    int inIndex = 0;
    
    for(int i = inStart; i <= inEnd; i++){
        if(inorder.arr[i] == root->value)
            inIndex = i;
    }
    
    root->left = restoreBinary(inStart, preStart+1, inIndex-1, inorder, preorder);
    root->right = restoreBinary(inIndex+1, preStart + inIndex - inStart + 1, inEnd, inorder, preorder);
    
    return root;
}

tree_integer * restoreBinaryTree(arr_integer inorder, arr_integer preorder) {
    return restoreBinary(0,0, inorder.size -1, inorder, preorder);
}
