fun main(args:Array<String>)
{
    var str = readLine()!!.split(" ")
    var mass = mutableListOf<Int>()

    for (i in 0 until str.size){
        mass[i] = str[i].toInt()
    }
}

fun solve_6(mass: MutableList<Int>){

    var flag = 0
    var r = 0

    for (i in 0 until mass.size)
    {
        if (flag == 0){
            if (mass[i]==mass[i+1])
            {
                flag = 1
                r = i
            }
            else if(mass[i-1]==mass[i+1])
            {
                flag = 2
                r = i
            }
        }

        if (flag==1)
        {
            for (n in i until mass.size)


        }

        if (flag == 2)
        {

        }
    }

}