import socket

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Server address
server_address = ('localhost', 12345)

# Take user input for message
while True:
    message = input("Enter message to send to server (type 'quit' to exit): ")
    
    # Send message to server
    client_socket.sendto(message.encode('utf-8'), server_address)
    
    # Check if the user wants to quit
    if message.lower() == "quit":
        break

# Close the socket
client_socket.close()
