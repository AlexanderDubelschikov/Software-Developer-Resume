//В школе решили на один прямоугольный стол поставить два прямоугольных ноутбука. Ноутбуки нужно поставить
// так, чтобы их стороны были параллельны сторонам стола. Определите, какие размеры должен иметь стол, чтобы
// оба ноутбука на него поместились, и площадь стола была минимальна.

fun main(args:Array<String>){

    var notebooks = readLine()
    var list = notebooks!!.split(" ")
    var a = list.get(0).toInt()
    var b = list.get(1).toInt()
    var c = list.get(2).toInt()
    var d = list.get(3).toInt()
    var x: Int
    var y: Int
    var min: Int
    var x_i: Int
    var y_i: Int


    x = (a+c)
    if (b<d) y= d else y = b
    min=x*y
    x_i=x
    y_i=y

    x = (a+d)
    if (b<c) y= c else y = b
    if (x*y<min)
    {
        min=x*y
        x_i=x
        y_i=y
    }

    x = (b+c)
    if (a<d) y= d else y = a
    if (x*y<min)
    {
        min=x*y
        x_i=x
        y_i=y
    }

    x=(b+d)
    if(a<c) y=c else y=a
    if (x*y<min)
    {
        min=x*y
        x_i=x
        y_i=y
    }

    print("$x_i $y_i")

}