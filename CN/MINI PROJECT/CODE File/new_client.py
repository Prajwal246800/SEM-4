import socket
import ssl
import webbrowser

# Define the server IP and port
server_ip = '' 
port = 8000

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# SSL Context
context = ssl.create_default_context(ssl.Purpose.SERVER_AUTH)
context.check_hostname = False 
context.verify_mode = ssl.CERT_NONE

try:
    ssl_client_socket = context.wrap_socket(client_socket, server_hostname=server_ip)

    ssl_client_socket.connect((server_ip, port))

    # Send GET request for index.html
    ssl_client_socket.sendall(f"GET /index.html HTTP/1.1\r\nHost: {server_ip}:{port}\r\n\r\n".encode())

    response = b''
    while True:
        chunk = ssl_client_socket.recv(4096)
        if not chunk:
            break
        response += chunk


    response_str = response.decode()

    print("Received response:")
    print(response_str) 

    with open('index.html', 'w') as f:
        f.write(response_str)

    webbrowser.open('index.html')

except socket.error as e:
    print(f"Socket error: {e}")

finally:
    # Close the SSL socket
    ssl_client_socket.close()
