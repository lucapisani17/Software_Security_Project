import socket

HOST = '0.0.0.0'
PORT = 9999

LOG_FILE = "/logs/target.log"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
    server.bind((HOST, PORT))
    server.listen()
    print(f"[TARGET] In ascolto su {HOST}:{PORT}")

    with open(LOG_FILE, "a") as log:
        while True:
            conn, addr = server.accept()
            with conn:
                data = conn.recv(1024)
                message = f"[TARGET] Ricevuto da {addr}: {data.decode()}\n"
                print(message.strip())
                log.write(message)
                log.flush()
