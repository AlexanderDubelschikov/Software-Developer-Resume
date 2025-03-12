from turtle import *
tracer(0)
k = 10
dot(3)
for i in range(10):
    forward(22*k)
    right(90)
    forward(16 * k)
    right(90)
up()
forward(1*k)
right(90)
forward(1*k)
left(90)
down()
for i in range(10):
    forward(72 * k)
    right(90)
    forward(79 * k)
    right(90)
up()
for x in range(-30,35):
    for y in range(-30,25):
        goto(x*k,y*k)
        dot(4)
done()