//Попытка решить руками

fun main(args: Array<String>)
{
    var str = readLine()!!.split(" ")
    var mass = mutableListOf<Long>()

    for (i in 0 until str.size)
    {
        if(str[i]!="")
            mass.add(str[i].toLong())
    }

    val (result1, result2, result3) = solve_8(mass)
    println("$result1 $result2 $result3")

}

fun solve_8(mass: MutableList<Long>):Triple<Long, Long, Long>
{
    var result1: Long
    var result2: Long
    var result3: Long

    var masshelp = listOf<Long>(mass[0], mass[1], mass[2])
    var sortmass = mass.sorted()
    /*for(i in 0 until mass.size)
    {
        println(sortmass[i])
    }*/
    var max1 = masshelp[0]
    var max2 = masshelp[1]
    var max3 = masshelp[2]
    var min1 = max2
    var min2 = max3


    for(i in 3 until mass.size)
    {
        if(mass[i]<=min1)
        {
            min2=min1
            min1=mass[i]
        }
        else if(mass[i]>min1 && mass[i]<=min2)
        {
            min2=mass[i]
        }

        if(mass[i]>=max1)
        {
            max3=max2
            max2=max1
            max1=mass[i]
        }
        else if(mass[i]<max1 && mass[i]>=max2)
        {
            max3=max2
            max2=mass[i]
        }
        else if(mass[i]<max2 && mass[i]>=max3)
            max3 = mass[i]
    }

    if (min1*min2*max1>max1*max2*max3)
    {
        result1 = min1
        result2 = min2
        result3 = max1
    }
    else
    {
        result1 = max1
        result2 = max2
        result3 = max3
    }

    return Triple(result1, result2, result3)
}

