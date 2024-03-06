import webbrowser

def open_webpage():
    
    server_ip = '10.14.143.190'
    port = 8000  

    # Open the webpage in the default web browser
    url = f'https://{server_ip}:{port}/index.html'  
    webbrowser.open(url, new=2)

if __name__ == '__main__':
    open_webpage()