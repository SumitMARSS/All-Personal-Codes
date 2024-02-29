import socket

# Server configuration
server_ip = "127.0.0.1"
server_port = 12345
buffer_size = 1024

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((server_ip, server_port))

print("UDP server is running...")

# Function to echo characters based on length
def echo_characters(data):
    length = len(data)
    if length % 2 == 0:  # Length is even
        return ''.join(data[i] for i in range(1, length, 2))
    else:  # Length is odd
        return ''.join(data[i] for i in range(0, length, 2))

# Continuously receive and echo messages from client
while True:
    message, client_address = server_socket.recvfrom(buffer_size)
    message = message.decode('utf-8')

    if message.lower() == 'bye':
        print("Client has ended the session. Closing the server.")
        break

    echoed_message = echo_characters(message)
    server_socket.sendto(echoed_message.encode('utf-8'), client_address)

# Close the socket
server_socket.close()
