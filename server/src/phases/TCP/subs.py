def sub_phase(vars, tcp, subs):
    if "name" not in vars:
        tcp.send("ko: missing name")
    else:
        subs.sub(tcp.conn, vars["name"])
        tcp.send("ok: subbed")

def unsub_phase(vars, tcp, subs):
    if "name" not in vars:
        tcp.send("ko: missing name")
    else:
        subs.unsub(tcp.conn, vars["name"])
        tcp.send("ok: unsubbed")