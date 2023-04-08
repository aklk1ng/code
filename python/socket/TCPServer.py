import socket

socket_server = socket.socket()
socket_server.bind(("localhost", 11000))
socket_server.listen(1)

conn, address = socket_server.accept()
print(address)

while True:
    data: str = conn.recv(1024).decode("UTF-8")
    print(data)
    if data == 'exit':
        conn.send(data.encode("UTF-8"))
        # close one connection
        conn.close()
        break
    conn.send("receive over".encode("UTF-8"))
# close the server connection
socket_server.close()
