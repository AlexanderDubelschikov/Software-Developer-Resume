from turtle import *
tracer(0)
k = 15
dot(3)
for i in range(3):
    forward(10*k)
    right(120)
up()
forward(10*k)
right(90)
forward(3*k)
down()
for i in range(4):
    forward(10*k)
    right(90)
up()
for x in range(-15,15):
    for y in range(-15,15):
        goto(x*k,y*k)
        dot(4)
done()