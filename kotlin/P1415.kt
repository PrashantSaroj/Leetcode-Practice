class Solution1415 {
    private val alphabets = listOf('a', 'b', 'c')
    private val happyStrings = mutableSetOf<String>()

    private fun stringHelper(curr: String, n: Int) {
        if (curr.length == n) {
            happyStrings.add(curr)
            return
        }

        val prev: Char = if (curr.isEmpty()) Character.MIN_VALUE else curr.last()
        alphabets.forEach {
            if (it != prev) {
                stringHelper(curr + it, n)
            }
        }
    }

    fun getHappyString(n: Int, k: Int): String {
        stringHelper("", n)
        return happyStrings.elementAtOrNull(k-1) ?: ""
    }
}

fun main() {
    val testCases = listOf(Pair(1, 3), Pair(1, 4), Pair(3, 9))
    testCases.forEach {
        println(Solution1415().getHappyString(it.first, it.second))
    }
}