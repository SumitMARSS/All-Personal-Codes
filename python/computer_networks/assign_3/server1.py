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

    if str_received == 'bye':
        break

    n = len(str_received)
    str1 = ""
    
    if n % 2 == 0:
        i = 0
        while i < n:
            str1 += str_received[i]
            i = i + 2
    else:
        i = 1
        while i < n:
            str1 += str_received[i]
            i = i + 2

    conn.sendall(str1.encode())
    print("Message from client:", str1)
print("Connection closed from client")		

#Close the connection with the client
conn.close()
