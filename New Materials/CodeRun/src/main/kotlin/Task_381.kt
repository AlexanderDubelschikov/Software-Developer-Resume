fun main (args:Array<String>){

    var str = readLine()
    var list = str!!.split(" ")
    var days = list[0].toInt()
    var week_day = list[1]
    var i = 0
    var d = 1
    var string = ""
    var stop = false

    when(week_day)
    {
        "Monday" -> i = -1
        "Tuesday" -> i = -2
        "Wednesday" -> i = -3
        "Thursday" -> i = -4
        "Friday" -> i = -5
        "Saturday" -> i = -6
        "Sunday" -> i = -7
    }

    while (stop == false)
    {
        for(k in 1..7) {
            if (i<-1)
            {
                string = string + ".. "
                i++
            }
            else if (days >= d && i>=-1){
                if (d<10) string = string + ".$d " else string = string + "$d "
                d = d+1
            }
            else
            {
                stop = true
                break
            }

        }
        println(string.removeSuffix(" "))
        string = ""
    }
    println(string.removeSuffix(" "))
}