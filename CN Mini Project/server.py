import socket

# Define the server IP and port
server_ip = ''  # Loopback address for local testing
port = 8000

# Function to read HTML file content
def read_html_file(filename):
    with open(filename, 'r') as f:
        return f.read()

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the IP and port
server_socket.bind((server_ip, port))

# Listen for incoming connections
server_socket.listen()

print(f"Server is listening on {server_ip}:{port}")

# Path to the HTML file to serve
html_filename = "index.html"

while True:
    # Accept a new connection
    client_socket, client_address = server_socket.accept()

    # Receive client's request
    request = client_socket.recv(1024).decode()

    # Send the HTML content
    if request.startswith("GET /index.html"):
        # Read the HTML content from the file
        html_content = read_html_file(html_filename)

        # Send the HTTP response with the HTML content
        response = f"HTTP/1.1 200 OK\nContent-Type: text/html\n\n{html_content}"
        client_socket.sendall(response.encode())
    else:
        # Send 404 Not Found if the request is for something else
        response = "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n404 Not Found"
        client_socket.sendall(response.encode())

    # Close the connection
    client_socket.close()