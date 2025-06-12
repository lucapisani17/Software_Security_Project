import socket
import time

C2_HOST = '192.168.1.71'  # IP del tuo computer host 
C2_PORT = 9000

while True:
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((C2_HOST, C2_PORT))
            print(f"[BOT] Connesso a {C2_HOST}:{C2_PORT}")
            while True:
                command = s.recv(1024).decode()
                if command:
                    print(f"[BOT] Ricevuto comando: {command}")
                    if command == "ddos":
                        print("[BOT] Simulazione DDoS")
                    elif command == "exit":
                        break
    except Exception as e:
        print(f"[BOT] Errore: {e}")
    time.sleep(5)
