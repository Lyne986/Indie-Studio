def check_missing_keys(vars, keys, conn):
    for i in keys:
        if i not in vars:
            conn.send(f"ko: missing key: {i}")
            return True
    return False

def game_phase(vars, conn, subs):
    if check_missing_keys(vars, ["event", "gid"], conn):
        return
    if vars["event"] == "bomb placed":
        if check_missing_keys(vars, ["x", "y", "z"], conn):
            return
        x=vars["x"]
        y=vars["y"]
        z=vars["z"]
        subs.send_to_all(f"bomb_placed:{x}:{y}:{z}", vars["gid"])
    elif vars["event"] == "player moved":
        x=vars["x"]
        y=vars["y"]
        z=vars["z"]
        subs.send_to_all(f"player_moved:{x}:{y}:{z}", vars["gid"])