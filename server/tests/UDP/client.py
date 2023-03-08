import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.connect(('127.0.0.1', 5005))

while 1:
    a = input("Command : ")
    try:
        if a == "init":
            # Initialization phase All good
            print("initialization all good")
            s.sendall(b"phase=init;player=2;ia=4;map=3")
            data, _ = s.recvfrom(1024)
            print(data)

        elif a == "listen":
            data, _ = s.recvfrom(1024)
            print(data)

        elif a == "sub":
            s.sendall(b"phase=sub;name=lobby")
            data, _ = s.recvfrom(1024)
            print(data)

        elif a == "stop":
            break

    except Exception as e:
        print("ERROR")
        print(str(e))
        break
s.close()