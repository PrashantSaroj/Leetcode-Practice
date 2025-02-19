import kotlin.math.max


class Solution1937 {
    private fun leftSideMax(points: LongArray, n: Int): LongArray {
        val leftMax = LongArray(n)
        leftMax[0] = points[0]
        for (i in 1 until n) {
            leftMax[i] = max(points[i], leftMax[i - 1] - 1)
        }
        return leftMax
    }

    private fun rightSideMax(points: LongArray, n: Int): LongArray {
        val rightMax = LongArray(n)
        rightMax[n - 1] = points[n - 1]
        for (i in n - 2 downTo 0) {
            rightMax[i] = max(points[i], rightMax[i + 1] - 1)
        }
        return rightMax
    }

    fun maxPoints(points: Array<IntArray>): Long {
        val m = points.size
        val n = points[0].size
        val dp = Array(m) { LongArray(n) }
        // base case - last row same as points
        for (i in 0 until n) {
            dp[m - 1][i] = points[m - 1][i].toLong()
        }

        for (i in m - 2 downTo 0) {
            val leftMax = leftSideMax(dp[i + 1], n)
            val rightMax = rightSideMax(dp[i + 1], n)
            for (j in 0 until n) {
                dp[i][j] = points[i][j].toLong() + max(leftMax[j], rightMax[j])
            }
        }

        return dp[0].max()
    }
}

fun main() {
    val points1 = arrayOf(
        intArrayOf(1, 2, 3),
        intArrayOf(1, 5, 1),
        intArrayOf(3, 1, 1),
    )
    val points2 = arrayOf(
        intArrayOf(1, 5),
        intArrayOf(2, 3),
        intArrayOf(4, 2),
    )
    val sol = Solution1937()
    println(sol.maxPoints(points1))
    println(sol.maxPoints(points2))
}