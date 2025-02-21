class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class FindElements(root: TreeNode?) {
    private val valuesSet = mutableSetOf<Int>()

    init {
        root?.let {
            it.`val` = 0
            val dfsStack = ArrayDeque(listOf(it))
            while (dfsStack.isNotEmpty()) {
                val curr = dfsStack.removeLast()
                curr.left?.let { child ->
                    child.`val` = 2*curr.`val` + 1
                    dfsStack.addLast(child)
                }
                curr.right?.let { child ->
                    child.`val` = 2*curr.`val` + 2
                    dfsStack.addLast(child)
                }
                println(curr.`val`)
                valuesSet.add(curr.`val`)
            }

        }
    }

    fun find(target: Int): Boolean {
        return valuesSet.contains(target)
    }
}

fun main() {
    val root = TreeNode(-1)
    root.right = TreeNode(-1)
    val obj = FindElements(root)
    println(obj.find(1))
    println(obj.find(2))
}
