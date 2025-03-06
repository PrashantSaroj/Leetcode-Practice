class Solution2965 {
    fun findMissingAndRepeatedValues(grid: Array<IntArray>): IntArray {
        val n = (grid.size * grid.size).toLong()
        val (gridSum, nSum) = grid.sumOf { it.sum().toLong() } to (n * (n + 1)) / 2L
        val (sqreSum, nSqSum) = grid.sumOf { it.sumOf { (it * it).toLong() } } to (n * (n + 1) * (2 * n + 1)) / 6L
        val diff = nSum - gridSum
        val sqDiff = nSqSum - sqreSum
        val a = ((diff * diff + sqDiff) / diff) shr 1
        val b = ((sqDiff - diff * diff) / diff) shr 1
        return intArrayOf(b.toInt(), a.toInt())
    }
}

fun main() {
    val testCases = listOf(
        arrayOf(intArrayOf(1, 3), intArrayOf(2, 2)),
        arrayOf(intArrayOf(9, 1, 7), intArrayOf(8, 9, 2), intArrayOf(3, 4, 6))
    )
    testCases.forEach {
        println(Solution2965().findMissingAndRepeatedValues(it).contentToString())
    }
}
