import socket

from Sockets.TCP import TCP
from check_message import parsing_message
from phases.TCP.initialization import initialization_phase
from phases.TCP.lobby import lobby_phase
from phases.TCP.subs import sub_phase, unsub_phase

def checking_phase(ret, tcp, instances):
    clients, game, subs, lobby = instances
    if ret["phase"] == "init":
        initialization_phase(ret["vars"], tcp, clients)
    elif ret["phase"] == "lobby":
        lobby_phase(ret["vars"], tcp, lobby, subs)
    elif ret["phase"] == "sub":
        sub_phase(ret["vars"], tcp, subs)
    elif ret["phase"] == "unsub":
        unsub_phase(ret["vars"], tcp, subs)

def thread_client(client, instances):
    try:
        tcp = TCP(client)
        running = True
        while running:
            data = tcp.listen()
            if data is None:
                running = False
            else:
                ret = parsing_message(data)
                if ret["phase"] == "exit":
                    running = False
                    tcp.close()
                else:
                    checking_phase(ret, tcp, instances)
    except Exception as e:
        print("Error")
        print(e)
        tcp.close()

def init_tcp_server():
    server_side_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    port = 5005
    ip = "0.0.0.0"
    connected = False
    while not connected:
        try:
            server_side_socket.bind((ip, port))
            connected = True
        except:
            port += 1
    fd = open("../.env", "a")
    fd.write(f"TCP_PORT={port}\n")
    fd.close()
    server_side_socket.listen(5)
    print("Server tcp, bind in", ip, port)
    return server_side_socket
