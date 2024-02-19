import socket
import select
import _thread as thread
import sys
import time
import random

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

if len(sys.argv) != 3:
    print("Print in the following order : script, IP address, port number")
    exit()

IP_address = str(sys.argv[1])
Port = int(sys.argv[2])

server.bind((IP_address, Port))
server.listen(100)

list_of_clients = []

Q = [" What is the Italian word for PIE? \n a.Mozarella b.Pasty c.Patty d.Pizza",
     " Water boils at 212 Units at which scale? \n a.Fahrenheit b.Celsius c.Rankine d.Kelvin",
     " Which sea creature has three hearts? \n a.Dolphin b.Octopus c.Walrus d.Seal",
     " Who was the character famous in our childhood rhymes associated with a lamb? \n a.Mary b.Jack c.Johnny d.Mukesh",
     " How many bones does an adult human have? \n a.206 b.208 c.201 d.196",
     " How many wonders are there in the world? \n a.7 b.8 c.10 d.4",
     " What element does not exist? \n a.Xf b.Re c.Si d.Pa",
     " How many states are there in India? \n a.24 b.29 c.30 d.31",
     " Who invented the telephone? \n a.A.G Bell b.John Wick c.Thomas Edison d.G Marconi",
     " Who is Loki? \n a.God of Thunder b.God of Dwarves c.God of Mischief d.God of Gods",
     " Who was the first Indian female astronaut ? \n a.Sunita Williams b.Kalpana Chawla c.None of them d.Both of them ",
     " What is the smallest continent? \n a.Asia b.Antarctic c.Africa d.Australia",
     " The beaver is the national embelem of which country? \n a.Zimbabwe b.Iceland c.Argentina d.Canada",
     " How many players are on the field in baseball? \n a.6 b.7 c.9 d.8",
     " Hg stands for? \n a.Mercury b.Hulgerium c.Argenine d.Halfnium",
     " Who gifted the Statue of Libery to the US? \n a.Brazil b.France c.Wales d.Germany",
     " Which planet is closest to the sun? \n a.Mercury b.Pluto c.Earth d.Venus"]

A = ['d', 'a', 'b', 'a', 'a', 'a', 'a', 'b', 'a', 'c', 'b', 'd', 'd', 'c', 'a', 'b', 'a']

Count = []
client = ["address", -1]
bzr = [0, 0, 0]

def clientthread(conn, addr):
    conn.send("Hello Genius!!!\n Welcome to this quiz! Answer any 5 questions correctly before your opponents do\n Press any key on the keyboard as a buzzer for the given question\n".encode('utf-8'))
    try:
        while True:
            message = conn.recv(2048)
            if message:
                if bzr[0] == 0:
                    client[0] = conn
                    bzr[0] = 1
                    i = 0
                    while i < len(list_of_clients):
                        if list_of_clients[i] == client[0]:
                            break
                        i += 1
                    client[1] = i
                elif bzr[0] == 1 and conn == client[0]:
                    bol = message[0] == A[bzr[2]][0]
                    print(A[bzr[2]][0])
                    if bol:
                        broadcast("player" + str(client[1]+1) + " +1" + "\n\n")
                        Count[i] += 1
                        if Count[i] == 5:
                            broadcast("player" + str(client[1]+1) + " WON" + "\n")
                            end_quiz()
                            sys.exit()
                    else:
                        broadcast("player" + str(client[1]+1) + " -1" + "\n\n")
                        Count[i] -= 1
                    bzr[0] = 0
                    if len(Q) != 0:
                        Q.pop(bzr[2])
                        A.pop(bzr[2])
                    if len(Q) == 0:
                        end_quiz()
                    quiz()
                else:
                    conn.send(" player " + str(client[1]+1) + " pressed buzzer first\n\n")
    except ConnectionResetError:
        print("Connection with", addr, "reset or closed by client.")
        remove(conn)

def broadcast(message):
    for clients in list_of_clients:
        try:
            clients.send(message.encode('utf-8'))
        except:
            clients.close()
            remove(clients)

def end_quiz():
        broadcast("Game Over\n")
        bzr[1]=1
        i = Count.index(max(Count))
        broadcast("player " + str(i+1)+ " wins!! by scoring "+str(Count[i])+" points.")
        for x in range(len(list_of_clients)):
            list_of_clients[x].send("You scored " + str(Count[x]) + " points.")
            
        server.close()

def quiz():
    bzr[2] = random.randint(0,10000)%len(Q)
    if len(Q) != 0:
        for connection in list_of_clients:
            connection.send(Q[bzr[2]])

def remove(connection):
    if connection in list_of_clients:
        list_of_clients.remove(connection)

while True:
    conn, addr = server.accept()
    list_of_clients.append(conn)
    Count.append(0)
    print(addr[0] + " connected")
    thread.start_new_thread(clientthread,(conn,addr))
    if(len(list_of_clients)==3):
        quiz()
        
conn.close()
server.close()
