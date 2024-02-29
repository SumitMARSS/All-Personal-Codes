import socket

# Server configuration
server_ip = "127.0.0.1"
server_port = 12345
buffer_size = 1024

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Function to send binary data to the server
def send_data(data):
    client_socket.sendto(data.encode('utf-8'), (server_ip, server_port))

    response, _ = client_socket.recvfrom(buffer_size)
    print("Number of 1s in data received from server:", response.decode('utf-8'))

# Send binary data to the server until 'Quit' is sent
while True:
    data = input("Enter binary values to send to server ('Quit' to exit): ")
    
    if data == 'Quit':
        print("Closing the client.")
        send_data(data)
        break

    send_data(data)

# Close the socket
client_socket.close()
