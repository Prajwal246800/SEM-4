import http.server
import socketserver
import threading
import ssl
class MyHandler(http.server.SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_header('Access-Control-Allow-Origin', '*')  # Cross-Origin Resource Sharing (CORS).
        super().end_headers()

    def do_GET(self):
        if self.path == '/favicon.ico':
            self.send_response(404)
            self.end_headers()
            return
        else:
            super().do_GET()

def start_server():
    handler = MyHandler
    port = 12345
    httpd = socketserver.TCPServer(('192.168.255.15', port), handler)

    # Load the SSL certificate and private key using SSLContext
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    context.load_cert_chain("server.crt", "server.key")

    httpd.socket = context.wrap_socket(httpd.socket, server_side=True)

    print(f'Server listening on https://10.14.143.190:{port}')

    threading.Thread(target=httpd.serve_forever).start()

if __name__ == '__main__':
    start_server()


'''
    Python script creates a simple HTTP server that serves files from the current directory 
    and allows cross-origin resource sharing (CORS) for all requests. 
    Let's break down the code:
        1. Imports: The script imports necessary modules:
            * http.server: This module provides basic classes for implementing web servers.
            * socketserver: This module provides a framework for network servers.
            * threading: This module provides classes and functions for working with threads.
            * ssl: This module provides access to SSL (Secure Socket Layer) cryptographic services.
        2. Custom Handler: The script defines a custom handler class MyHandler, 
                            which inherits from http.server.SimpleHTTPRequestHandler. 
                            This handler overrides the end_headers() method 
                            to include an 'Access-Control-Allow-Origin' header with a value of '*' 
                            (allowing requests from any origin). Additionally, 
                            it overrides the do_GET() method to handle GET requests. 
                            If the request path is '/favicon.ico', it sends a 404 response; 
                            otherwise, it calls the parent class method to handle the request.
        3. start_server() Function: This function sets up and starts the HTTP server. 
                            It creates an instance of the custom handler, 
                            specifies the IP address and port to listen on (10.1.1.8 and port 12345 in this case), 
                            and creates a socketserver.TCPServer object.
        4. SSL Configuration: The script loads SSL certificate and private key files using the ssl.SSLContext class. 
                            It then wraps the server socket with SSL encryption using the loaded certificate and key.
        5. Server Start: The script starts the server by calling httpd.serve_forever() in a separate thread using threading.Thread.
        6. Main Block: Finally, the script checks if it's being run as the main program (not imported as a module) and 
                            calls the start_server() function accordingly.
'''