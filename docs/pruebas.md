# CASOS DE PRUEBA MÍNIMOS - SISTEMA DE CAJA 2026

## Caso 1: Límite de Descuento (Sin descuento vs 5%)
- **Entrada:** Producto 1 -> Precio: Q99.99, Cantidad: 1. Precio: 0 (Terminar).
- **Resultado esperado:** Subtotal Q99.99, Descuento Q0.00, IVA Q12.00, Total Q111.99.
- **Entrada 2:** Producto 1 -> Precio: Q100.00, Cantidad: 1. Precio: 0 (Terminar).
- **Resultado esperado:** Subtotal Q100.00, Descuento Q5.00, IVA Q11.40, Total Q106.40.

## Caso 2: Límite de Descuento (10%)
- **Entrada:** Producto 1 -> Precio: Q500.00, Cantidad: 1. Precio: 0 (Terminar).
- **Resultado esperado:** Subtotal Q500.00, Descuento Q50.00, IVA Q54.00, Total Q504.00.

## Caso 3: Validaciones de Cantidad, Precio y Menú
- **Entrada:** Menú opción "9" -> Esperado: Mensaje de error.
- **Entrada:** Ingresar precio -10 -> Esperado: Mensaje de error.
- **Entrada:** Ingresar cantidad 0 -> Esperado: Mensaje de error.
- **Entrada:** Ingresar cantidad 101 -> Esperado: Mensaje de error.

## Caso 4: Resumen del Día sin Ventas
- **Entrada:** Menú opción 2 (Antes de registrar cualquier venta).
- **Resultado esperado:** Mensaje en pantalla: "Aun no se han registrado ventas el dia de hoy."

## Caso 5: Pago Menor al Total
- **Entrada:** Registrar una venta de Q100. Intentar pagar con Q50.
- **Resultado esperado:** Mensaje de error indicando que el monto es insuficiente y solicita el pago de nuevo.
