//По последовательности чисел во входных данных определите ее вид:
//CONSTANT – последовательность состоит из одинаковых значений
//ASCENDING – последовательность является строго возрастающей
//WEAKLY ASCENDING – последовательность является нестрого возрастающей
//DESCENDING – последовательность является строго убывающей
//WEAKLY DESCENDING – последовательность является нестрого убывающей
//RANDOM – последовательность не принадлежит ни к одному из вышеупомянутых типов
fun main(args:Array<String>){

    println(solve())


}

fun solve():String
{
    var i = 0
    var p = -1
    var r = 0
    var k = 0
    var result = "null"

    var str = readLine()!!.toInt()
    var str2 = readLine()!!.toInt()

    if (str == str2)
    {
        r = 1
        i = 5
    }
    else if (str > str2)
    {
        r = 2
        i = 3
    }
    else
    {
        r = 3
        i = 1
    }

    str = readLine()!!.toInt()

    while (str != -2000000000) {

        if (r == 1) {
            if (str==str2)
            {
                i = i
            }
            else if (str>str2 && k!=2)
            {
                i = 2
                k = 1
            }
            else if (str<str2 && k!=1)
            {
                i = 4
                k = 2
            }
            else
            {
                p = 0
            }
        }
        if (r == 2) {
            if (str<str2)
            {
                i = i
            }
            else if (str==str2)
            {
                i = 4
            }
            else
            {
                p = 0
            }
        }
        if (r == 3) {
            if (str>str2)
            {
                i = i
            }
            else if (str==str2)
            {
                i = 2
            }
            else
            {
                p = 0
            }
        }

        str2 = str
        str = readLine()!!.toInt()
    }


    if (p==-1)
    {
        p = i
    }

    when(p)
    {
        0->result = "RANDOM"
        1->result = "ASCENDING"
        2->result = "WEAKLY ASCENDING"
        3->result = "DESCENDING"
        4->result = "WEAKLY DESCENDING"
        5->result = "CONSTANT"

    }

    return result
}
