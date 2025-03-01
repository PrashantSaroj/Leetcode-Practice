class Solution994 {
    private val dir = listOf(0 to 1, 1 to 0, 0 to -1, -1 to 0)

    private fun getFreshNeighbors(grid: Array<IntArray>, rows: Int, cols: Int, i: Int, j: Int): List<Pair<Int, Int>> {
        val neighbors = mutableListOf<Pair<Int, Int>>()
        dir.forEach { (dx, dy) ->
            val cx = dx + i
            val cy = dy + j
            if (cx >= 0 && cx < rows && cy >= 0 && cy < cols && grid[cx][cy] == 1) neighbors.add(cx to cy)
        }
        return neighbors
    }

    private fun getRotten(grid: Array<IntArray>, rows: Int, cols: Int): List<Pair<Int, Int>> {
        val rotten = mutableListOf<Pair<Int, Int>>()
        for (i in 0 until rows) {
            for (j in 0 until cols) {
                if (grid[i][j] == 2) rotten.add(i to j)
            }
        }
        return rotten
    }

    private fun freshRemaining(grid: Array<IntArray>, rows: Int, cols: Int): Boolean {
        for (i in 0 until rows) {
            for (j in 0 until cols) {
                if (grid[i][j] == 1) return true
            }
        }
        return false
    }

    fun orangesRotting(grid: Array<IntArray>): Int {
        val rows = grid.size
        val cols = grid[0].size
        var minutes = -1

        val bfsQ = ArrayDeque<Pair<Int, Int>>(getRotten(grid, rows, cols))
        while (bfsQ.isNotEmpty()) {
            val levelSize = bfsQ.size
            repeat(levelSize) {
                val curr = bfsQ.removeFirst()
                getFreshNeighbors(grid, rows, cols, curr.first, curr.second).forEach {
                    grid[it.first][it.second] = 2
                    bfsQ.addLast(it)
                }
            }
            minutes++
        }

        return if (freshRemaining(grid, rows, cols)) -1 else minutes
    }
}

fun main() {
    val testCases = listOf(
        arrayOf(intArrayOf(2, 1, 1), intArrayOf(1, 1, 0), intArrayOf(0, 1, 1)),
        arrayOf(intArrayOf(2, 1, 1), intArrayOf(0, 1, 1), intArrayOf(1, 0, 1)),
        arrayOf(intArrayOf(0, 2))
    )
    testCases.forEach {
        println(Solution994().orangesRotting(it))
    }
}
