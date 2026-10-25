#include <iostream>

using namespace std;

int main() {
    int opcion;
    opcion = 0;
    
    int totalVentas;
    totalVentas = 0;
    
    double totalDineroDia;
    totalDineroDia = 0;
    
    double totalDescuentosDia;
    totalDescuentosDia = 0;
    
    double ventaMayor;
    ventaMayor = -1;
    
    double ventaMenor;
    ventaMenor = -1;
    
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
            
            double descuento;
            descuento = 0;
            
            if (subtotal < 100) {
                descuento = 0;
            }
            if (subtotal >= 100 && subtotal < 500) {
                descuento = subtotal * 0.05;
            }
            if (subtotal >= 500) {
                descuento = subtotal * 0.10;
            }
            
            double montoConDescuento;
            montoConDescuento = subtotal - descuento;
            
            double iva;
            iva = montoConDescuento * 0.12;
            
            double totalAPagar;
            totalAPagar = montoConDescuento + iva;
            
            double pagoCliente;
            cout << "\nTotal a pagar (con IVA): Q" << totalAPagar << endl;
            cout << "Ingrese el monto recibido del cliente: Q";
            cin >> pagoCliente;
            
            while (pagoCliente < totalAPagar) {
                cout << "Error: El monto recibido es menor al total a pagar." << endl;
                cout << "Ingrese el monto recibido del cliente: Q";
                cin >> pagoCliente;
            }
            
            double cambio;
            cambio = pagoCliente - totalAPagar;
            
            cout << "\n--- RECIBO DE VENTA ---" << endl;
            cout << "Subtotal: Q" << subtotal << endl;
            cout << "Descuento otorgado: Q" << descuento << endl;
            cout << "IVA (12%): Q" << iva << endl;
            cout << "Total final: Q" << totalAPagar << endl;
            cout << "Pago del cliente: Q" << pagoCliente << endl;
            cout << "Cambio: Q" << cambio << endl;
            
            totalVentas = totalVentas + 1;
            totalDineroDia = totalDineroDia + totalAPagar;
            totalDescuentosDia = totalDescuentosDia + descuento;
            
            if (ventaMayor == -1 || totalAPagar > ventaMayor) {
                ventaMayor = totalAPagar;
            }
            if (ventaMenor == -1 || totalAPagar < ventaMenor) {
                ventaMenor = totalAPagar;
            }
        }
        
        if (opcion == 2) {
            cout << "\n--- RESUMEN PARCIAL DEL DIA ---" << endl;
            if (totalVentas == 0) {
                cout << "Aun no se han registrado ventas el dia de hoy." << endl;
            } else {
                double promedio;
                promedio = totalDineroDia / totalVentas;
                
                cout << "Numero de ventas realizadas: " << totalVentas << endl;
                cout << "Total de dinero vendido: Q" << totalDineroDia << endl;
                cout << "Venta de mayor valor: Q" << ventaMayor << endl;
                cout << "Venta de menor valor: Q" << ventaMenor << endl;
                cout << "Promedio por venta: Q" << promedio << endl;
                cout << "Total de descuentos otorgados: Q" << totalDescuentosDia << endl;
            }
        }
        
        if (opcion == 3) {
            cout << "Cerrando caja... ¡Feliz dia!" << endl;
        }
    }
    
    return 0;
}
