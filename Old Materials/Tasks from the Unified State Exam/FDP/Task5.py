from turtle import *
tracer(0)
left(90)
dot(7)
k = 20
for i in range(5):
    forward(8*k)
    right(120)
    for j in range(2):
        forward(4 * k)
        right(60)
    forward(4 * k)
    right(120)
up()

for x in range(-10,10):
  for y in range(-10,10):
    goto(x*k,y*k)
    dot(3)
done()