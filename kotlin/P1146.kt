class SnapshotArray(length: Int) {
    private var snapId = 0
    private val snapMaps = Array(length) { mutableListOf(0 to 0) }

    fun set(index: Int, `val`: Int) {
        val newPair = snapId to `val`
        if (snapMaps[index].last().first == snapId) {
            snapMaps[index][snapMaps[index].lastIndex] = newPair
        } else {
            snapMaps[index].add(newPair)
        }
    }

    fun snap(): Int {
        return snapId++
    }

    fun get(index: Int, snap_id: Int): Int {
        val targetMap = snapMaps[index]

        var l = 0
        var r = targetMap.size - 1
        while (l < r) {
            val mid = (l + r) / 2
            if (targetMap[mid].first >= snap_id) {
                r = mid
            } else {
                l = mid + 1
            }
        }
        return if (targetMap[l].first > snap_id) {
            targetMap[l - 1].second
        } else {
            targetMap[l].second
        }
    }

}

fun main() {
    val snapShotArray = SnapshotArray(3)
    snapShotArray.set(1, 6)
    snapShotArray.snap()
    snapShotArray.snap()
    snapShotArray.set(0, 4)
    snapShotArray.set(2, 1)
    println(snapShotArray.get(0, 1))
}
