import socket

serverPort = 12000
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverSocket.bind(('127.0.0.1', serverPort))

print("The server is ready to receive")

while True:
  message, clientAddress = serverSocket.recvfrom(2048)
  print(message.decode())
  modifiedMessage = message.decode().upper()
  serverSocket.sendto(modifiedMessage.encode(), clientAddress)
