#include <iostream>

using namespace std;

int main() {
    int opcion;
    opcion = 0;
    
    while (opcion != 3) {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Ver resumen parcial del dia" << endl;
        cout << "3. Cerrar caja y salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        if (opcion < 1 || opcion > 3) {
            cout << "Error: Opcion invalida. Intente de nuevo." << endl;
        }
        
        if (opcion == 1) {
            double subtotal;
            subtotal = 0;
            
            double precio;
            precio = -1;
            
            cout << "\n--- NUEVA VENTA (Ingrese precio 0 para terminar) ---" << endl;
            
            while (precio != 0) {
                cout << "Ingrese precio unitario del producto: Q";
                cin >> precio;
                
                while (precio < 0) {
                    cout << "Error: El precio no puede ser negativo." << endl;
                    cout << "Ingrese precio unitario del producto: Q";
                    cin >> precio;
                }
                
                if (precio != 0) {
                    int cantidad;
                    cout << "Ingrese la cantidad (1-100): ";
                    cin >> cantidad;
                    
                    while (cantidad < 1 || cantidad > 100) {
                        cout << "Error: La cantidad debe estar entre 1 y 100." << endl;
                        cout << "Ingrese la cantidad (1-100): ";
                        cin >> cantidad;
                    }
                    
                    subtotal = subtotal + (precio * cantidad);
                }
            }
            
            cout << "\nSubtotal de la venta actual: Q" << subtotal << endl;
        }
        
        if (opcion == 2) {
            cout << "\n--- RESUMEN PARCIAL ---" << endl;
            cout << "Proximamente en el Hito 2." << endl;
        }
        
        if (opcion == 3) {
            cout << "Cerrando caja... ¡Feliz dia!" << endl;
        }
    }
    
    return 0;
}
