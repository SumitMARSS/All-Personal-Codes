import socket

# Server configuration
server_ip = "127.0.0.1"
server_port = 12345
buffer_size = 1024

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((server_ip, server_port))

print("UDP server is running...")

# Function to count the number of 1s in binary data
def count_ones(data):
    return data.count('1')

# Continuously receive data from client and send back the count of 1s
while True:
    data, client_address = server_socket.recvfrom(buffer_size)
    data = data.decode('utf-8')

    if data == 'Quit':
        print("Client has ended the session. Closing the server.")
        break

    ones_count = count_ones(data)
    server_socket.sendto(str(ones_count).encode('utf-8'), client_address)

# Close the socket
server_socket.close()
