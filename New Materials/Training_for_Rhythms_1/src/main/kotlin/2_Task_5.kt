import kotlin.math.max

fun main(args: Array<String>){

    var k = readLine()!!.toInt()
    var str = readLine()!!.split(" ")
    var mass = mutableListOf<Double>()

    for (i in 0 until str.size)
    {
        mass.add(str[i].toDouble())
    }

    println(solve_5(mass))
}

fun solve_5(mass: MutableList<Double>):Int{

    var max = mass.max()
    var help = 0.0
    var place = 1
    var k = 0

    for (i in mass.indexOfFirst { it == max } + 1 until mass.size-1)
    {
        if (mass[i]%10.0==5.0 && mass[i]>mass[i+1] && mass[i]>=help)
        {
            help = mass[i]
        }
    }

    if (help != 0.0) {
        for (i in 0 until mass.size) {
            if (mass[i] > help) {
                place = place + k + 1
            }
        }
    }
    else
        place = 0


    return place

}

