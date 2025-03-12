from turtle import *
tracer(0)
k = 15
dot(3)
for i in range(2):
    forward(9*k)
    right(90)
    forward(15 * k)
    right(90)
up()
forward(12*k)
right(90)
down()
for i in range(2):
    forward(6 * k)
    right(90)
    forward(12 * k)
    right(90)
up()
for x in range(-15,15):
    for y in range(-15,15):
        goto(x*k,y*k)
        dot(4)
done()