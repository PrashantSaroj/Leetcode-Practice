class Solution873 {
    fun lenLongestFibSubseq(arr: IntArray): Int {
        val numSet = arr.toSet()
        var maxLen = 0
        val arSize = arr.size
        for (i in 0 until arSize) {
            for (j in i + 1 until arSize) {
                var len = 2
                var prev = arr[i]
                var curr = arr[j]
                while (numSet.contains(prev + curr)) {
                    len++
                    val tmp = curr
                    curr = curr + prev
                    prev = tmp
                }
                maxLen = maxOf(len, maxLen)
            }
        }
        return maxLen
    }
}

fun main() {
    val testCases = listOf(
        intArrayOf(1, 2, 3, 4, 5, 6, 7, 8),
        intArrayOf(1, 3, 7, 11, 12, 14, 18),
    )

    testCases.forEach {
        println(Solution873().lenLongestFibSubseq(it))
    }
}
