import socket

port=50000
host="127.0.0.1"

server= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((host, port))
print("socket binded to %s" %(port))

server.listen(2)
print("Socket is listening...")

# Accepting/Establishing connection from client.
conn, addr = server.accept()        
print('Got connection from', addr)

while True:
    data = conn.recv(2048)
    str_received = data.decode()
    print("Message from client:", str_received)

    if str_received == 'quit':
        break
    # sz = len(str_received)
    arr = str_received.split(",")
    print(arr)
    sz = len(arr)
    stack = []
    str1 = ""
    
    i = 0
    while i < sz:
        if arr[i] == "+" or arr[i] == "-" or arr[i] == "*" or arr[i] == "/":
            num1 = int(stack[-1])
            stack.pop()
            num2 = int(stack[-1])
            stack.pop()
            mp = {"+":num1+num2,"-":num2-num1,"*":num1*num2,"/":num2/num1}
            res = mp[arr[i]]
            stack.append(res)
        elif arr[i] == ",":
            continue
        else:
            stack.append(arr[i])
        i = i+1
    ans = stack[-1]
    str1 = str(ans)
    conn.sendall(str1.encode())
    print("Message for client:", str1)
print("Connection closed from client")		

#Close the connection with the client
conn.close()