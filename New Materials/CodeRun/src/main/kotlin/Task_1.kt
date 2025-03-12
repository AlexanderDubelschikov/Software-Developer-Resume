
fun main(args:Array<String>){
    val del = " "

    val str = readLine()
    var list = str!!.split(del)

    //Встроенными функциями
    /*var list_2 = list.map { it.toInt() }.toTypedArray()
    var sortList = list_2.sorted()
    println(sortList[1])*/

    //Ручками
    var list_2 = list.map { it.toInt() }.toTypedArray()
    for (i in 0..2)
        for (j in 0..1){
            if(list_2[j]>list_2[j+1])
            {
                var list_help = list_2[j]
                list_2[j] = list_2[j+1]
                list_2[j+1] = list_help
            }
        }

    println(list_2[1])
}