num = int(input("Enter a number: "))

if num % 2 == 0:
    parity = "even"
else:
    parity = "odd"

if num > 0:
    sign = "positive"
elif num < 0:
    sign = "negative"
else:
    sign = "zero"

print("Number is " + parity  + " and " + sign)
