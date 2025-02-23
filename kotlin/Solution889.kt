class Solution889 {
    fun constructFromPrePost(preorder: IntArray, postorder: IntArray): TreeNode? {
        val totalNodes = preorder.size

        val lChild = mutableMapOf<Int, Int>()
        val rChild = mutableMapOf<Int, Int>()
        // fill potential children
        for (i in 0 until totalNodes - 1) {
            lChild[preorder[i]] = preorder[i + 1]
            rChild[postorder[totalNodes - 1 - i]] = postorder[totalNodes - 2 - i]
        }

        val root = TreeNode(preorder[0])
        val usedChild = mutableSetOf(preorder[0])
        val nodesQueue = ArrayDeque<TreeNode>(listOf(root))
        while (nodesQueue.isNotEmpty()) {
            val curr = nodesQueue.removeFirst()
            // add potential left child
            val lVal = lChild[curr.`val`]
            if (lVal != null && !usedChild.contains(lVal)) {
                curr.left = TreeNode(lVal).also { nodesQueue.addLast(it) }
                usedChild.add(lVal)
            }
            // add potential right child
            val rVal = rChild[curr.`val`]
            if (rVal != null && !usedChild.contains(rVal)) {
                curr.right = TreeNode(rVal).also { nodesQueue.addLast(it) }
                usedChild.add(rVal)
            }
        }
        return root
    }
}

fun main() {
    val testCases = listOf(
        intArrayOf(1, 2, 4, 5, 3, 6, 7) to intArrayOf(4, 5, 2, 6, 7, 3, 1),
        intArrayOf(1) to intArrayOf(1),
    )

    testCases.forEach {
        inOrder(Solution889().constructFromPrePost(it.first, it.second))
        print('\n')
    }
}
