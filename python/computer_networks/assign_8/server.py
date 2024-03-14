import socket
import threading

# Function to handle client connections
def handle_client(client_socket, address):
    print(f"Accepted connection from {address}")
    while True:
        # Receive data from the client
        data = client_socket.recv(1024)
        if not data:
            break  # If no data is received, break the loop
        
        # Print the received message
        print(f"Received from {address}: {data.decode()}")
        
        # Echo back the received message to the client
        client_socket.sendall(data)
    
    # Close the client socket when done
    client_socket.close()
    print(f"Connection with {address} closed")

# Main function
def main():
    # Server settings
    host = '127.0.0.1'
    port = 12345
    
    # Create a TCP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    # Bind the socket to the host and port
    server_socket.bind((host, port))
    
    # Start listening for incoming connections
    server_socket.listen(5)
    print("Server is listening...")
    
    while True:
        # Accept incoming connection
        client_socket, address = server_socket.accept()
        
        # Create a new thread to handle the client
        client_thread = threading.Thread(target=handle_client, args=(client_socket, address))
        client_thread.start()

# Run the main function
if __name__ == "__main__":
    main()
