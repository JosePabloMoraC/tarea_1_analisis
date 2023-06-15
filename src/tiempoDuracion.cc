#include <tiempoDuracion.hh>
#include <chrono>

using namespace std::chrono;

void construirArbol(Arbol& a, int k, int n){
    int etiqueta = 2;
    int i = 0;
    int j;
    bool continuar = true;
    nodo_t nodoActual;

    // Inicializamos una cola
    Cola<nodo_t> cola;
    // Agregar raíz del árbol
    a.PonerRaiz(1);
    // Encolar raíz
    cola.agregar(a.Raiz());

    // Bucle enterno se encarga de revisar la cantidad total de nodos
    // (n - 1) porque ya se agregó la raíz
    while (i < n - 1)
    {  
        j = 0;
        nodoActual = cola.sacar();
        // Bucle interno se encarga de insertar hijos
        while(continuar && j < k){   
            if(i == n){
                // Está condición es importante para evitar que el árbol tenga más de n nodos
                continuar = false;
            } else {
                // Agregamos el nuevo nodo al árbol y lo encolamos
                cola.agregar(a.AgregarHijo(nodoActual, etiqueta, j + 1));

                etiqueta++;
                j++;
                i++;
            }

        }
    }
}

float medirPadrePromedio(Arbol& a, int n, bool ancho){
    int k;
    int cantidadMuestras = 0;
    float tiempoTotal = 0;
    int etiqueta = 100;
    nodo_t nodoActual;
    Traductor traductor;

    //Inicializamos las variables de tiempo
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if(ancho){
        k = 10;
    } else {
        k = 2;
    }

    //construir árbol
    construirArbol(a, k, n);
    
    while(etiqueta <= n){
        nodoActual = traductor.Etiqueta_a_Nodo(etiqueta, a);
        //tomar tiempo
        start = high_resolution_clock::now();
        a.Padre(nodoActual);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        //Cast de duration a long
        tiempoTotal = tiempoTotal + static_cast<float>(duration.count());

        //cout << "La duración del operador padre para el nodo " << etiqueta << " es " << static_cast<long>(duration.count()) << endl;
        
        etiqueta = etiqueta + 200;
        cantidadMuestras++;
    }
    return tiempoTotal/cantidadMuestras; 
}


float medirHermanoDerechoPromedio(Arbol& a, int n, bool ancho){
    int k;
    int cantidadMuestras = 0;
    float tiempoTotal = 0;
    int etiqueta = 100;
    nodo_t nodoActual;
    Traductor traductor;

    //Inicializamos las variables de tiempo
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if(ancho){
        k = 10;
    } else {
        k = 2;
    }

    //construir árbol
    construirArbol(a, k, n);
    
    while(etiqueta <= n){
        nodoActual = traductor.Etiqueta_a_Nodo(etiqueta, a);
        //tomar tiempo
        start = high_resolution_clock::now();
        a.HermanoDerecho(nodoActual);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        //Cast de duration a long
        tiempoTotal = tiempoTotal + static_cast<float>(duration.count());

        //cout << "La duración del operador hermanoDerecho para el nodo " << etiqueta << " es " << static_cast<long>(duration.count()) << endl;
        
        etiqueta = etiqueta + 200;
        cantidadMuestras++;
    }
    return tiempoTotal/cantidadMuestras; 
}

//Siempre es el peor caso
//Devuelve milisegundos
float medirNivelesArbol(Arbol& a, int n, bool ancho){
    int k;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if(ancho){
        k = 10;
    } else {
        k = 2;
    }

    construirArbol(a, k, n);
    start = high_resolution_clock::now();
    nivelesArbol(a);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //Castear de duration a long
    return static_cast<float>(duration.count());
}

//Peor caso
float medirAlturaRaiz(Arbol& a, int n, bool ancho){
    int k;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if(ancho){
        k = 10;
    } else {
        k = 2;
    }

    construirArbol(a, k, n);
    start = high_resolution_clock::now();
    alturaNodo(a.Raiz(), a); // Es el peor caso
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //Castear de duration a long
    return static_cast<float>(duration.count());

    
}

float medirAlturaPromedio(Arbol& a, int n, bool ancho){
    int k;
    int cantidadMuestras = 0;
    float tiempoTotal = 0;
    int etiqueta = 100;
    nodo_t nodoActual;
    Traductor traductor;

    //Inicializamos las variables de tiempo
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if(ancho){
        k = 10;
    } else {
        k = 2;
    }

    //construir árbol
    construirArbol(a, k, n);
    
    while(etiqueta <= n){
        nodoActual = traductor.Etiqueta_a_Nodo(etiqueta, a);
        //tomar tiempo
        start = high_resolution_clock::now();

        alturaNodo(nodoActual, a);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        //Cast de duration a long
        tiempoTotal = tiempoTotal + static_cast<float>(duration.count());

        //cout << "La duración de altura para el nodo " << etiqueta << " es " << static_cast<long>(duration.count()) << endl;
        
        etiqueta = etiqueta + 200;
        cantidadMuestras++;
    }
    return tiempoTotal/cantidadMuestras; 
}

