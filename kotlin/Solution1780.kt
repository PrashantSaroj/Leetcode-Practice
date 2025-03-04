class Solution1780 {
    private val memo = mutableMapOf<Pair<Int, Int>, Boolean>()

    private fun checkHelper(curr: Int, target: Int): Boolean {
        if (curr == target) return true
        if (curr < 0 || curr > target) return false

        val memoKey = Pair(curr, target)
        memo[memoKey]?.let { return it }

        val next = 3 * curr
        memo[memoKey] = checkHelper(next, target - curr) || checkHelper(next, target)
        return memo[memoKey]!!
    }

    fun checkPowersOfThree(n: Int): Boolean {
        return checkHelper(1, n)
    }
}

fun main() {
    val testCases = listOf(12, 91, 21)
    testCases.forEach { println(Solution1780().checkPowersOfThree(it)) }
}
