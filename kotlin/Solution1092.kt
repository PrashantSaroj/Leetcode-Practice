class Solution1092 {
    private fun lcs(s1: String, s2: String): String {
        val N1 = s1.length
        val N2 = s2.length
        val lcs = Array(N1 + 1) { Array(N2 + 1) { 0 } }

        for (i in 1..N1) {
            for (j in 1..N2) {
                if (s1[i - 1] == s2[j - 1]) lcs[i][j] = 1 + lcs[i - 1][j - 1]
                else lcs[i][j] = maxOf(lcs[i - 1][j], lcs[i][j - 1])
            }
        }

        // construct lcs
        var index = lcs[N1][N2] - 1;
        var i = N1;
        var j = N2;
        val subSeq = CharArray(index + 1)
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                subSeq[index] = s1[i - 1]
                i--; j--; index--
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                i--
            } else {
                j--
            }
        }
        return String(subSeq)
    }

    fun shortestCommonSupersequence(str1: String, str2: String): String {
        val lcs = lcs(str1, str2)
        var i = 0;
        var j = 0;
        var k = 0;
        val superSeq = StringBuilder()
        while (i < str1.length && j < str2.length && k < lcs.length) {
            if (str1[i] == lcs[k] && str2[j] == lcs[k]) {
                superSeq.append(str1[i])
                i++; j++; k++
            } else if (str1[i] == lcs[k] && str2[j] != lcs[k]) {
                superSeq.append(str2[j])
                j++
            } else if (str1[i] != lcs[k] && str2[j] == lcs[k]) {
                superSeq.append(str1[i])
                i++
            } else {
                superSeq.append(str1[i])
                if (str1[i] != str2[j]) superSeq.append(str2[j])
                i++; j++
            }
        }

        while (i < str1.length) superSeq.append(str1[i++])
        while (j < str2.length) superSeq.append(str2[j++])
        return superSeq.toString()
    }
}

fun main() {
    val testCases = listOf(
        "abac" to "cab",
        "aaaaaaaa" to "aaaaaaaa",
    )

    testCases.forEach { (s1, s2) ->
        println(Solution1092().shortestCommonSupersequence(s1, s2))
    }
}
