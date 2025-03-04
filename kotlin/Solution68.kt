class Solution68 {
    private fun justifyLine(words: List<String>, maxWidth: Int): String {
        if (words.size == 1) return words[0].padEnd(maxWidth)

        val spaces = maxWidth - words.sumOf { it.length }
        val buckts = words.size - 1
        val spaceL = spaces / buckts
        var extras = spaces % buckts
        val justified = StringBuilder().apply { append(words[0]) }
        for (i in 1 until words.size) {
            val spaceCount = spaceL + if (extras-- > 0) 1 else 0
            justified.append(" ".repeat(spaceCount))
            justified.append(words[i])
        }
        return justified.toString()
    }

    fun fullJustify(words: Array<String>, maxWidth: Int): List<String> {
        val allLines = mutableListOf<List<String>>()
        var currLine = mutableListOf<String>()
        var currLen = 0
        words.forEach {
            if (currLen +  it.length <= maxWidth) {
                currLen += (1 + it.length)
                currLine.add(it)
            } else {
                allLines.add(currLine.toList())
                currLine.clear()
                // move next word to next line
                currLine.add(it)
                currLen = it.length
            }
        }

        val justified = mutableListOf<String>()
        allLines.forEach {
            justified.add(justifyLine(it, maxWidth))
        }
        justified.add(currLine.joinToString(" ").padEnd(maxWidth))

        return justified
    }
}

fun main() {
    val testCases = listOf(
        arrayOf("Listen","to","many,","speak","to","a","few.") to 6,
        arrayOf("This", "is", "an", "example", "of", "text", "justification.") to 16,
        arrayOf("What", "must", "be", "acknowledgment", "shall", "be") to 16,
        arrayOf(
            "Science",
            "is",
            "what",
            "we",
            "understand",
            "well",
            "enough",
            "to",
            "explain",
            "to",
            "a",
            "computer.",
            "Art",
            "is",
            "everything",
            "else",
            "we",
            "do"
        ) to 20,
    )
    testCases.forEach {
        Solution68().fullJustify(it.first, it.second).forEach { println(it) }
    }
}
