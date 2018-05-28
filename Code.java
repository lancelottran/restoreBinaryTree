//
// Definition for binary tree:
// class Tree<T> {
//   Tree(T x) {
//     value = x;
//   }
//   T value;
//   Tree<T> left;
//   Tree<T> right;
// }

Tree<Integer> restoreBinaryTree(int[] inorder, int[] preorder) { 
    return restoreBinaryTree(0, 0 , inorder.length-1, inorder, preorder);
}

Tree<Integer> restoreBinaryTree(int inStart, int preStart, int inEnd, int[] inorder, int[] preorder){   
    if(preStart > preorder.length || inStart > inEnd)
        return null;
    
    Tree<Integer> root = new Tree<Integer>(preorder[preStart]);
    int inIndex = 0;
    
    for(int i = inStart; i <= inEnd; i++){
        if(inorder[i] == root.value)
            inIndex = i;
    }
    
    root.left = restoreBinaryTree(inStart, preStart+1, inIndex-1, inorder, preorder);
    root.right  = restoreBinaryTree(inIndex + 1, preStart + inIndex - inStart + 1, inEnd, inorder, preorder);
    
    return root;
}
