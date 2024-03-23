import socket
import webbrowser

# Define the server IP and port
server_ip = ''  # Loopback address for local testing
port = 8000  # Change the port number if needed

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # Connect to the server
    client_socket.connect((server_ip, port))

    # Send GET request for index.html
    client_socket.sendall(f"GET /index.html HTTP/1.1\r\nHost: {server_ip}:{port}\r\n\r\n".encode())

    # Receive the response from the server
    response = b''
    while True:
        # Receive in chunks of 4096 bytes
        chunk = client_socket.recv(4096)
        if not chunk:
            break
        response += chunk

    # Decode the received bytes to string
    response_str = response.decode()

    print("Received response:")
    print(response_str)  # Print the received response for debugging

    # Save the entire response to a local HTML file
    with open('index.html', 'w') as f:
        f.write(response_str)

    # Open the local HTML file in the default web browser
    webbrowser.open('index.html')

except socket.error as e:
    print(f"Socket error: {e}")

finally:
    # Close the connection
    client_socket.close()
