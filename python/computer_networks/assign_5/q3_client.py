import socket

port=50000
portClient=8000
host="127.0.0.1"

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.bind((host, portClient))
client.connect((host, port))
#server_address = ('127.0.0.1', 12345)

while True:
    url = input("Enter URL: ")
    if url.lower() == 'quit':
        client.sendall('Quit'.encode())
        break

    depth = input("Enter depth: ")

    message = f"{url},{depth}"
    client.sendall(message.encode())

    response = client.recv(4096).decode()
    print("Crawled URLs:")
    print(response)

client.close()