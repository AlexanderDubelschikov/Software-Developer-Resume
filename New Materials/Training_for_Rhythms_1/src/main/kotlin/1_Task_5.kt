fun main(args:Array<String>)
{


    var list = readLine()!!.split(" ")
    var z:Int = 0
    var k1 = list[0].toFloat()
    var m = list[1].toInt()
    var k2 = list[2].toFloat()
    var p2 = list[3].toInt()
    var n2 = list[4].toFloat()
    var p1 = 1
    var p3 = 1
    var n1 = 0
    var k3 = k2

    var kof = k2/(n2+((p2-1)*m))
    if (kof%1!=0f)
        z = (kof+1).toInt()
    else
        z = kof.toInt()
    var max_k_p = m*z
    //Здесь все верно

    while (k3>max_k_p)
    {
        p3=p3+1
        k3=k3-max_k_p
    }
    //Вроде все верно

    if (p2!=p3) {
        p1 = -1
        n1 = -1
    }
    else if (k1 == k2 || n2>m)
    {
        p1 = p2
        n1 = n2.toInt()
    }
    else
    {
        if (n2==1f && p2 == 1)
        {
            p1 = 0
            while (k1>max_k_p)
            {
                k1=k1-max_k_p
            }
        }
        else
        {
            while (k1>max_k_p)
            {
                p1=p1+1
                k1=k1-max_k_p
            }
        }


        kof = k1.toFloat()/z.toFloat()

        if (kof%1!=0f)
        {
            n1 = (kof+1).toInt()
        }
        else
            n1 = kof.toInt()
    }

    if(p1==0 && m!=1)
        n1 = 0


    println("$p1 $n1")

}