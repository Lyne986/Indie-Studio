def initialization_phase(vars, tcp, clients):
    print("initialization phase")
    mandatory_fields = ["player", "map", "ia"]
    for k in mandatory_fields:
        if k not in vars:
            tcp.send(f"Error: missing field {k}")
            return
    clients.creates(int(vars["ia"]))
    tcp.send("all good")
