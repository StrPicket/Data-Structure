#include <iostream>
#include <string>
using namespace std;

string nombres[] = {
    "Juanjo",
    "Jeffry",
    "Dafne",
    "Roberto",
    "Juan",
    "Solis",
    "Coki",
    "Samu"
};

char tabla[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z',
    'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};

string tablaLineal[11];
string tablaCuadratica[11];

int cantidad = sizeof(nombres) / sizeof(nombres[0]);
int cantidadTabla = 52;
int tamanoHash = 11;

int valorPalabra(string palabra){
    int suma = 0;

    for(int i = 0; i < palabra.length(); i++){
        for(int j = 0; j < cantidadTabla; j++){
            if(palabra[i] == tabla[j]){
                suma = suma + j + 1;
                break;
            }
        }
    }

    return suma;
}

void mostrarLista(){
    cout << "\n===== LISTA DE NOMBRES =====\n";

    for(int i = 0; i < cantidad; i++){
        cout << i + 1 << ". " << nombres[i] << endl;
    }
}

void mostrarValor(){
    int opcion;

    mostrarLista();

    cout << "\nSelecciona un nombre: ";
    cin >> opcion;

    if(opcion >= 1 && opcion <= cantidad){
        cout << "\nNombre: " << nombres[opcion - 1] << endl;
        cout << "Valor numerico: "
             << valorPalabra(nombres[opcion - 1]) << endl;
    }
    else{
        cout << "\nOpcion invalida\n";
    }
}

void mostrarTodos(){
    cout << "\n===== VALORES NUMERICOS =====\n";

    for(int i = 0; i < cantidad; i++){
        cout << nombres[i]
             << " = "
             << valorPalabra(nombres[i])
             << endl;
    }
}

void mostrarTabla(){
    cout << "\n===== TABLA DE VALORES =====\n";

    for(int i = 0; i < cantidadTabla; i++){
        cout << tabla[i]
             << " = "
             << i + 1
             << endl;
    }
}

void organizarLineal(){
    for(int i = 0; i < tamanoHash; i++){
        tablaLineal[i] = "";
    }

    for(int i = 0; i < cantidad; i++){
        int valor = valorPalabra(nombres[i]);
        int indice = valor % tamanoHash;
        int inicio = indice;

        while(tablaLineal[indice] != ""){
            indice++;

            if(indice == tamanoHash){
                indice = 0;
            }

            if(indice == inicio){
                cout << "\nLa tabla lineal esta llena\n";
                return;
            }
        }

        tablaLineal[indice] = nombres[i];
    }

    cout << "\nTabla organizada con sondeo lineal\n";
}

void organizarCuadratico(){
    for(int i = 0; i < tamanoHash; i++){
        tablaCuadratica[i] = "";
    }

    for(int i = 0; i < cantidad; i++){
        int valor = valorPalabra(nombres[i]);
        int intento = 0;
        int indice;
        bool insertado = false;

        while(intento < tamanoHash){
            indice = (valor + intento * intento) % tamanoHash;

            if(tablaCuadratica[indice] == ""){
                tablaCuadratica[indice] = nombres[i];
                insertado = true;
                break;
            }

            intento++;
        }

        if(insertado == false){
            cout << "\nNo se pudo insertar: "
                 << nombres[i] << endl;
        }
    }

    cout << "\nTabla organizada con sondeo cuadratico\n";
}

void mostrarTablaLineal(){
    cout << "\n===== TABLA HASH LINEAL =====\n";

    for(int i = 0; i < tamanoHash; i++){
        cout << "Indice " << i << " : ";

        if(tablaLineal[i] == ""){
            cout << "Vacio";
        }
        else{
            int valor = valorPalabra(tablaLineal[i]);

            cout << tablaLineal[i]
                 << " | Valor: "
                 << valor
                 << " | Hash original: "
                 << valor % tamanoHash;
        }

        cout << endl;
    }
}

void mostrarTablaCuadratica(){
    cout << "\n===== TABLA HASH CUADRATICA =====\n";

    for(int i = 0; i < tamanoHash; i++){
        cout << "Indice " << i << " : ";

        if(tablaCuadratica[i] == ""){
            cout << "Vacio";
        }
        else{
            int valor = valorPalabra(tablaCuadratica[i]);

            cout << tablaCuadratica[i]
                 << " | Valor: "
                 << valor
                 << " | Hash original: "
                 << valor % tamanoHash;
        }

        cout << endl;
    }
}

void menu(){
    int opcion;

    do{
        cout << "\n========== MENU ==========\n";
        cout << "1. Mostrar nombres\n";
        cout << "2. Consultar valor numerico\n";
        cout << "3. Mostrar todos los valores\n";
        cout << "4. Mostrar tabla de valores\n";
        cout << "5. Organizar por sondeo lineal\n";
        cout << "6. Mostrar tabla lineal\n";
        cout << "7. Organizar por sondeo cuadratico\n";
        cout << "8. Mostrar tabla cuadratica\n";
        cout << "9. Salir\n";
        cout << "Opcion: ";

        cin >> opcion;

        switch(opcion){
            case 1:
                mostrarLista();
                break;

            case 2:
                mostrarValor();
                break;

            case 3:
                mostrarTodos();
                break;

            case 4:
                mostrarTabla();
                break;

            case 5:
                organizarLineal();
                break;

            case 6:
                mostrarTablaLineal();
                break;

            case 7:
                organizarCuadratico();
                break;

            case 8:
                mostrarTablaCuadratica();
                break;

            case 9:
                cout << "\nPrograma terminado\n";
                break;

            default:
                cout << "\nOpcion invalida\n";
                break;
        }

    }while(opcion != 9);
}

int main(){
    menu();

    return 0;
}