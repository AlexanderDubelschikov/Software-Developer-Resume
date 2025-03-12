from turtle import *

dot(7)
tracer(0)
down()
m = 1

for i in range(2):
    forward(7*m)
    right(60)
    forward(12*m)
    right(120)
up()
forward(7*m)
right(60)
down()
for i in range(2):
    forward(5*m)
    right(120)
    forward(10*m)
    right(60)
up()

for x in range(-45, 45):
    for y in range(-30, 40):
        goto(x * m, y * m)
        dot(3)
done()