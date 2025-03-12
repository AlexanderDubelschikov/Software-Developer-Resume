fun main(args: Array<String>) {

    var num: Int = 5
    val num_2: Int = 10
    println(num)

    val eiffelTowerHeight = 325
    print(eiffelTowerHeight)

    var newVariable : Int
    newVariable = 10

    //Byte, Short, Int, Long - целые числа.
    //Float, Double (в них есть NaN и INFINITY) - числа с плавующей точкой.
    //Сложение, вычетание, умножение, деление, деление с остатком

    val number = 1000L
    val number2 = 10.1f
    var number3: Long
    var number4 = 10
    number3 = number4.toLong()

    val a = 5
    val b = 2

    println("a+b=${a+b}")
    println("a-b=${a-b}")
    println("a*b=${a*b}")
    println("a/b=${a/b.toDouble()}")
    println("a%b=${a%b}")

    /*
    a==b
    a!=b
    a>b
    a<b
    a>=b
    a<=b
     */

    var numberEven = 10
    var newBooleanVariable: Boolean = 5>10
    val booleanVariable = true
    val isEven = numberEven % 2 == 0

    println(newBooleanVariable)
    println("$numberEven is Even - $isEven")

    //Логическое И - &&, логическое ИЛИ - ||, логическое НЕ - !

    val numberForCheck = -5
    val isPositive = numberForCheck>0 || numberForCheck!=-5
    println("Is $numberForCheck is Positive or -5? $isPositive")
    val character: Char = 'A'
    val charNumber = '1'

    println(character.toInt())
    println(charNumber.toInt())

    val charC = character + 2
    println(charC)

    val stringNew: String = "Hello \nWorld"
    println(stringNew)

    val commonString = """Hello
        |World.
        |Good Day,
        |Sir!
    """.trimMargin()
    println(commonString)

    val secondChar = commonString[1]
    println(secondChar)

    val hello = "Hello"
    val world = " World"
    println(hello + world)
    println(hello.toUpperCase())
    val lenghtString = hello.length
    println(lenghtString)

    var str = "Hello World again"
    println(str.contains("Hello"))
    println(str.replace("H","2"))

    val replaceFirst = str.replaceFirst("l", "2")
    println(replaceFirst)

    var nulNum: Int = 5
    var nulNum2: Int? = null

    var nonNullString = "Null is not good!"
    var nullableString: String? = null

    println(nullableString?.toUpperCase())

    if (nullableString != null)
        println(nullableString.toUpperCase())





}