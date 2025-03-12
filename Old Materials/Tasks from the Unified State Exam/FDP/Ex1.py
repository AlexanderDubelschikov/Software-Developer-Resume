from turtle import *
tracer(0)
left(90)
dot(7)
k = 50
for i in range(10):
  forward(6*k)
  right(120)
up()

for x in range(-10,10):
  for y in range(-10,10):
    goto(x*k,y*k)
    dot(3)
done()