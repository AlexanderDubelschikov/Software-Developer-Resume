from turtle import *
tracer(0)
k = 10
dot(10)
for i in range(2):
    forward(10*k)
    right(90)
    forward(4 * k)
    right(90)
up()
forward(3*k)
right(90)
forward(6*k)
left(90)
down()
for i in range(2):
    forward(8 * k)
    right(90)
    forward(6 * k)
    right(90)
up()
for x in range(-30,35):
    for y in range(-30,25):
        goto(x*k,y*k)
        dot(4)
done()