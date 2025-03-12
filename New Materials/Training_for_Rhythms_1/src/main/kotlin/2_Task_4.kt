//Дан список чисел. Определите, сколько в этом списке элементов, которые больше двух своих соседей и выведите количество таких элементов.

fun main(args:Array<String>){

    var str = readLine()!!.split(" ")
    var mass = mutableListOf<Int>()

    for (i in 0 until str.size){
        mass.add(str[i].toInt())
    }

    println(solve_3(mass))
}

fun solve_3(mass: MutableList<Int>):Int{

    var result = 0

    for(i in 1 until mass.size-1)
    {
        if (mass[i]>mass[i+1] && mass[i]>mass[i-1])
            result+=1
    }

    return result
}