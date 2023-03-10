Proceso Operaciones_matrices_menu
	Definir  A, B, C Como Real;
	Definir opcion, opcion2, fils1, cols1, fils2, cols2, FILSMAX, COLSMAX Como Entero;
	FILSMAX <- 10;
	COLSMAX <- 10;
	fils1 <- 0;
	cols1 <- 0;
	fils2 <- 0;
	cols2 <- 0;
	opcion <- 0;
	opcion2 <- 0;
	Dimension A(FILSMAX, COLSMAX);
	Dimension B(FILSMAX, COLSMAX);
	Dimension C(FILSMAX, COLSMAX);
	
	Repetir
		opcion <- menu();
		Escribir 'Has elegido la opcion ',opcion,' del menu';
		Escribir 'Presione una tecla para continuar...';
		Esperar Tecla;
		Borrar Pantalla;
		Si opcion<>6 Entonces
			cargar_filas_columnas(fils1, cols1);
			condicion_opcion(opcion, fils1, cols1, fils2, cols2);
			inicializar_matriz(fils1, cols1, A);
			inicializar_matriz(fils2, cols2, B);
			Borrar Pantalla;
			Si ((opcion = 1) O (opcion = 2) O (opcion = 3)) Entonces
				completar_matriz(fils1, cols1, A, 1);
				completar_matriz(fils2, cols2, B, 2);
				opcion_proceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
				Escribir "-MATRIZ A-";
				mostrar_matriz(fils1, cols1, A);
				Escribir "-MATRIZ B-";
				mostrar_matriz(fils2, cols2, B);
				Escribir "-MATRIZ RESULTANTE-";
				mostrar_matriz(fils1, cols2, C);
				
			SiNo
				Si (opcion = 5) Entonces
					completar_matriz(fils1, cols1, A, 1);
					opcion_proceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
					Escribir "-MATRIZ-";
					mostrar_matriz(fils1, cols1, A);
					Escribir "-MATRIZ RESULTANTE-";
					mostrar_matriz(cols1, fils1, C);
				SiNo
					completar_matriz(fils1, cols1, A, 1);
					Escribir "-MATRIZ-";
					mostrar_matriz(fils1, cols1, A);
					opcion_proceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
					Escribir "-MATRIZ RESULTANTE-";
					mostrar_matriz(fils1, cols1, C);
				Fin Si
				
			Fin Si
			opcion2 <- 0;
			
		SiNo
			
			opcion2 <- opcion_salida();
			
		FinSi
		Escribir 'Presione una tecla para continuar...';
		Esperar Tecla;
	Hasta Que opcion2=1
FinProceso

SubProceso opcion <- menu ()	
	Definir opcion Como Entero;
	opcion <- 0;
	Repetir
		Borrar Pantalla;
		Escribir '||MENU DE OPERACIONES CON MATRICES||';
		Escribir '1)SUMA.';
		Escribir '2)RESTA.';
		Escribir '3)MULTIPLICACION.';
		Escribir '4)DIVISION POR ESCALAR.';
		Escribir '5)TRASPUESTA.';
		Escribir '6)SALIR.';
		Escribir 'Elija una opcion: ';
		Leer opcion;
		Si ((opcion<1) O (opcion>6)) Entonces
			Escribir 'Opcion invalida.';
			Escribir "Presione una tecla para continuar...";
			Esperar Tecla;
		FinSi
	Hasta Que ((opcion>0) Y (opcion<7))
FinSubProceso

SubAlgoritmo  cargar_filas_columnas (filas Por Referencia, columnas Por Referencia)
	Definir salir como entero;
	Definir FILSMAX, COLSMAX como entero;
	FILSMAX <- 10;
	COLSMAX <- 10;
	salir <- 0;
	Repetir
		Borrar Pantalla;
		Escribir "Digite el numero de filas: ";
		Leer filas;
		Escribir "Digite el numero de columnas: ";
		Leer columnas;
		Si ((filas > FILSMAX) o (columnas > COLSMAX)) Entonces
			Escribir "Ha excedido el limite de memoria.";
			salir = 0;
		SiNo
			salir = 1;
		Fin Si
		
		
	Hasta Que salir = 1
Fin SubAlgoritmo

SubAlgoritmo  condicion_opcion (opcion, filas1 Por Referencia, columnas1 Por Referencia, filas2 Por Referencia, columnas2 Por Referencia )
	
	Si ((opcion = 1) O (opcion = 2)) Entonces
		
		filas2 <- filas1;
		columnas2 <- columnas1;
		
	SiNo
		Si (opcion = 3) Entonces
			
			Escribir "Digite el numero de columnas de la matriz B: ";
			Leer columnas2;
			filas2 <- columnas1;
		SiNo
			Si (opcion = 5) Entonces
				
				filas1 <- columnas1;
				
			SiNo
				
			Fin Si
		Fin Si
	Fin Si
	
Fin SubAlgoritmo

SubAlgoritmo  inicializar_matriz (filas, columnas, matriz)
	Definir i, j como enteros;
	Para i<-0 Hasta (filas - 1) Con Paso 1 Hacer
		
		Para j<-0 Hasta (columnas - 1) Con Paso 1 Hacer
			
			matriz(i, j) <- (0);
			
		Fin Para
		
	Fin Para
Fin SubAlgoritmo

