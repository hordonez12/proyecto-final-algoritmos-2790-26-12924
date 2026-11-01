#include <iostream>

using namespace std;

int main() {
    int opc = 0;
    
    // Variables para el reporte del final
    int conteoVentas = 0;
    double dineroTotal = 0;
    double descuentosTotal = 0;
    double vMayor = -1;
    double vMenor = -1;
    
    while (opc != 3) {
        cout << "\n=== TIENDITA DE BARRIO - CAJA ===" << endl;
        cout << "1) Registrar una venta" << endl;
        cout << "2) Ver resumen del dia" << endl;
        cout << "3) Salir del programa" << endl;
        cout << "Elija una opcion: ";
        cin >> opc;
        
        if (opc < 1 || opc > 3) {
            cout << "Opcion no valida, intente otra vez..." << endl;
        }
        
        if (opc == 1) {
            double sub = 0;
            double pre = -1;
            
            cout << "\n--- NUEVA COMPRA (coloque precio 0 para cerrar la cuenta) ---" << endl;
            
            while (pre != 0) {
                cout << "Precio del producto: Q";
                cin >> pre;
                
                while (pre < 0) {
                    cout << "El precio no puede ser menor a cero. Ponga otra vez: Q";
                    cin >> pre;
                }
                
                if (pre != 0) {
                    int cant;
                    cout << "Cantidad de unidades: ";
                    cin >> cant;
                    
                    while (cant < 1 || cant > 100) {
                        cout << "Cantidad incorrecta (debe ser de 1 a 100). Ponga otra vez: ";
                        cin >> cant;
                    }
                    
                    sub = sub + (pre * cant);
                }
            }
            
            // Calculo de los descuentos manuales
            double desc = 0;
            if (sub < 100) {
                desc = 0;
            }
            if (sub >= 100 && sub < 500) {
                desc = sub * 0.05;
            }
            if (sub >= 500) {
                desc = sub * 0.10;
            }
            
            double subConDesc = sub - desc;
            double impuestoIva = subConDesc * 0.12;
            double totalNeto = subConDesc + impuestoIva;
            
            double pago = 0;
            cout << "\nTotal neto a pagar: Q" << totalNeto << endl;
            cout << "Efectivo recibido: Q";
            cin >> pago;
            
            while (pago < totalNeto) {
                cout << "Dinero insuficiente. Falta dinero. Ingrese de nuevo: Q";
                cin >> pago;
            }
            
            double vuelto = pago - totalNeto;
            
            // Impresion de la factura sencilla
            cout << "\n****** RECUERDO DE SU COMPRA ******" << endl;
            cout << "Subtotal de los productos: Q" << sub << endl;
            cout << "Descuento aplicado: Q" << desc << endl;
            cout << "Impuesto IVA cobrado: Q" << impuestoIva << endl;
            cout << "TOTAL FINAL: Q" << totalNeto << endl;
            cout << "Usted pago con: Q" << pago << endl;
            cout << "Su cambio es: Q" << vuelto << endl;
            cout << "***********************************" << endl;
            
            // Guardar datos para el reporte
            conteoVentas = conteoVentas + 1;
            dineroTotal = dineroTotal + totalNeto;
            descuentosTotal = descuentosTotal + desc;
            
            if (vMayor == -1 || totalNeto > vMayor) {
                vMayor = totalNeto;
            }
            if (vMenor == -1 || totalNeto < vMenor) {
                vMenor = totalNeto;
            }
        }
        
        if (opc == 2) {
            cout << "\n====== REPORTE DE CAJA ======" << endl;
            if (conteoVentas == 0) {
                cout << "Aun no se han registrado ventas el dia de hoy." << endl;
            } else {
                double prom = dineroTotal / conteoVentas;
                cout << "Ventas cobradas: " << conteoVentas << endl;
                cout << "Dinero total en caja: Q" << dineroTotal << endl;
                cout << "Venta mas alta: Q" << vMayor << endl;
                cout << "Venta mas baja: Q" << vMenor << endl;
                cout << "Promedio por cliente: Q" << prom << endl;
                cout << "Total de descuentos dados: Q" << descuentosTotal << endl;
            }
            cout << "=============================" << endl;
        }
        
        if (opc == 3) {
            cout << "Saliendo del sistema de caja... Adios." << endl;
        }
    }
    
    return 0;
}
