import socket
from urllib.parse import urlparse
from bs4 import BeautifulSoup
import requests

#import socket

port=50000
host="127.0.0.1"

server= socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((host, port))
print("socket binded to %s" %(port))

server.listen(2)
print("Socket is listening...")

# Accepting/Establishing connection from client.
conn, addr = server.accept()        
print('Got connection from', addr)

def web_crawler(url, depth):
    visited = set()
    to_visit = [(url, 0)]
    results = []

    while to_visit:
        current_url, current_depth = to_visit.pop(0)

        if current_url in visited or current_depth > depth:
            continue

        visited.add(current_url)
        print(current_url)
        results.append(current_url)

        try:
            response = requests.get(current_url)
            soup = BeautifulSoup(response.text, 'html.parser')

            for link in soup.find_all('a'):
                next_url = link.get('href')
                if next_url and next_url.startswith('http'):
                    to_visit.append((next_url, current_depth + 1))
        except Exception as e:
            print(f"Error crawling {current_url}: {e}")

    return results

while True:
    recieved_data=conn.recv(2048)
    
    if recieved_data.decode()=='Quit':
        break
    url, depth = recieved_data.decode().split(',')
    depth = int(depth)	
    print(f"Received URL: {url}, Depth: {depth}")

    crawled_urls = web_crawler(url, depth)
    response_data = '\n'.join(crawled_urls)
    conn.sendall(response_data.encode())
 
#Close the connection with the client
conn.close()