class UDP:

    def __init__(self, conn, addr):
        self.conn = conn
        self.addr = addr

    def send(self, message):
        self.conn.sendto(message.encode("utf-8"), self.addr)
