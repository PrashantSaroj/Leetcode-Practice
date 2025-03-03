class StockPrice() {
    private var currT = 0
    private var currP = 0
    private val time2Price = mutableMapOf<Int, Int>()
    private val price2Time = sortedMapOf<Int, MutableSet<Int>>()

    fun update(timestamp: Int, price: Int) {
        if (timestamp >= currT) {
            currT = timestamp
            currP = price
        }

        time2Price[timestamp]?.let { prevPrice ->
            price2Time[prevPrice]!!.remove(timestamp)
            if (price2Time[prevPrice]!!.isEmpty()) price2Time.remove(prevPrice)
        }
        time2Price[timestamp] = price
        if (price2Time[price] == null) price2Time[price] = mutableSetOf()
        price2Time[price]!!.add(timestamp)

    }

    fun current(): Int {
        return currP
    }

    fun maximum(): Int {
        return price2Time.lastKey()
    }

    fun minimum(): Int {
        return price2Time.firstKey()
    }
}

fun main() {
    with(StockPrice()) {
        update(1, 10)
        update(2, 5)
        println(current())
        println(maximum())
        update(1, 3)
        println(maximum())
        update(4, 2)
        println(minimum())
    }
}
