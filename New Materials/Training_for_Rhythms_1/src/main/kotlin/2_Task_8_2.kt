fun main(args: Array<String>)
{
    var str = readLine()!!.split(" ")
    var mass = mutableListOf<Long>()

    for (i in 0 until str.size)
    {
        if(str[i]!="")
            mass.add(str[i].toLong())
    }

    val (result1, result2, result3) = solve_8_2(mass)
    println("$result1 $result2 $result3")

}

fun solve_8_2(mass: MutableList<Long>):Triple<Long, Long, Long>
{
    var result1: Long
    var result2: Long
    var result3: Long
    var masshelp = mass.sorted()
    /*for (i in 0 until masshelp.size)
    {
        println(masshelp[i])
    }*/

    var max1 = masshelp[mass.size-1]
    var max2 = masshelp[mass.size-2]
    var max3 = masshelp[mass.size-3]
    var min2 = masshelp[0]
    var min1 = masshelp[1]

    if (max2*max3>min1*min2)
    {
        result1 = max1
        result2 = max2
        result3 = max3
    }
    else
    {
        result1 = max1
        result2 = min1
        result3 = min2
    }

    return Triple(result1, result2, result3)

}