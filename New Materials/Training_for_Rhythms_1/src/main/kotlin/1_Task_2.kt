//Даны три натуральных числа. Возможно ли построить треугольник с такими сторонами. Если это возможно,
// выведите строку YES, иначе выведите строку NO. Треугольник — это три точки, не лежащие на одной прямой.

fun main(args:Array<String>){

    var a = readLine()!!.toInt()
    var b = readLine()!!.toInt()
    var c = readLine()!!.toInt()

    if (a>0 && b>0 && c>0 && a+b>c && a+c>b && b+a>c)
        println("YES")
    else
        println("NO")
}