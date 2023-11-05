/*
    strtok(): This function is used to break a string into a series of tokens, which are separated by a delimiter
    strstr(): This function is used to search for a substring within a string. 
    sscanf(): This function is used to read formatted input from a string.
*/

/*
char *del_filas, *deli_columnas;

    int condicion = 0;
    for(int i = 0, cant_elems_anteriores = 0; matriz[i] != '\0' || condicion; i++) {

        int cant_espacios = 0;
        for(; matriz[i] != ';' || condicion; i++) {
            if(matriz[i] == ' ') cant_espacios++;
        }
        if(i == 0) cant_elems_anteriores = cant_espacios - 1;
        if(cant_elems_anteriores != cant_espacios - 1) condicion = 1;
    }

    if(condicion) {
        perror("La cantidad de elementos de la matriz difieren");
        exit(1);
    }

    // while(__strtok_r(matriz, ';', del_filas)) {
    //     while(__strtok_r(matriz, ' ', deli_columnas)) {
    //         matriz
    //     }
    // }
*/