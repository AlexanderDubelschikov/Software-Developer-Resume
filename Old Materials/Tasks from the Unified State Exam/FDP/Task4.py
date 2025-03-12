from turtle import *
tracer(0)
left(90)
dot(7)
k = 20
right(45)
for i in range(7):
    left(60)
    forward(5*k)
    left(120)
    forward(5 * k)
up()

for x in range(-10,0):
  for y in range(-10,10):
    goto(x*k,y*k)
    dot(3)
done()