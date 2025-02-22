class Solution1028 {
    private fun parseTraversal(traversal: String): List<String> {
        val parsed = mutableListOf<String>()
        var isCurD = false
        var l = 0
        for (i in 1 until traversal.length) {
            if (traversal[i] == '-' && !isCurD) {
                parsed.add(traversal.substring(l, i))
                isCurD = true
                l = i
            }
            if (traversal[i] != '-' && isCurD) {
                parsed.add(traversal.substring(l, i))
                isCurD = false
                l = i
            }
        }
        parsed.add(traversal.substring(l, traversal.length))
        return parsed
    }

    fun recoverFromPreorder(traversal: String): TreeNode? {
        val parsedIn = parseTraversal(traversal)
        val root = TreeNode(parsedIn[0].toInt())
        val dfsStack = ArrayDeque<Pair<TreeNode, Int>>(listOf(root to 0))

        var currDepth = 0
        for (i in 1 until parsedIn.size) {
            if (parsedIn[i][0] == '-') {
                currDepth = parsedIn[i].length
            } else {
                val node = TreeNode(parsedIn[i].toInt())
                var prnt = dfsStack.last()
                while (prnt.second != currDepth - 1) {
                    dfsStack.removeLast()
                    prnt = dfsStack.last()
                }
                // insert in parent (try left first)
                if (prnt.first.left == null) {
                    prnt.first.left = node
                } else {
                    prnt.first.right = node
                    // both child filled, removed from stack
                    dfsStack.removeLast()
                }
                dfsStack.addLast(node to currDepth)
                currDepth = 0
            }
        }
        return root
    }
}

fun main() {
    val testCases = listOf(
        "10-7--8"
//        "1-2--3--4-5--6--7",
//        "1-2--3---4-5--6---7",
//        "1-401--349---90--88",
    )

    testCases.forEach {
        preOrder(Solution1028().recoverFromPreorder(it))
        print('\n')
    }
}
