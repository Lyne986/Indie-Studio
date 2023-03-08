import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 5005))

while 1:
    a = input("Command : ")
    try:
        if a == "sub":
            s.send(b"phase=sub;name=lobby")
            data = s.recv(1024)
            print(data)

        if a == "unsub":
            s.send(b"phase=unsub;name=lobby")
            data = s.recv(1024)
            print(data)

        if a == "create":
            s.send(b"phase=lobby;command=create game;name=partie 1;creator=Nini")
            data = s.recv(1024)
            print(data)

        if a == "listen":
            data = s.recv(1024)
            print(data)

        elif a == "stop":
            break

    except:
        break
s.close()

            # s.sendall(b"phase=init;player=2;ia=4;map=3")
            # data = s.recv(1024)
            # print(data)
            # data = s.recv(1024)
            # print(data)
