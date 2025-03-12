from turtle import *
tracer(0)
dot(10)
k = 15
for i in range(2):
    forward(6*k)
    right(90)
    forward(12*k)
    right(90)
up()
forward(1*k)
right(90)
forward(3*k)
left(90)
down()
for i in range(2):
    forward(77*k)
    right(90)
    forward(45*k)
    right(90)
up()
for x in range(-15,15):
    for y in range(-15,15):
        goto(x*k,y*k)
        dot(4)
done()