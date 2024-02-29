x=input("Enter first number ")
z=input("Enter what you want to do like +,-,*,/,%     ")
y=input("Enter second number")
if z =="+":
    sum=int(x)+int(y)
    print(sum)
elif z =="-":
    sum=int(x)-int(y)
    print(sum)
elif z =="*":
    sum=int(x)*int(y)
    print(sum)
elif z =="/":
    sum=int(x)/int(y)
    print(sum)
elif z =="%":
    sum=int(x)%int(y)
    print(sum)
else:
    print("Invalid operation")
