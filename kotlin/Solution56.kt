class Solution56 {
    fun merge(intervals: Array<IntArray>): Array<IntArray> {
        val sortedIntervals = intervals.sortedBy { it[0] }
        val mergedIntervals = mutableListOf<IntArray>()
        var start = sortedIntervals[0][0]
        var end = sortedIntervals[0][1]
        sortedIntervals.forEach { (currStart, currEnd) ->
            if (currStart > end) {
                mergedIntervals.add(intArrayOf(start, end))
                start = currStart
                end = currEnd
            } else {
                end = maxOf(end, currEnd)
            }
        }
        mergedIntervals.add(intArrayOf(start, end))
        return mergedIntervals.toTypedArray()
    }
}

fun main() {
    val testCases = listOf(
        arrayOf(
            intArrayOf(1, 3), intArrayOf(2, 6), intArrayOf(8, 10), intArrayOf(15, 18),
        ),
        arrayOf(intArrayOf(1, 4), intArrayOf(4, 5))
    )
    testCases.forEach {
        Solution56().merge(it).also { ans ->
            println(ans.map { interval -> interval.contentToString() }.toList())
        }
    }
}
