class Solution106 {
    var poIndex = 0
    lateinit var inOrder: IntArray
    lateinit var poOrder: IntArray
    val iOrderIndices = mutableMapOf<Int, Int>()

    private fun helper(l: Int, r: Int): TreeNode? {
        if (l > r) {
            return null
        }

        val cVal = poOrder[poIndex--]
        val root = TreeNode(cVal)
        val rootIndex = iOrderIndices[cVal]!!
        root.right = helper(rootIndex + 1, r)
        root.left = helper(l, rootIndex - 1)

        return root
    }

    fun buildTree(inorder: IntArray, postorder: IntArray): TreeNode? {
        poOrder = postorder
        inOrder = inorder
        inOrder.forEachIndexed { i, ele ->
            iOrderIndices[ele] = i
        }
        poIndex = inorder.size - 1
        return helper(0, postorder.size - 1)
    }
}

fun main() {
    val p = intArrayOf(9,15,7,20,3)
    val i = intArrayOf(9, 3, 15, 20, 7)
    inOrder(Solution106().buildTree(i, p))
}