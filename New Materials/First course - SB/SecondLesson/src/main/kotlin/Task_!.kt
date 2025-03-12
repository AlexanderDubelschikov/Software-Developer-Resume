/*Что нужно сделать
Напишите программу, которая работает с рассмотренными типами данных с помощью изменяемых и неизменяемых переменных.
1) Создайте переменную firstName с типом String, которая ссылается на строку с вашим именем.
2) Создайте переменную lastName с типом String, которая ссылается на строку с вашей фамилией.
3) Создайте переменную height с типом Double, которая хранит ваш рост в метрах и изменяется.
4) Создайте переменную weight с типом Float, которая хранит ваш вес в килограммах.
5) Создайте переменную isChild с типом Boolean, которая хранит значение, указывающее, что вы ребёнок. Значение
переменной должно вычисляться исходя из значений переменных height и weight. Считайте, что человек является
ребёнком, если рост меньше 150 см или вес меньше 40 кг.
6) Создайте переменную info, которая хранит строку с информацией о вас. В строке должна быть вся информация,
доступная из переменных firstName, lastName, height, weight, isChild. Используйте для этого строковые шаблоны.
7) Выведите значение переменной info в консоль.
8) Измените значение переменной height после вывода информации из info.
9) Вновь вызовите вывод информации об info на экран, убедитесь, что в консоль вывелось обновлённое значение.
10) По желанию. Добейтесь, чтобы информация в переменной isChild обновилась.
11) По желанию. Добейтесь, чтобы информация на экране согласно п. 9 обновилась.*/

fun main (args: Array<String>){
    val firstName: String = "Alexander"
    val secondName: String = "Dubelschikov"
    var height: Double = 178.0
    val weight: Float = 102.5f
    println (weight)
    var isChild: Boolean = false

    if (height < 150.0 || weight < 40f)
        isChild = true

    println(isChild)

    var info = "Surename: $firstName, Name: $secondName, Height: $height, Weight: $weight. Child: $isChild"
    println(info)

    height = 130.1

    if (height < 150.0 || weight < 40f)
        isChild = true

    info = "Surename: $firstName, Name: $secondName, Height: $height, Weight: $weight. Child: $isChild"
    println(info)




}
