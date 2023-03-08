def lobby_phase(vars, tcp, lobby, subs):
    for i in vars:
        if i == "command":
            if vars[i] == "create game":
                lobby.create(vars["name"], vars["creator"])
                tcp.send("game created")
                subs.send_to_subs(lobby.get_parties_serialized(), "lobby")