//Напишите программу, которая находит в массиве элемент, самый близкий по величине к  данному числу.

import java.lang.Math.abs

fun main (args: Array<String>){

    var num = readLine()!!.toInt()
    var str = readLine()!!.split(" ")
    var mass = mutableListOf<Int>()

    for (i in 0 until num)
    {
        mass.add(str[i].toInt())
    }

    var x = readLine()!!.toInt()

    println(solve_2(mass,num,x))


}

fun solve_2(mass: MutableList<Int>, num: Int, x: Int):Int
{
    var result = -9999

    for(i in 0 until num)
    {
        if (abs(mass[i]-x)<abs(result-x))
            result = mass[i]
    }

    return result
}