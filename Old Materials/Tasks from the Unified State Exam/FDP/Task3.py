from turtle import *
tracer(0)
left(90)
dot(7)
k = 20
right(45)
for i in range(9):
  forward(9*k)
  right(90)
up()

for x in range(0,15):
  for y in range(-15,15):
    goto(x*k,y*k)
    dot(3)
done()