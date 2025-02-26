import kotlin.math.abs

class Solution1749 {
    fun maxAbsoluteSum(nums: IntArray): Int {
        val runningSum = nums.runningFold(0) { sum, num -> num + sum }
        val runningMax = runningSum.runningReduce { acc, num -> maxOf(acc, num) }
        val runningMin = runningSum.runningReduce { acc, num -> minOf(acc, num) }

        var maxAbsSum = 0
        for (i in 1..nums.size) {
            val curMax = if (runningSum[i] > 0) {
                runningSum[i] - runningMin[i-1]
            } else {
                runningSum[i] - runningMax[i-1]
            }
            maxAbsSum = maxOf(maxAbsSum, abs(curMax))
        }
        return maxAbsSum
    }
}

fun main() {
    val testCases = listOf(
        intArrayOf(1,-3,2,3,-4),
        intArrayOf(2,-5,1,-4,3,-2),
    )

    testCases.forEach {
        println(Solution1749().maxAbsoluteSum(it))
    }
}
