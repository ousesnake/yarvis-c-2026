#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Convierte texto a minúsculas (compatible C clásico)
void aMinusculas(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
    }
}
void mostrarAyuda() {
    cout << "\nComandos disponibles:\n";
    cout << "  ayuda      -> muestra esta lista\n";
    cout << "  hora       -> muestra hora actual\n";
    cout << "  fecha      -> muestra fecha actual\n";
    cout << "  limpiar    -> limpia pantalla\n";
    cout << "  dir        -> lista archivos (DOS)\n";
    cout << "  salir      -> cierra YARVIS\n";
}
void mostrarHora() {
    struct time t;
    gettime(&t);
    cout << "Hora actual: ";
    if (t.ti_hour < 10) cout << "0";
    cout << t.ti_hour << ":";
    if (t.ti_min < 10) cout << "0";
    cout << t.ti_min << ":";
    if (t.ti_sec < 10) cout << "0";
    cout << t.ti_sec << "\n";
}
void mostrarFecha() {
    struct date d;
    getdate(&d);
    cout << "Fecha actual: ";
    if (d.da_day < 10) cout << "0";
    cout << d.da_day << "/";
    if (d.da_mon < 10) cout << "0";
    cout << d.da_mon << "/" << d.da_year << "\n";
}
int main() {
    char comando[80];
    clrscr();
    cout << "=====================================\n";
    cout << "      YARVIS - Sistema de Consola    \n";
    cout << "      Borland C++ (sin graficos)     \n";
    cout << "=====================================\n";
    cout << "Escribe 'ayuda' para ver comandos.\n";
    while (1) {
        cout << "\nYARVIS> ";
        cin.getline(comando, 79);
        aMinusculas(comando);
        if (strcmp(comando, "ayuda") == 0) {
            mostrarAyuda();
        }
        else if (strcmp(comando, "hora") == 0) {
            mostrarHora();
        }
        else if (strcmp(comando, "fecha") == 0) {
            mostrarFecha();
        }
        else if (strcmp(comando, "limpiar") == 0) {
            clrscr();
        }
        else if (strcmp(comando, "dir") == 0) {
            system("dir");
        }
        else if (strcmp(comando, "salir") == 0) {
            cout << "Cerrando YARVIS...\n";
            break;
        }
        else if (strlen(comando) == 0) {
            // No hacer nada si está vacío
        }
        else {
            cout << "Comando no reconocido. Escribe 'ayuda'.\n";
        }
    }
    return 0;
}
