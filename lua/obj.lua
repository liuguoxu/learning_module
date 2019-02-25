animal = {name = "", age = 0, money = 100}


function animal:say()
    print("i am "..self.name)
    print("my age is "..self.age)
end


animal.age = 12
animal.name = "jack"

animal:say()

function animal:spend(m)
	self.money = self.money - m
end

function animal.howMuchMoneyHave(a)
	return a.money
end

animal.age = 12
animal.name = "jack"

animal:say()

print(animal.howMuchMoneyHave(animal))
