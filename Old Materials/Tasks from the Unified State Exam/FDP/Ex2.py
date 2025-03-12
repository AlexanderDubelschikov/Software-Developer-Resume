from turtle import *
tracer(0)
k = 20
dot(7)
for i in range(3):
    forward(7*k)
    right(90)
    forward(12*k)
    right(90)
up()
forward(4*k)
right(90)
forward(6*k)
left(90)
down()
for i in range(4):
    forward(83*k)
    right(90)
    forward(77*k)
    right(90)
up()
for x in range(-15,15):
    for y in range(-15,15):
        goto(x*k,y*k)
        dot(4)
done()