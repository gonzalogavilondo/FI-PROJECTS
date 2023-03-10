Algoritmo parcial_01
	// Declaraciones
	Definir FILAS, COLUMNAS Como Entero
	FILAS <- 3
	COLUMNAS <- 3
	Definir matriz1, matriz2, idx_fila, idx_columna, aux Como Entero
	Dimension matriz1[FILAS, COLUMNAS]
	Dimension matriz2[FILAS, COLUMNAS]
	idx_fila <- 0
	idx_columna <- 0
	aux <- 0
	
	// Cargar valores en cada matriz
	cargar_matriz(matriz1, idx_fila, idx_columna, 1)
	cargar_matriz(matriz2, idx_fila, idx_columna, 2)
	
	// Procesar las matrices
	procesar_matriz(matriz1, matriz2, idx_fila, idx_columna, aux)
	
	// Mostrar resultados
	mostrar_resultados(matriz1, idx_fila, idx_columna, 1)
	mostrar_resultados(matriz2, idx_fila, idx_columna, 2)
	
FinAlgoritmo

Funcion  cargar_matriz (matriz, idx_fila, idx_columna, identificador)
	Definir FILAS, COLUMNAS Como Entero
	FILAS <- 3
	COLUMNAS <- 3
	Escribir "Leer valores de la matriz ",identificador,""
	Para idx_fila<-0 Hasta FILAS-1 Hacer
		Para idx_columna<-0 Hasta COLUMNAS-1 Hacer
			Escribir "Ingrese el elemento [", idx_fila + 1, ",", idx_columna + 1, "] " Sin Saltar
			Leer matriz[idx_fila, idx_columna]
		FinPara
	FinPara
	
Fin Funcion

Funcion procesar_matriz(matriz1, matriz2, idx_fila, idx_columna, aux)
	Definir FILAS, COLUMNAS Como Entero
	FILAS <- 3
	COLUMNAS <- 3
	Para idx_fila<-0 Hasta FILAS-1 Hacer
		Para idx_columna<-0 Hasta COLUMNAS-1 Hacer
			Si idx_fila > idx_columna Entonces
				aux <- matriz1[idx_fila, idx_columna]
				matriz1[idx_fila, idx_columna] <- matriz2[idx_columna, idx_fila]
				matriz2[idx_columna, idx_fila] <- aux
			FinSi
		FinPara
	FinPara
	
Fin Funcion

Funcion  mostrar_resultados (matriz, idx_fila, idx_columna, identificador)
	Definir FILAS, COLUMNAS Como Entero
	FILAS <- 3
	COLUMNAS <- 3
	Escribir "Matriz ",identificador," procesada"
	Para idx_fila<-0 Hasta FILAS-1 Hacer
		Escribir "|   " Sin Saltar
		Para idx_columna<-0 Hasta COLUMNAS-1 Hacer
			Escribir matriz[idx_fila, idx_columna], "   " Sin Saltar
		FinPara
		Escribir "|"
	FinPara
	
Fin Funcion