SubAlgoritmo  completar_matriz ( filas, columnas, matriz, nombreMatriz )
	Definir i, j como enteros;
	i <- 0;
	j <- 0;
	Para i<-0 Hasta (filas - 1) Con Paso 1 Hacer
		
		Para j<-0 Hasta (columnas - 1) Con Paso 1 Hacer
			Escribir "COMPLETE LA MATRIZ ",nombreMatriz,"";
			mostrar_matriz(filas, columnas, matriz);
			Escribir "Ingrese el valor [",i+1,"][",j+1,"]" Sin Saltar;
			Leer matriz(i, j);
			Borrar Pantalla;
		Fin Para
		
	Fin Para
Fin SubAlgoritmo

SubAlgoritmo  mostrar_matriz ( filas, columnas, matriz)
	Definir i, j como enteros;
	i <- 0;
	j <- 0;
	Para i<-0 Hasta (filas - 1) Con Paso 1 Hacer
		
		Escribir "|    " Sin Saltar
		Para j<-0 Hasta (columnas - 1) Con Paso 1 Hacer
			
			Escribir matriz(i, j), "   "; Sin Saltar 
		Fin Para
		Escribir "|";
		
	Fin Para	
Fin SubAlgoritmo

SubProceso opcion_proceso (op, fils1, cols1, fils2, cols2, A, B, C)	
	Segun op  Hacer
		1:
			suma_matriz(fils1, cols1, A, B, C);
		2:
			resta_matriz(fils1, cols1, A, B, C);
		3:
			multiplicar_matrices(fils1, cols1, fils2, cols2, A, B, C);
		4:
			div_escalar(fils1, cols1, A, C);
		5:
			traspuesta_matriz(fils1, cols1, A, C);
	FinSegun
FinSubProceso

SubProceso si_no <- opcion_salida ()
	Definir si_no Como Entero;
	si_no <- 0;
	Repetir
		Borrar Pantalla;
		Escribir '¿Seguro que desea salir? <Si = 1 / No = 0>: ';
		Leer si_no;
		Segun si_no  Hacer
			0:
				Escribir 'Has decidido volver al menu.';
			1:
				Escribir 'Has decidido salir del programa.';
			De Otro Modo:
				Escribir 'Opcion invalida.';
				Escribir 'Presione una tecla para continuar...';
				Esperar Tecla;
		FinSegun
	Hasta Que ((si_no=0) O (si_no=1))
FinSubProceso

SubProceso suma_matriz(filas, columnas, matriz_1, matriz_2, matriz_3)
	Definir i, j como enteros;
	i <- 0;
	j <- 0;
	Para i<-0 Hasta (filas - 1) Con Paso 1 Hacer
		
		Para j<-0 Hasta (columnas - 1) Con Paso 1 Hacer
			
			matriz_3(i,j) <- (matriz_1(i,j) + matriz_2(i, j));
			
		Fin Para
	Fin Para
FinSubProceso

SubProceso resta_matriz(filas, columnas, matriz_1, matriz_2, matriz_3)
	Definir i, j como enteros;
	i <- 0;
	j <- 0;
	Para i<-0 Hasta (filas - 1) Con Paso 1 Hacer
		
		Para j<-0 Hasta (columnas - 1) Con Paso 1 Hacer
			
			matriz_3(i,j) <- (matriz_1(i,j) - matriz_2(i, j));
			
		Fin Para
	Fin Para
FinSubProceso

SubProceso multiplicar_matrices(filas1, columnas1, filas2, columnas2, matriz_1, matriz_2, matriz_3)
	Definir i, j como enteros;
	i <- 0;
	j <- 0;
	
	Para i<-0 Hasta (filas1 - 1) Con Paso 1 Hacer
		
		Para j<-0 Hasta (columnas2 - 1) Con Paso 1 Hacer
			
			matriz_3(i,j) <- multiplicar_escalar_matrices(i, j, filas2, matriz_1, matriz_2);
			
		Fin Para
	Fin Para
	
FinSubProceso

SubAlgoritmo res <- multiplicar_escalar_matrices (i, j, elementos, matriz_1, matriz_2 )
	Definir res como real;
	Definir k como entero;
	k <- 0;
	res <- 0.0;
	
	Para k<-0 Hasta (elementos - 1) Con Paso 1 Hacer
		
		res  <- (res + matriz_1(i,k)*matriz_2(k, j));
		
	Fin Para	
Fin SubAlgoritmo

SubAlgoritmo  div_escalar ( filas, columnas, matriz_1, matriz_2 )
	Definir i, j como enteros;
	Definir escalar como real;
	escalar <- 0.0;
	i <- 0;
	j <- 0;
	Escribir "Ingrese un escalar: ";
	Leer escalar;
	
	Para i<-0 Hasta (filas - 1) Con Paso 1 Hacer
		
		Para j<-0 Hasta (columnas - 1) Con Paso 1 Hacer
			
			matriz_2(i, j) <- (matriz_1(i, j) / escalar);
			
		Fin Para
		
	Fin Para
Fin SubAlgoritmo

SubAlgoritmo  traspuesta_matriz (filas, columnas, matriz_1, matriz_2)
	Definir i, j como enteros;
	i <- 0;
	j <- 0;
	Para i<-0 Hasta (columnas - 1) Con Paso 1 Hacer
		
		Para j<-0 Hasta (filas - 1) Con Paso 1 Hacer
			
			matriz_2(i, j) <- matriz_1(j, i);
			
		Fin Para
		
	Fin Para
	
Fin SubAlgoritmo