//Peor caso es ultimo nivel
float medirListarEtiquetasNiveles(Arbol& a, int n, bool ancho){
    int k;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    int niveles;

    if(ancho){
        k = 10;
    } else {
        k = 2;
    }

    construirArbol(a, k, n);
    niveles = nivelesArbol(a);
    start = high_resolution_clock::now();
    alturaNodo(a.Raiz(), a); // Es el peor caso
    etiquetasNivel(niveles, a);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //Castear de duration a long
    return static_cast<float>(duration.count());

}

float medirEtiquetasRepetidas(Arbol& a, int n, bool ancho){
    int k;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if(ancho){
        k = 10;
    } else {
        k = 2;
    }

    construirArbol(a, k, n);
    start = high_resolution_clock::now();
    etiquetasRepetidas(a);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //Castear de duration a long
    return static_cast<float>(duration.count());
}

void imprimirExperimento(int n, bool ancho){
    Arbol a1;
    float duracion;
    int tamanoArbol = 500;

    // OPERADORES
    // Tiempo de ejecución promedio de operador Padre()
    cout << "========================================================" << endl;
    cout << "***OPERADORES***" << endl;
    cout << "***Tiempo de ejecucion promedio para operador Padre()***" << endl;

    while(tamanoArbol <= n){
        duracion = medirPadrePromedio(a1, tamanoArbol, ancho);
        
        cout << "n = " << tamanoArbol << " || " << duracion << endl; 
        tamanoArbol = tamanoArbol + 500;
        a1.Vaciar();   
    } 

    //Reiniciar el tamaño del árbol
    tamanoArbol = 500;

    cout << endl;
    cout << "***Tiempo de ejecucion promedio para operador HermanoDerecho()***" << endl;
    while(tamanoArbol <= n){
        duracion = medirHermanoDerechoPromedio(a1, tamanoArbol, ancho);
        
        cout << "n = " << tamanoArbol << " || " << duracion << endl; 
        tamanoArbol = tamanoArbol + 500;
        a1.Vaciar();   
    } 
    tamanoArbol = 500;

    // ALGORITMOS
    cout << "========================================================" << endl;
    cout << endl;
    cout << endl;
    cout << "========================================================" << endl;
    cout << "***ALGORITMOS***" << endl;

    cout << "***Tiempo de ejecucion promedio para algoritmo alturaNodo()***" << endl;
        while(tamanoArbol <= n){
        duracion = medirAlturaPromedio(a1, tamanoArbol, ancho);
        
        cout << "n = " << tamanoArbol << " || " << duracion << endl; 
        tamanoArbol = tamanoArbol + 500;
        a1.Vaciar();   
    } 
    tamanoArbol = 500;

    cout << endl;
    cout << "***Tiempo de ejecucion para el peor caso del algoritmo alturaNodo()***" << endl;
        while(tamanoArbol <= n){
        duracion = medirAlturaRaiz(a1, tamanoArbol, ancho);
        
        cout << "n = " << tamanoArbol << " || " << duracion << endl; 
        tamanoArbol = tamanoArbol + 500;
        a1.Vaciar();   
    } 
    tamanoArbol = 500;

    cout << endl;
    cout << "***Tiempo de ejecucion para el peor caso del algoritmo nivelesArbol()***" << endl;
    while(tamanoArbol <= n){
        duracion = medirNivelesArbol(a1, tamanoArbol, ancho);
        
        cout << "n = " << tamanoArbol << " || " << duracion << endl; 
        tamanoArbol = tamanoArbol + 500;
        a1.Vaciar();   
    } 
    tamanoArbol = 500;

    cout << endl;
    cout << "***Tiempo de ejecucion para el peor caso del algoritmo etiquetasNivel()***" << endl;
    while(tamanoArbol <= n){
        duracion = medirListarEtiquetasNiveles(a1, tamanoArbol, ancho);
        
        cout << "n = " << tamanoArbol << " || " << duracion << endl; 
        tamanoArbol = tamanoArbol + 500;
        a1.Vaciar();   
    } 
    tamanoArbol = 500;

    cout << endl;
    cout << "***Tiempo de ejecucion para el peor caso del algoritmo etiquetasRepetidas()***" << endl;
    while(tamanoArbol <= n){
        duracion = medirEtiquetasRepetidas(a1, tamanoArbol, ancho);
        
        cout << "n = " << tamanoArbol << " || " << duracion << endl; 
        tamanoArbol = tamanoArbol + 500;
        a1.Vaciar();   
    } 
    cout << "========================================================" << endl;
    cout << endl;
}

int main () {
    cout << "Hola mundo" << endl;
    cout << ">>>PROGRAMA DE PRUEBA PARA ARBOL ANGOSTO<<<" << endl;
    imprimirExperimento(15000, false);
    cout << "********************************************************************************************" << endl;
    cout << ">>>PROGRAMA DE PRUEBA PARA ARBOL ANCHO<<<" << endl;
    imprimirExperimento(15000, true);

   

    cout << "Fin del programa" << endl;
    //std::cin.ignore();

    return 0;
}


