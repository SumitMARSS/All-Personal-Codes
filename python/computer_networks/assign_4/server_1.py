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

    n = int(str_received)
    sum = 0
    print("Natural numbers are:")
    while(n >= 1):
        print(n)
        sum = sum + n*n
        n = n-1

    str1 = str(sum)
    conn.sendall(str1.encode())
    print("Message for client square of n natural number:", str1)
print("Connection closed from client")		

#Close the connection with the client
conn.close()
