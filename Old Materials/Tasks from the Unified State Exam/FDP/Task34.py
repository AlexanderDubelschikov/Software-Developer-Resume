from turtle import *
tracer(0)
k = 10
dot(3)
for i in range(4):
    forward(28*k)
    right(90)
    forward(26 * k)
    right(90)
up()
forward(8*k)
right(90)
forward(7*k)
left(90)
down()
for i in range(4):
    forward(67 * k)
    right(90)
    forward(98 * k)
    right(90)
up()
for x in range(-30,35):
    for y in range(-30,25):
        goto(x*k,y*k)
        dot(4)
done()