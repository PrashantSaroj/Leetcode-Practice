import kotlin.math.max


class Solution {
    fun maxScoreSightseeingPair(values: IntArray): Int {
        var res = values[values.size - 1] + values[values.size - 2] - 1
        var cur = values[values.size - 1]
        for (i in values.size - 2 downTo 0) {
            cur = max(cur, values[i + 1]) - 1
            res = max(res, values[i] + cur)
        }
        return res
    }
}

fun main() {
    val values1 = intArrayOf(8, 1, 5, 2, 6)
    val values2 = intArrayOf(1, 2)
    val sol = Solution()
    println(sol.maxScoreSightseeingPair(values1))
    println(sol.maxScoreSightseeingPair(values2))
}