class Solution1524 {
    fun numOfSubarrays(arr: IntArray): Int {
        var res = 0
        val runningSum = arr.runningFold(0) { sum, num -> sum + num }
        val oddSums = runningSum.runningReduce { count, num -> if (num and 1 == 0) count else count + 1 }

        for (i in 1..arr.size) {
            res += if (runningSum[i] and 1 == 0) oddSums[i - 1] else i - oddSums[i - 1]
            res = res % BIG_MOD
        }
        return res
    }

    companion object {
        private const val BIG_MOD = 1000000007
    }
}

fun main() {
    val testCases = listOf(
        intArrayOf(1, 3, 5),
        intArrayOf(2, 4, 6),
        intArrayOf(1, 2, 3, 4, 5, 6, 7),
    )

    testCases.forEach {
        println(Solution1524().numOfSubarrays(it))
    }
}
