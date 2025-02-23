class Solution105 {
    var preIndex = 0
    lateinit var iOrder: IntArray
    lateinit var pOrder: IntArray
    val iOrderIndices = mutableMapOf<Int, Int>()

    private fun helper(l: Int, r: Int): TreeNode? {
        if (l > r) {
            return null
        }

        val cVal = pOrder[preIndex++]
        val root = TreeNode(cVal)
        val rootIndex = iOrderIndices[cVal]!!
        root.left = helper(l, rootIndex - 1)
        root.right = helper(rootIndex + 1, r)
        return root
    }

    fun buildTree(preorder: IntArray, inorder: IntArray): TreeNode? {
        pOrder = preorder
        iOrder = inorder
        iOrder.forEachIndexed { i, ele ->
            iOrderIndices[ele] = i
        }
        return helper(0, preorder.size - 1)
    }
}

fun main() {
    val p = intArrayOf(3, 9, 20, 15, 7)
    val i = intArrayOf(9, 3, 15, 20, 7)
    inOrder(Solution105().buildTree(p, i))
}
