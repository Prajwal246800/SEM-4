import socket
import ssl

# Define the server IP and port
server_ip = '192.168.149.16'  
port = 8000


def read_html_file(filename):
    with open(filename, 'r') as f:
        return f.read()

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.bind((server_ip, port))

server_socket.listen()

print(f"Server is listening on {server_ip}:{port}")

html_filename = "index.html"

context = ssl.create_default_context(ssl.Purpose.CLIENT_AUTH)
context.load_cert_chain(certfile="certificate.crt", keyfile="private.key")

while True:

    client_socket, client_address = server_socket.accept()
    ssl_client_socket = context.wrap_socket(client_socket, server_side=True)

    request = ssl_client_socket.recv(1024).decode()

    # Send the HTML content
    if request.startswith("GET /index.html"):
        # Read the HTML content from the file
        html_content = read_html_file(html_filename)

        # Send the HTTP response with the HTML content
        response = f"HTTP/1.1 200 OK\nContent-Type: text/html\n\n{html_content}"
        ssl_client_socket.sendall(response.encode())
    else:
        response = "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n404 Not Found"
        ssl_client_socket.sendall(response.encode())

    # Close the SSL socket
    ssl_client_socket.close()

server_socket.close()
