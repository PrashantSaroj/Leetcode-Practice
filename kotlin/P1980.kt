class Solution {
    fun findDifferentBinaryString(nums: Array<String>): String {
        val n = nums.size
        // pigeon hole => n+1 holes & n pigeon
        val initialNums = Array<Boolean>(n+1) {false}
        nums.forEach {
            val curInt = it.toInt(2)
            if (curInt <= n) {
                initialNums[curInt] = true
            }
        }

        initialNums.forEachIndexed { index, seen ->
            if (!seen) {
                return index.toString(2).padStart(n, '0')
            }
        }
        return  ""
    }
}

fun main() {
    val testCases = listOf(
        arrayOf("01","10"),
        arrayOf("00","01"),
        arrayOf("111","011","001"),
    )

    testCases.forEach {
        println(Solution().findDifferentBinaryString(it))
    }
}
