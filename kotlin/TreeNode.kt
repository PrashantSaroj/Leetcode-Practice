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
