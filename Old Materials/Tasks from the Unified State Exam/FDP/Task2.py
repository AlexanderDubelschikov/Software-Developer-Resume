from turtle import *
tracer(0)
left(90)
dot(7)
k = 20
for i in range(15):
  forward(15*k)
  right(120)
up()

for x in range(0,15):
  for y in range(0,15):
    goto(x*k,y*k)
    dot(3)
done()