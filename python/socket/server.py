import socket

socket_server = socket.socket()
socket_server.bind(("localhost", 8000))
# 接受的连接数量
socket_server.listen(1)
conn, address = socket_server.accept()
print(address)

while True:
    data: str = conn.recv(1024).decode("UTF-8")
    print(data)
    if data == 'exit':
        break
    conn.send("receive over".encode("UTF-8"))
conn.close()
socket_server.close()
