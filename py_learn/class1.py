class Turtle:
#atri
    color = 'green'
    weight = 10

    def eat(sel):
        sel.color = 'red'
        print('I am eating')


tt =Turtle()

print(tt.color)

tt.eat()
print(tt.color)
