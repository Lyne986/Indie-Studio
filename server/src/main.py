from _thread import *
from tcp_server import init_tcp_server, thread_client
from udp_server import init_udp_server, udp_client

from common_instances import get_all_common_instances

def listen_tcp(tcp_serv, instances):
    while 1:
        client_tcp, addr_tcp = tcp_serv.accept()
        print('Connected to tcp: ' + addr_tcp[0] + ':' + str(addr_tcp[1]))
        start_new_thread(thread_client, (client_tcp, instances))

def listen_udp(udp_serv, instances):
    while 1:
        data, addr_udp = udp_serv.recvfrom(1024)
        print('Connected to udp: ' + addr_udp[0] + ':' + str(addr_udp[1]))
        udp_client(udp_serv, addr_udp, data, instances)

def main():
    fd = open("../.env", "a")
    fd.truncate(0)
    fd.close()
    tcp_serv = init_tcp_server()
    udp_serv = init_udp_server()
    instances = get_all_common_instances()
    start_new_thread(listen_tcp, (tcp_serv, instances))
    start_new_thread(listen_udp, (udp_serv, instances))
    while 1:
        pass

if __name__ == "__main__":
    main()