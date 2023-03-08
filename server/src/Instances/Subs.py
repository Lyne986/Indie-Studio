class Subs:

    def __init__(self):
        self.subs = {}

    def sub(self, conn, sub, mode="tcp"):
        if mode == "tcp":
            if sub in self.subs:
                self.subs[sub]["tcp"].append(conn)
            else:
                self.subs[sub] = {
                    "tcp": [conn],
                    "udp": []
                }
        elif mode == "udp":
            if sub in self.subs:
                self.subs[sub]["udp"].append(conn)
            else:
                self.subs[sub] = {
                    "tcp": [],
                    "udp": [conn]
                }

    def unsub(self, conn, sub, mode="tcp"):
        if mode == "tcp":
            self.subs[sub]["tcp"].remove(conn)
        elif mode == "udp":
            self.subs[sub]["udp"].remove(conn)

    def send_to_subs(self, message, sub_name):
        if sub_name in self.subs:
            for conn in self.subs[sub_name]["tcp"]:
                conn.send(message.encode("utf-8"))
            for conn in self.subs[sub_name]["udp"]:
                conn.send(message)
        else:
            print(f"sub not found {sub_name}")
