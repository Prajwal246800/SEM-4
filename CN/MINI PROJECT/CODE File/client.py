import webbrowser

def open_webpage():
    
    server_ip = '10.14.143.190'
    port = 8000  

    # Open the webpage in the default web browser
    url = f'https://{server_ip}:{port}/index.html'  
    webbrowser.open(url, new=2)

if __name__ == '__main__':
    open_webpage()

'''
    1. Import: The script imports the webbrowser module, 
                which provides a high-level interface to display web-based documents to users.
    2. open_webpage() Function: This function is defined to open a webpage in the default web browser. 
                It does the following:
                    Defines the server's IP address (server_ip) and port number (port) where the webpage is hosted.
                    Constructs the URL for the webpage to be opened. 
                    The URL is formed using the HTTPS protocol and includes the server's IP address and port number, 
                    as well as the specific page (index.html) to be opened.
                    Uses the webbrowser.open() function to open the constructed URL in the default web browser. 
                    The new=2 argument specifies to open the URL in a new tab, if possible.
    3. Main Block: The script checks if it's being run as the main program (not imported as a module) 
                and calls the open_webpage() function accordingly.
'''