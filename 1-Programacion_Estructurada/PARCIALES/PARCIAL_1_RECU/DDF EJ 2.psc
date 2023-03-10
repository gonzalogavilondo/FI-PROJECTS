Algoritmo main_ej_2
	Dimension mask[4, 4]
	Dimension vec_1[4]
	Dimension vec_2[4]
	Definir COLS Como Entero
	Escribir Escribir "VALORES DE LOS VECTORES ANTSE DE APLICARLES LA MASCARA.\n\n"
	imprimir_vector(vec_1, 1, COLS)
	imprimir_vector(vec_2, 2, COLS)
	aplicar_mascara (vec_1, vec_2, mask, COLS)
	Escribir Escribir "VALORES DE LOS VECTORES DESPUES DE APLICARLES LA MASCARA.\n\n"
	imprimir_vector(vec_1, 1, COLS)
	imprimir_vector(vec_2, 2, COLS)
FinAlgoritmo

Funcion aplicar_mascara (vector_1, vector_2, mask, COLS)
	Para i<-0 Hasta COLS-1 Hacer
		Para j<-0 Hasta COLS-1 Hacer
			Si mask[i, j] == 1 Entonces
				Dimension bytes_vec_1[4] 
				Dimension bytes_vec_2[4]
				get_bytes_by_int(vector_1[i], bytes_vec_1)
				get_bytes_by_int(vector_2[i], bytes_vec_2)
				intercambiar_bytes(bytes_vec_1, bytes_vec_2, i)
				bytes_to_int(bytes_vec_1, vector_1[i] Por Referencia)
				bytes_to_int(bytes_vec_2, vector_2[i] Por Referencia)
			FinSi
		FinPara
	FinPara
FinFuncion

Funcion get_bytes_by_int(elemento, vector)
	//mask <- 0xFF
	Para i<-3 Hasta 0 Con Paso -1 Hacer
		//vector[3-i] = (elemento >> i*8) & mask
	FinPara
FinFuncion

Funcion intercambiar_bytes (bytes_vec_1, bytes_vec_2, posicion)
	Definir aux como entero
	aux <- bytes_vec_1[posicion]
	bytes_vec_1[posicion] <- bytes_vec_2[posicion]
	bytes_vec_2[posicion] <- aux
FinFuncion

Funcion bytes_to_int (bytse_vec, num Por Referencia, COLS)
	entero <- 0
	Para i<-0 Hasta COLS-1 Hacer
		num <- num //+ bytes_vec[i] << ((COLS-1-i)*8)
	FinPara
FinFuncion

Funcion imprimir_vector (vector, num_vector, COLS)
	Escribir  "EL num_vectorº VECTOR ES: \n\n"
	Escribir  "|\t"
	Para i<-0 Hasta COLS-1 Hacer
		Escribir  "0xvector[i]\t"
	FinPara
	Escribir  "|\n\n"
FinFuncion

