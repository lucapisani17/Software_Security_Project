# 🛡️ Software Security Attack Chain – Project

> **Disclaimer:** Questo progetto è stato realizzato a scopo **puramente didattico** nell’ambito del corso di *Software Security*. Non deve essere utilizzato al di fuori di ambienti controllati o per fini illeciti. L’autore non si assume alcuna responsabilità per un uso improprio.

## 🔍 Descrizione del Progetto

Questa repository documenta e implementa una **catena di attacco simulata** che mostra come diversi vettori di minaccia possano essere combinati per compromettere un sistema bersaglio. Il progetto è stato realizzato per approfondire le tecniche offensive nella sicurezza software e comprendere meglio le contromisure difensive.

## 🧪 Panoramica della Catena di Attacco

L'attacco si articola in più fasi, come segue:

1. **Phishing/Inganno Iniziale**
   L'utente vittima viene indotto a visitare una **pagina web malevola** che lo invita a scaricare un falso **gioco eseguibile** (.exe), apparentemente innocuo.

2. **Esecuzione del Payload Iniziale**
   Una volta eseguito l’eseguibile:

   * Si stabilisce una **connessione reverse shell** verso la macchina dell’attaccante.
   * L’attaccante ottiene accesso remoto alla macchina vittima.

3. **Distribuzione dei Malware Secondari**
   Attraverso la reverse shell, l’attaccante inietta ed esegue automaticamente una serie di payload malevoli:

   * 🕷️ **Quasar RAT Client**

     * Controllo remoto persistente
     * Esecuzione comandi, acquisizione dati, sorveglianza
   * ⌨️ **Keylogger**

     * Tracciamento continuo degli input da tastiera
     * Persistente anche dopo il riavvio
   * 🔒 **Encrypter (componente di un Ransomware)**

     * Dormiente fino a comando diretto dell’attaccante
     * Capace di cifrare file selezionati
   * 🐍 **Python Malware – Botnet Node**

     * Trasforma la macchina in un **nodo botnet**
     * Usabile per attacchi **DDoS** distribuiti su comando

## 🧩 Componenti Tecniche

| Componente          | Linguaggio / Tool     | Descrizione                                        |
| ------------------- | --------------------- | -------------------------------------------------- |
| Pagina Web Malevola | HTML / JS / CSS       | Inganna l’utente a scaricare il falso gioco        |
| Executable Game     | Python (PyInstaller)  | Contiene codice per reverse shell                  |
| Reverse Shell       | Netcat / Python       | Stabilisce la connessione remota                   |
| Quasar RAT Client   | .NET / Windows        | Malware già esistente, integrato per scopi di test |
| Keylogger           | Python + WinAPI       | Log degli input da tastiera con avvio automatico   |
| Encrypter           | Python (Cryptography) | Modulo cifratura file, attivabile manualmente      |
| Botnet Node         | Python + socket       | Componente per attacchi DDoS                       |

## ⚙️ Come Eseguire (in ambiente controllato)

> ⚠️ Utilizzare **solo in ambiente di test isolato (es. VM)**.

1. Clona la repository:

   ```bash
   git clone https://github.com/tuo-username/attack-chain-project.git
   cd attack-chain-project
   ```

2. Configura l’ambiente:

   * Installa i requisiti Python: `pip install -r requirements.txt`
   * Prepara il server attaccante (Netcat, listener Quasar, ecc.)
   * Avvia la pagina web su un server locale

3. Simula l’attacco:

   * Fai scaricare il file eseguibile alla vittima
   * Esegui il file dalla macchina bersaglio
   * Osserva l’attacco svilupparsi

## 📁 Struttura della Repository

```
attack-chain-project/
├── malware/
│   ├── keylogger.py
│   ├── encrypter.py
│   └── botnet_node.py
├── quasar/
│   └── QuasarClientSetup.exe
├── web/
│   └── malicious_landing_page.html
├── reverse_shell/
│   └── backdoor.py
├── utils/
│   └── persistence_scripts/
├── README.md
```

## 🎓 Obiettivi Didattici

* Comprendere le tecniche di ingegneria sociale
* Analizzare le metodologie di persistence e privilege escalation
* Simulare una botnet e comprendere il funzionamento di attacchi DDoS
* Studiare i meccanismi di difesa da RAT, ransomware e keylogger

## 🚨 Avvertenze Legali

> Questo progetto è destinato **esclusivamente a scopi educativi**.
> È vietato l’utilizzo su sistemi reali senza autorizzazione esplicita.
> L'autore declina ogni responsabilità per eventuali abusi.

---

