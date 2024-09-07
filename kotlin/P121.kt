class Solution {
    fun maxProfit(prices: IntArray): Int {
        val maxPrices = IntArray(prices.size)
        maxPrices[prices.size - 1] = prices[prices.size - 1]
        for (i in prices.size - 2 downTo 0) {
            if (prices[i] > maxPrices[i + 1]) {
                maxPrices[i] = prices[i]
            } else {
                maxPrices[i] = maxPrices[i + 1]
            }
        }

        var currMaxProfit = 0
        for (i in 0..(prices.size - 1)) {
            val newProfit = maxPrices[i] - prices[i]
            if (newProfit > currMaxProfit) {
                currMaxProfit = newProfit
            }
        }
        return currMaxProfit
    }
}

fun main() {
    val prices1 = intArrayOf(7, 1, 5, 3, 6, 4)
    val prices2 = intArrayOf(7, 6, 4, 3, 1)
    val sol = Solution()
    println(sol.maxProfit(prices1))
    println(sol.maxProfit(prices2))
}
