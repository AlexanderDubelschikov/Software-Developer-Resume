//Дан список. Определите, является ли он монотонно возрастающим(то есть верно ли, что каждый элемент этого списка больше предыдущего).
//Выведите YES, если массив монотонно возрастает и NO в противном случае.

fun main(args:Array<String>)
{
    var list = readLine()!!.split(" ")
    var list2 = mutableListOf<Int>()
    for (i in 0..list.size-1)
    {
        list2.add(list[i].toInt())
    }

    println(solve(list2))

}

fun solve(mass: MutableList<Int>):String
{
    var k = 0
    for (i in 0..mass.size-2)
    {
        if (mass[i]>=mass[i+1])
        k = 1;

    }

    if (k == 1)
        return "NO"
    else
        return "YES"

}