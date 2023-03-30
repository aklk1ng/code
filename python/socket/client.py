import socket

socket_client = socket.socket()
socket_client.connect(("localhost", 8000))
while True:
  send_msg = input("Please Enter The Message:").encode("UTF-8")
  socket_client.send(send_msg)
  recev_data = socket_client.recv(1024)
  if recev_data.decode("UTF-8") == 'close':
    print("the connection will be closed!")
    break
  print(recev_data.decode("UTF-8"))
socket_client.close()
