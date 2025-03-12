import kotlin.math.max
import kotlin.math.min

//Дан список, заполненный произвольными целыми числами. Найдите в этом списке два числа, произведение которых максимально. Выведите эти числа в порядке неубывания.
//Список содержит не менее двух элементов. Числа подобраны так, что ответ однозначен.
//Решение должно иметь сложность O(n), где n - размер списка.

fun main(){

    var str = readLine()!!.split(" ")
    var mass = mutableListOf<Long>()

    for (i in 0 until str.size)
    {
        if(str[i]!="")
        mass.add(str[i].toLong())
    }

    val (result1, result2) = solve_6(mass)
    println("$result1 $result2")
}

fun solve_6(mass: MutableList<Long>):Pair<Long,Long>
{
    var min1 = min(mass[0], mass[1])
    var min2 = max(mass[0], mass[1])
    var max1 = min(mass[0], mass[1])
    var max2 = max(mass[0], mass[1])
    var result_1 = 0L
    var result_2 = 0L

    for (i in 2 until mass.size)
    {
        if (mass[i]<=min1)
        {
            min2 = min1
            min1 = mass[i]
        }
        else if (mass[i]>min1 && mass[i]<=min2)
        {
            min2 = mass[i]
        }

        if (mass[i]>=max2)
        {
            max1 = max2
            max2 = mass[i]
        }
        else if (mass[i]>=max1 && mass[i]<max2)
        {
            max1 = mass[i]
        }
    }

    if (max1*max2>min1*min2)
    {
        result_1 = max1
        result_2 = max2
    }
    else
    {
        result_1 = min1
        result_2 = min2
    }

    return Pair(result_1,result_2)
}



