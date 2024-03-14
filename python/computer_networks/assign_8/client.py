import socket

# Main function
def main():
    # Server settings
    host = '127.0.0.1'
    port = 12345
    
    # Create a TCP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    # Connect to the server
    client_socket.connect((host, port))
    
    while True:
        # Send a message to the server
        message = input("Enter message: ")
        if(message == 'Quit'):
            break
        client_socket.send(message.encode())
        
        # Receive a response from the server
        response = client_socket.recv(1024).decode()
        print("Server response:", response)
    
    # Close the connection
    client_socket.close()

# Run the main function
if __name__ == "__main__":
    main()
