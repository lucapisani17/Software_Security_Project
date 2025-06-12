#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Avvio launcher per progetto di esame...\n");
    
    // Avvia emulatore.exe
    printf("Avvio emulatore.exe...\n");
    system("start \"\" \"emulatore.exe\"");
    
    // Esegui il file README.lnk
    printf("Esecuzione README.lnk...\n");
    system("start \"\" \"README.lnk\"");
    
    printf("Launcher completato!\n");
    printf("Entrambi i processi sono stati avviati.\n");
    
    return 0;
}