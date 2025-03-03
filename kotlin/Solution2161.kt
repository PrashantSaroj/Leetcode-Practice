class Solution2161 {
    fun pivotArray(nums: IntArray, pivot: Int): IntArray {
        val numsCount = nums.size
        var l = 0
        var r = numsCount - 1
        val pivotedNums = IntArray(numsCount)

        for (i in 0 until numsCount) {
            if (nums[i] < pivot) pivotedNums[l++] = nums[i]
            if (nums[numsCount - 1 - i] > pivot) pivotedNums[r--] = nums[numsCount - 1 - i]
        }

        for (i in l..r) pivotedNums[i] = pivot

        return pivotedNums
    }
}

fun main() {
    val testCases = listOf(
        intArrayOf(9, 12, 5, 10, 14, 3, 10) to 10,
        intArrayOf(-3, 4, 3, 2) to 2,
    )
    testCases.forEach {
        println(Solution2161().pivotArray(it.first, it.second).contentToString())
    }
}
