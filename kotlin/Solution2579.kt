class Solution2579 {
    fun coloredCells(n: Int): Long {
        /**
         * middle row -> 2n - 1
         * rest -> 2* (1 + 3 + 2*n-3) = 2 * (n-1)^2
         */
        val nLong = n.toLong()
        return 2 * nLong - 1 + 2 * (nLong - 1) * (nLong - 1)
    }
}