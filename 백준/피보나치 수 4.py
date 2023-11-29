def fibo(n):
    x,y = 0,1
    for i in range(n):
        x,y = y,x+y
    return x
print(fibo(int(input())))