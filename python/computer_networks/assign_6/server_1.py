import socket

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the port
server_address = ('localhost', 12345)
server_socket.bind(server_address)

print('Server is listening...')

# Receive and display message
while True:
    data, address = server_socket.recvfrom(4096)
    message = data.decode('utf-8')
    print(f"Received message from {address}: {message}")
    
    # Check if the message is "quit" to break the loop
    if message.lower() == "quit":
        print("Client has requested to quit. Closing the server.")
        break

# Close the socket
server_socket.close()
