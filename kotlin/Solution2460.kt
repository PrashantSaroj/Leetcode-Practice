class Solution2460 {
    private fun getNextZero(nums: IntArray, start: Int): Int {
        for (i in start until nums.size) {
            if (nums[i] == 0) return i
        }
        return Int.MAX_VALUE
    }

    fun applyOperations(nums: IntArray): IntArray {
        for (i in 0 until nums.size - 1) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i] shl 1
                nums[i+1] = 0
            }
        }

        var zeroIndex = getNextZero(nums, 0)
        var i = zeroIndex
        while (i < nums.size) {
            if (nums[i] != 0) {
                nums[zeroIndex] = nums[i]
                nums[i] = 0
                zeroIndex = getNextZero(nums, zeroIndex)
                if (zeroIndex > i) i = zeroIndex
            }
            i++
        }
        return nums
    }
}

fun main() {
    val testCases = listOf(
        intArrayOf(1, 2, 2, 1, 1, 0),
        intArrayOf(0, 1),
    )
    testCases.forEach {
        println(Solution2460().applyOperations(it).contentToString())
    }
}
