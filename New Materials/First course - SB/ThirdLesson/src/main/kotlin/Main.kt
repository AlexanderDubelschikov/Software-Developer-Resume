fun main(args: Array<String>) {
    val result = multiply(a =5,b =6)
    println(result)
    println(multiply())
    var name = "Alexander"
    var nameRobot = 1234
    printName(nameRobot)
    printName(name)
    var goodBank: Double
    goodBank = calculateSavings(70000,0.25,5)
    println(testUnit())

    val type: (Int)->String //Принимает Int, возвращает String.
    val type2: (Int, Double, Int) ->Double //Принимает Int, Double, Int, возращает Double.

    val anonimous: (Int) -> Unit = fun(a:Int) {print(a)}
    anonimous(123)

    val lambda = {println("Lambda Func")}
    val lambdaWithParam ={msg:String -> { println(msg) }}
    val lambdaWithParamAndReturn = {x: Int, y:Int -> x*y}

    val str = "This is typical task for developer interview"
    //str.count { char -> checkSymb(char) }
    //str.count {checkSymb(it)}
    println(str.count{it == 'e'})

    val volwes = "aeoiu"
    println(str.filter { it !in volwes })


    //val sum = calculateSavings(3000, 0.12, 7)+calculateSavings(55000, 0.20, 9)
    val first = calculateSavings(3000, 0.12, 7, printInfo = {_,_,_,bank ->
        println("First Member bank - $bank")
    })
    val second = calculateSavings(55000, 0.20, 9) {salary,percent,period,bank ->
        println("Second Member: salary - $salary, percent - $percent, period - $period, bank - $bank")
    }
    println(first + second)
}

fun checkSymb(char: Char):Boolean = char == 'e'

fun multiplyFunc(func: () -> Unit){

}


fun multiply(a:Int = 0, b:Int = 0):Int{
    return a*b
}
fun multiply(a: Double, b: Double):Int = (a*b).toInt()
fun multiply(a: Int, b: Int, c: Int):Int = a*b*c
/*fun multiply(a:Int, b:Int) = a*b*/
fun printName (a: String){
    println("Your Name is: $a")
}
fun printName (a: Int){
    println("Your Name, my dear robot, is: $a")
}
fun testUnit() {}
fun calculateSavings(salary: Int = 15000,
                     percent: Double = 0.30,
                     period: Int = 12,
                     printInfo: ((salary: Int, percent: Double, period: Int, bank: Double) -> Unit)? = null
):Double{

    val netSalary = salary*0.87
    val bank = netSalary*percent*period
    printInfo?.invoke(salary,percent,period,bank)
    //println ("Salary: $salary, Percent: $percent, months: $period, bank: $bank")
    return bank
}