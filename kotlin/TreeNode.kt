class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

fun preOrder(root: TreeNode?) {
    root?.let {
        print("${root.`val`} ")
        preOrder(it.left)
        preOrder(it.right)
    }
}

fun inOrder(root: TreeNode?) {
    root?.let {
        inOrder(it.left)
        print("${root.`val`} ")
        inOrder(it.right)
    }
}
