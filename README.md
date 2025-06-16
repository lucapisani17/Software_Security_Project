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
| RS Dropper          |                       | DL del payload e stabilimento della connessione    |
| Quasar RAT Client   | .NET / Windows        | Malware già esistente, integrato per scopi di test |
| Keylogger           | C++                   | Log degli input da tastiera con avvio automatico   |
| Encrypter           | C# / .NET             | Modulo cifratura file, attivabile manualmente      |
| Botnet Node         | Python / Docker       | Componente per attacchi DDoS                       |

## ⚙️ Come Eseguire (in ambiente controllato)

> ⚠️ Utilizzare **solo in ambiente di test isolato (es. VM)**.

## 🎓 Obiettivi Didattici

* Comprendere le tecniche di ingegneria sociale
* Esplorare i possibili attacchi possibili dopo aver ottenuto il controllo di una vittima
* Simulare una botnet e comprendere il funzionamento di attacchi DDoS

## 🚨 Avvertenze Legali

> Questo progetto è destinato **esclusivamente a scopi educativi**.
> È vietato l’utilizzo su sistemi reali senza autorizzazione esplicita.
> L'autore declina ogni responsabilità per eventuali abusi.


## 🤙🏻 Realizzato da

> Andrea Bertolero.
> Luca Pisani.

---

