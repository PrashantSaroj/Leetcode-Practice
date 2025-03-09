import kotlin.math.sqrt

class Solution2523 {
    private fun getPrimes(left: Int, right: Int): List<Int> {
        val sieve = BooleanArray(right + 1) { true }
        sieve[1] = false
        val maxFactor = sqrt(right.toDouble()).toInt() + 1
        for (i in 2..maxFactor) {
            if (sieve[i]) {
                var curFactor = 2
                while (curFactor * i <= right) sieve[(curFactor++) * i] = false
            }
        }

        val primes = mutableListOf<Int>()
        for (i in left..right) {
            if (sieve[i]) primes.add(i)
        }
        return primes
    }

    fun closestPrimes(left: Int, right: Int): IntArray {
        val primes = getPrimes(left, right)
        var minDiff = Int.MAX_VALUE
        var num1 = -1
        var num2 = -1
        for (i in 1 until primes.size) {
            if (primes[i] - primes[i - 1] < minDiff) {
                minDiff = primes[i] - primes[i - 1]
                num1 = primes[i - 1]
                num2 = primes[i]
            }
        }
        return intArrayOf(num1, num2)
    }
}

fun main() {
    val testCases = listOf<Pair<Int, Int>>(10 to 19, 4 to 6)
    testCases.forEach { println(Solution2523().closestPrimes(it.first, it.second).contentToString()) }
}
