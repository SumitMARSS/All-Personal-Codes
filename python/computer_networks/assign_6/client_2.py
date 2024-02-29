import socket

# Server configuration
server_ip = "127.0.0.1"
server_port = 12345
buffer_size = 1024

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Function to take user input and send message to server
def send_message():
    while True:
        message = input("Enter message to send to server ('bye' to quit): ")
        client_socket.sendto(message.encode('utf-8'), (server_ip, server_port))

        if message.lower() == 'bye':
            print("Closing the client.")
            break

        response, _ = client_socket.recvfrom(buffer_size)
        print("Echoed message from server:", response.decode('utf-8'))

# Send messages to server
send_message()

# Close the socket
client_socket.close()
