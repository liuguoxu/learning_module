animal = {name = "", age = 0}

function animal:say()
    print("i am "..self.name)
    print("my age is "..self.age)
end

animal.age = 12
animal.name = "jack"

animal:say()