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

def xor(a, b):
    result = []
    for i in range(1, len(b)):
        if a[i] == b[i]:
            result.append('0')
        else:
            result.append('1')
 
    return ''.join(result)

def mod2div(dividend, divisor):

    pick = len(divisor)
    tmp = dividend[0: pick]
 
    while pick < len(dividend):
 
        if tmp[0] == '1':
            tmp = xor(divisor, tmp) + dividend[pick]
 
        else:  
            tmp = xor('0'*pick, tmp) + dividend[pick]
        pick += 1
    if tmp[0] == '1':
        tmp = xor(divisor, tmp)
    else:
        tmp = xor('0'*pick, tmp)
 
    checkword = tmp
    return checkword


while True:
    data = conn.recv(2048)
    str_received = data.decode()
    n = len(str_received)
    data_val,key = str_received.split(',')
    print("Message from client:", str_received)
    if str_received == 'Quit':
        break
    
    l_key = len(key)
    print("l_key: ",l_key)
    appended_data = data_val + '0'*(l_key-1)
    print(appended_data)
    remainder = mod2div(appended_data, key)
    codeword = data_val + remainder
    print("Remainder : ", remainder)
    print("Encoded Data (Data + Remainder) : ", codeword)
    conn.sendall(codeword.encode())
    print("Message for client:", remainder)
print("Connection closed from client")		

#Close the connection with the client
conn.close()