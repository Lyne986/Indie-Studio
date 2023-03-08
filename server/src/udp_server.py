import socket
from Sockets.UDP import UDP
from check_message import parsing_message
from phases.UDP.game import game_phase

def check_phase(ret, instances, conn):
    clients, game, subs, lobby = instances
    if ret["phase"] == "sub":
        subs.sub(conn, ret["vars"]["name"], "udp")
        conn.send("subbed")
    if ret["phase"] == "game":
        game_phase(ret["vars"], conn, subs)

def udp_client(server, addr, data, instances):
    try:
        udp = UDP(server, addr)
        ret = parsing_message(data)
        check_phase(ret, instances, udp)
    except Exception as e:
        print("Error")
        print(e)
        server.close()

def init_udp_server():
        server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        port = 5005
        ip = "127.0.0.1"
        connected = False
        while not connected:
            try:
                server.bind((ip, port))
                connected = True
            except:
                port += 1
        fd = open("../.env", "a")
        fd.write(f"UDP_PORT={port}\n")
        fd.close()
        print("Server udp, bind in", ip, port)
        return server
