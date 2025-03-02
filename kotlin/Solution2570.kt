class Solution2570 {
    fun mergeArrays(nums1: Array<IntArray>, nums2: Array<IntArray>): Array<IntArray> {
        val merged = mutableListOf<IntArray>()
        var i1 = 0
        var i2 = 0
        while (i1 < nums1.size && i2 < nums2.size) {
            val (id1, val1) = nums1[i1]
            val (id2, val2) = nums2[i2]
            if (id1 > id2) {
                merged.add(intArrayOf(id2, val2))
                i2++
            } else if (id2 > id1) {
                merged.add(intArrayOf(id1, val1))
                i1++
            } else {
                merged.add(intArrayOf(id1, val1 + val2))
                i1++
                i2++
            }
        }

        while (i1 < nums1.size) merged.add(nums1[i1++])
        while (i2 < nums2.size) merged.add(nums2[i2++])
        return merged.toTypedArray()
    }
}

fun main() {
    val testCases = listOf(
        Pair(
            arrayOf(intArrayOf(1, 2), intArrayOf(2, 3), intArrayOf(4, 5)),
            arrayOf(intArrayOf(1, 4), intArrayOf(3, 2), intArrayOf(4, 1))
        ),
        Pair(
            arrayOf(intArrayOf(2, 4), intArrayOf(3, 6), intArrayOf(5, 5)),
            arrayOf(intArrayOf(1, 3), intArrayOf(4, 3))
        )
    )
    testCases.forEach {
        println(
            Solution2570().mergeArrays(it.first, it.second)
                .map { it.contentToString() }
                .toList()
        )
    }
}
