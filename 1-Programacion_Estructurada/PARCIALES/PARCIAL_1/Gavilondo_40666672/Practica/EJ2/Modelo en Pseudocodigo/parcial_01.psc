Algoritmo parcial_01
	// Declaraciones
	Definir FILAS, COLUMNAS Como Entero
	FILAS <- 3
	COLUMNAS <- 3
	Definir matriz1, matriz2, idx_fila, idx_columna, aux Como Entero
	Dimension matriz1[FILAS, COLUMNAS]
	Dimension matriz2[FILAS, COLUMNAS]
	// Cargar valores en cada matriz
	Escribir "Leer valores de la matriz 1"
	Para idx_fila<-0 Hasta FILAS-1 Hacer
		Para idx_columna<-0 Hasta COLUMNAS-1 Hacer
			Escribir "Ingrese el elemento [", idx_fila + 1, ",", idx_columna + 1, "] " Sin Saltar
			Leer matriz1[idx_fila, idx_columna]
		FinPara
	FinPara
	Escribir "Leer valores de la matriz 2"
	Para idx_fila<-0 Hasta FILAS-1 Hacer
		Para idx_columna<-0 Hasta COLUMNAS-1 Hacer
			Escribir "Ingrese el elemento [", idx_fila + 1, ",", idx_columna + 1, "] " Sin Saltar
			Leer matriz2[idx_fila, idx_columna]
		FinPara
	FinPara
	
	// Procesar las matrices
	Para idx_fila<-0 Hasta FILAS-1 Hacer
		Para idx_columna<-0 Hasta COLUMNAS-1 Hacer
			Si idx_fila > idx_columna Entonces
				aux <- matriz1[idx_fila, idx_columna]
				matriz1[idx_fila, idx_columna] <- matriz2[idx_columna, idx_fila]
				matriz2[idx_columna, idx_fila] <- aux
			FinSi
		FinPara
	FinPara
	
	// Mostrar resultados
	Escribir "Matriz 1 procesada"
	Para idx_fila<-0 Hasta FILAS-1 Hacer
		Escribir "| " Sin Saltar
		Para idx_columna<-0 Hasta COLUMNAS-1 Hacer
			Escribir matriz1[idx_fila, idx_columna], " " Sin Saltar
		FinPara
		Escribir " |"
	FinPara
	
	Escribir "Matriz 2 procesada"
	Para idx_fila<-0 Hasta FILAS-1 Hacer
		Escribir "| " Sin Saltar
		Para idx_columna<-0 Hasta COLUMNAS-1 Hacer
			Escribir matriz2[idx_fila, idx_columna], " " Sin Saltar
		FinPara
		Escribir " |"
	FinPara
	
FinAlgoritmo
