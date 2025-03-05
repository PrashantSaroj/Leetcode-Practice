class Solution394 {
    private fun getDigit(s: String, endIndex: Int): Pair<Int, Int> {
        var start = endIndex - 1
        while (start >= 0 && s[start].isDigit()) start--
        return s.substring(start + 1, endIndex).toInt() to start
    }

    private fun multiply(s: ArrayDeque<String>, multiplier: Int): String {
        val result = StringBuilder()
        while (true) {
            val cur = s.removeLast()
            if (cur == "]") break
            result.append(cur)
        }
        return result.toString().repeat(multiplier)
    }

    fun decodeString(s: String): String {
        var i = s.length - 1
        val evalStack = ArrayDeque<String>()
        while (i >= 0) {
            if (s[i] == ']') {
                evalStack.addLast(s[i--].toString())
            } else if (s[i] == '[') {
                val (multiplier, newI) = getDigit(s, i)
                evalStack.addLast(multiply(evalStack, multiplier))
                i = newI
            } else {
                evalStack.addLast(s[i--].toString())
            }
        }
        val evalBuilder = StringBuilder()
        while (evalStack.isNotEmpty()) evalBuilder.append(evalStack.removeLast())
        return evalBuilder.toString()
    }
}

fun main() {
    val testCases = listOf(
        "3[a]2[bc]",
        "3[a2[c]]",
        "2[abc]3[cd]ef",
    )
    testCases.forEach {
        println(Solution394().decodeString(it))
    }
}
