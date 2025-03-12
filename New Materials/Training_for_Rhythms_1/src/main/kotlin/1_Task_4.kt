//Решите в целых числах уравнение:
//sqrt(ax+b)=c
//a, b, c – данные целые числа: найдите все решения или сообщите, что решений в целых числах нет.

fun main(args:Array<String>)
{
    var a = readLine()!!.toFloat()
    var b = readLine()!!.toFloat()
    var c = readLine()!!.toFloat()

    if (c<0)
        println("NO SOLUTION")
    else if (a==0f && b==c*c)
        println("MANY SOLUTIONS")
    else if (a!=0f && ((c*c-b)/a)%1==0f)
    {
        var x = (c * c - b) / a
        var z = x.toInt()
        println("$z")
    }
    else
        println("NO SOLUTION")

}