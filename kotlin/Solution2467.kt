class Solution2467 {
    private var bob = 0

    // store node -> time map
    private val bobPath = mutableMapOf<Int, Int>()
    private val cumRewd = mutableMapOf<Int, Int>()
    private lateinit var adjList: Array<MutableList<Int>>

    private fun onPath(node: Int, parent: Int): Int? {
        if (node == bob) {
            bobPath[bob] = 0
            return 0
        }

        adjList[node].filter { it != parent }.forEach { neighbor ->
            val neighborT = onPath(neighbor, node)
            if (neighborT != null) {
                bobPath[node] = neighborT + 1
                return neighborT + 1
            }
        }
        return null
    }

    private fun calcReward(parentReward: Int, node: Int, aliceTime: Int, amount: Int) {
        val bobTime = bobPath[node]
        if (bobTime == null || bobTime > aliceTime) {
            cumRewd[node] = amount + parentReward
        } else {
            if (bobTime == aliceTime) {
                cumRewd[node] = amount / 2 + parentReward
            } else {
                cumRewd[node] = parentReward
            }
        }
    }


    fun mostProfitablePath(edges: Array<IntArray>, bob: Int, amount: IntArray): Int {
        this.bob = bob
        adjList = Array(amount.size) { mutableListOf() }
        edges.forEach {
            adjList[it[0]].add(it[1])
            adjList[it[1]].add(it[0])
        }
        onPath(0, -1)

        var aliceTime = 0
        calcReward(0, 0, 0, amount[0])
        val bfsQ = ArrayDeque<Int>(listOf(0))
        val visited = BooleanArray(amount.size) { false }
        visited[0] = true

        while (bfsQ.isNotEmpty()) {
            val curLevelSize = bfsQ.size
            repeat(curLevelSize) {
                val node = bfsQ.removeFirst()
                adjList[node].filter { !visited[it] }.forEach {
                    calcReward(cumRewd[node]!!, it, aliceTime + 1, amount[it])
                    bfsQ.addLast(it)
                    visited[it] = true
                }
            }
            aliceTime++
        }
        var maxLeafProfit = Int.MIN_VALUE
        for (node in 0 until amount.size) {
            if (adjList[node].size == 1) {
                maxLeafProfit = maxOf(maxLeafProfit, cumRewd[node]!!)
            }
        }
        return maxLeafProfit
    }
}

data class TestCase(
    val bob: Int,
    val amount: IntArray,
    val edges: Array<IntArray>,
)

fun main() {
    val testCases = listOf(
        TestCase(1, intArrayOf(-7280, 2350), arrayOf(intArrayOf(0, 1))),
        TestCase(
            3,
            intArrayOf(-2, 4, 2, -4, 6),
            arrayOf(intArrayOf(0, 1), intArrayOf(1, 2), intArrayOf(1, 3), intArrayOf(3, 4))
        ),
    )
    testCases.forEach {
        println(Solution2467().mostProfitablePath(it.edges, it.bob, it.amount))
    }
}
