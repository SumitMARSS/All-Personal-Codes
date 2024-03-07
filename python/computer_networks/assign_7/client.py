import socket

port=50000
portClient=8000
host="127.0.0.1"

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.bind((host, portClient))
client.connect((host, port))
while True:	
	data1 = input("Enter your message of data: ")
	key = input("Enter You key: ")
	data1 += ','
	data1 += key
	client.send(data1.encode())
	if data1 =='Quit':
		break
	recieved_data =  client.recv(2048).decode()
	print("CodeWord from server: ", recieved_data)
print("Connection closed from server")
client.close()