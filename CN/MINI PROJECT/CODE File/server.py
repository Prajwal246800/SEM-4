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
    httpd = socketserver.TCPServer(('192.168.119.15', port), handler)

    # Load the SSL certificate and private key using SSLContext
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    context.load_cert_chain("server.crt", "server.key")

    httpd.socket = context.wrap_socket(httpd.socket, server_side=True)

    print(f'Server listening on https://10.14.143.190:{port}')

    threading.Thread(target=httpd.serve_forever).start()

if __name__ == '__main__':
    start_server()