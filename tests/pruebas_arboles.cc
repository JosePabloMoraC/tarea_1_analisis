#include <gtest/gtest.h>
#include <traductor.hh> //se debe cambiar de acuerdo al árbol a probar 
#include <algoritmos.hh>
#include <iostream>
/*
//Para poder correr los tests es necesario cambiar en el cmake, la línea 18 [${TareaProgramada1_SOURCE_DIR}/src/arbol___] de acuerdo al ábol que se este incluyendo
//Para efectos de entregar, el CmakeLists.txt de la carpeta tests va a estar sin la extensión .txt
// Correr con : (1) cmake -S . -B build; (2)cmake --build build; (3) cd build/tests; (4) ctest
TEST(Arboles, Insertar) {
    //Notar que indirectamente tambien probamos los métodos Etiqueta e Hijo. Posiblemente esto no sea lo ideal, pero el objetivo del trabajo no es hacer pruebas. 
   Arbol a1 = Arbol();
   a1.PonerRaiz(100);
   a1.AgregarHijo(a1.Raiz(), 120, 1);
   a1.AgregarHijo(a1.Raiz(), 110, 1); // Debería haber un desplazamiento
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 1)), 110);
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 2)), 120);
   a1.AgregarHijo(a1.Raiz(), 130, 3); //Debería ir al final
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 3)), 130);
   a1.AgregarHijo(a1.Raiz(), 140, 4);  //Debería haber un desplazamiento
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 4)), 140);
   a1.AgregarHijo(a1.Raiz(), 135, 4);
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 4)), 135);
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 5)), 140);
   a1.AgregarHijo(a1.Raiz(), 139, 5);
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 5)), 139);
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 6)), 140);
}

TEST(Arboles, Padre) {
   Arbol a1 = Arbol();
   a1.PonerRaiz(100);
   a1.AgregarHijo(a1.Raiz(), 120, 1);
   EXPECT_EQ(a1.Etiqueta(a1.Padre(a1.Hijo(a1.Raiz(), 1))), 100);
}


TEST(Arboles, HermanoDerecho) {
   Arbol a1 = Arbol();
   a1.PonerRaiz(100);
   a1.AgregarHijo(a1.Raiz(), 120, 1);
   a1.AgregarHijo(a1.Raiz(), 110, 1); 
   EXPECT_EQ(a1.HermanoDerecho(a1.Hijo(a1.Raiz(), 2)), a1.NodoNulo());
   EXPECT_EQ(a1.Etiqueta(a1.HermanoDerecho(a1.Hijo(a1.Raiz(), 1))), 120);
   a1.AgregarHijo(a1.Raiz(), 130, 3); 
   a1.AgregarHijo(a1.Raiz(), 140, 4); //Debería ir al final
   EXPECT_EQ(a1.Etiqueta(a1.HermanoDerecho(a1.Hijo(a1.Raiz(), 3))), 140);
}

TEST(Arboles, HermanoIzquierdo) {
   Arbol a1 = Arbol();
   a1.PonerRaiz(100);
   a1.AgregarHijo(a1.Raiz(), 120, 1);
   a1.AgregarHijo(a1.Raiz(), 110, 1); 
   EXPECT_EQ(a1.HermanoIzquierdo(a1.Hijo(a1.Raiz(), 1)), a1.NodoNulo());
   EXPECT_EQ(a1.Etiqueta(a1.HermanoIzquierdo(a1.Hijo(a1.Raiz(), 2))), 110);
   a1.AgregarHijo(a1.Raiz(), 130, 3); 
   a1.AgregarHijo(a1.Raiz(), 140, 4); //Debería ir al final
   EXPECT_EQ(a1.Etiqueta(a1.HermanoIzquierdo(a1.Hijo(a1.Raiz(), 4))), 130);
}

TEST(Arboles, BorrarHoja){
   Arbol a1 = Arbol();
   a1.PonerRaiz(100);
   a1.AgregarHijo(a1.Raiz(), 120, 1);
   a1.AgregarHijo(a1.Raiz(), 110, 1); 
   a1.AgregarHijo(a1.Raiz(), 130, 3); 
   a1.AgregarHijo(a1.Raiz(), 140, 4); 
   a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1); 
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 1)), 110);
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 3)), 130);
   a1.BorrarHoja(a1.Hijo(a1.Raiz(), 1));
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 1)), 120);
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 3)), 140);
   a1.BorrarHoja(a1.Hijo(a1.Raiz(), 2));
   EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 2)), 140);
}

*/


// Pruebas de los algoritmos
TEST(Algoritmos, ListarHermanos){
   //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 

  //Notar que pruebas deben ser distintas porque el listado sale por cout
  //Salida estándar a un stringstream
  std::stringstream output;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

  // Llamar al algoritmo
  etiquetasHermanos(a1.Hijo(a1.Raiz(), 1), a1);

  // Restaurar la salida estándar original
  std::cout.rdbuf(oldCoutBuffer);

  //Comparar
  std::string outputStr = output.str();
  EXPECT_EQ(outputStr, "La lista de Hermanos es: 120 130 140 ");

}

TEST(Algoritmos, ListarHermanos2){
   //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 

  //Notar que pruebas deben ser distintas porque el listado sale por cout
  //Salida estándar a un stringstream
  std::stringstream output;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

  // Llamar al algoritmo
  etiquetasHermanos(a1.Hijo(a1.Raiz(), 3), a1);

  // Restaurar la salida estándar original
  std::cout.rdbuf(oldCoutBuffer);

  //Comparar
  std::string outputStr = output.str();
  EXPECT_EQ(outputStr, "La lista de Hermanos es: 110 120 140 ");
}


TEST(Algoritmos, ListarHermanos3){
   //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 

  //Notar que pruebas deben ser distintas porque el listado sale por cout
  //Salida estándar a un stringstream
  std::stringstream output;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

   //Llamar al algoritmo
  etiquetasHermanos(a1.Hijo(a1.Hijo(a1.Raiz(), 4), 1), a1);
   
   //Restaurar la salida estándar original
  std::cout.rdbuf(oldCoutBuffer);

  //Comparar
  std::string outputStr = output.str();
  EXPECT_EQ(outputStr, "La lista de Hermanos es: ");
}

TEST(Algoritmos, etiquetasNivel1){
   //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 

  //Salida estándar a un stringstream
  std::stringstream output;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

  // Llamar al algoritmo
  etiquetasNivel(1, a1);

  // Restaurar la salida estándar original
  std::cout.rdbuf(oldCoutBuffer);

  //Comparar
  std::string outputStr = output.str();
  EXPECT_EQ(outputStr, "Las etiquetas de los nodos en el nivel 1 son: 100 ");
}

TEST(Algoritmos, etiquetasNivel2){
  //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 

  //Salida estándar a un stringstream
  std::stringstream output;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

  // Llamar al algoritmo
  etiquetasNivel(2, a1);

  // Restaurar la salida estándar original
  std::cout.rdbuf(oldCoutBuffer);

  //Comparar
  std::string outputStr = output.str();
  EXPECT_EQ(outputStr, "Las etiquetas de los nodos en el nivel 2 son: 110 120 130 140 ");
}

TEST(Algoritmos, etiquetasNivel3){
  //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 

  //Salida estándar a un stringstream
  std::stringstream output;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

  // Llamar al algoritmo
  etiquetasNivel(3, a1);

  // Restaurar la salida estándar original
  std::cout.rdbuf(oldCoutBuffer);

  //Comparar
  std::string outputStr = output.str();
  EXPECT_EQ(outputStr, "Las etiquetas de los nodos en el nivel 3 son: 200 210 220 230 240 250 ");
}

TEST(Algoritmos, etiquetasNivel4){
  //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 

  //Salida estándar a un stringstream
  std::stringstream output;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

  // Llamar al algoritmo
  etiquetasNivel(4, a1);

  // Restaurar la salida estándar original
  std::cout.rdbuf(oldCoutBuffer);

  //Comparar
  std::string outputStr = output.str();
  EXPECT_EQ(outputStr, "Las etiquetas de los nodos en el nivel 4 son: 300 310 ");
}

TEST(Algoritmos, cantidadNiveles){
  //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  EXPECT_EQ(nivelesArbol(a1), 1);
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  EXPECT_EQ(nivelesArbol(a1), 2);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  EXPECT_EQ(nivelesArbol(a1), 3);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 
  EXPECT_EQ(nivelesArbol(a1), 4);
}


TEST(Algoritmos, profundidadNodo){
   //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  EXPECT_EQ(profundidadNodo(a1.Raiz(), a1), 0);
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  EXPECT_EQ(profundidadNodo(a1.Hijo(a1.Raiz(), 1), a1), 1);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  EXPECT_EQ(profundidadNodo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), a1), 2);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 
  EXPECT_EQ(profundidadNodo(a1.Hijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 1), a1), 3);
}


TEST(Algoritmos, alturaNodo){
   //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 
  
  EXPECT_EQ(alturaNodo(a1.Raiz(), a1), 3); 
  EXPECT_EQ(alturaNodo(a1.Hijo(a1.Raiz(), 1), a1), 2);
  EXPECT_EQ(alturaNodo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), a1), 1);
  EXPECT_EQ(alturaNodo(a1.Hijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 1), a1), 0);
}

TEST(Algoritmos, existeEtiqueta){
   //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 
  
  EXPECT_EQ(existeEtiqueta(100, a1), true); 
  EXPECT_EQ(existeEtiqueta(110, a1), true); 
  EXPECT_EQ(existeEtiqueta(130, a1), true); 
  EXPECT_EQ(existeEtiqueta(140, a1), true); 
  EXPECT_EQ(existeEtiqueta(200, a1), true); 
  EXPECT_EQ(existeEtiqueta(250, a1), true); 
  EXPECT_EQ(existeEtiqueta(300, a1), true);
  EXPECT_EQ(existeEtiqueta(90, a1), false);  
  EXPECT_EQ(existeEtiqueta(150, a1), false); 
  EXPECT_EQ(existeEtiqueta(270, a1), false); 
  EXPECT_EQ(existeEtiqueta(311, a1), false); 
  EXPECT_EQ(existeEtiqueta(500, a1), false); 
  EXPECT_EQ(existeEtiqueta(1000, a1), false); 
}

TEST(Algoritmos, copiarArbol){
      //Árbol de prueba
  Arbol a1 = Arbol();
  //Raíz
  a1.PonerRaiz(100);
  
  //Nivel 1 
  a1.AgregarHijo(a1.Raiz(), 110, 1);
  a1.AgregarHijo(a1.Raiz(), 120, 2);
  a1.AgregarHijo(a1.Raiz(), 130, 3);
  a1.AgregarHijo(a1.Raiz(), 140, 4);
  //Nivel 2
  //Nodos hijos de 110
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 200, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 210, 2);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 1), 220, 3);
  //Nodos Hijos de 120 
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 2), 230, 1);
  //Nodos Hijos de 130
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 240, 1);
  a1.AgregarHijo(a1.Hijo(a1.Raiz(), 3), 250, 2);
  //Nivel 3
  //Nodos Hijos de 200
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 300, 1); 
  a1.AgregarHijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 310, 2); 
  
  Arbol a2 = copiarArbol(a1);
  //Primer nivel
  EXPECT_EQ(a1.Etiqueta(a1.Raiz()), a1.Etiqueta(a1.Raiz()));
  //Segundo nivel
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 1)), a2.Etiqueta(a2.Hijo(a2.Raiz(), 1)));
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 2)), a2.Etiqueta(a2.Hijo(a2.Raiz(), 2)));
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 3)), a2.Etiqueta(a2.Hijo(a2.Raiz(), 3)));
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Raiz(), 4)), a2.Etiqueta(a2.Hijo(a2.Raiz(), 4)));
  //Tercer nivel
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1)), a2.Etiqueta(a1.Hijo(a2.Hijo(a2.Raiz(), 1), 1)));
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 2)), a2.Etiqueta(a1.Hijo(a2.Hijo(a2.Raiz(), 1), 2)));
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 3)), a2.Etiqueta(a1.Hijo(a2.Hijo(a2.Raiz(), 1), 3)));
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Hijo(a1.Raiz(), 3), 2)), a2.Etiqueta(a1.Hijo(a2.Hijo(a2.Raiz(), 3), 2)));
  //Cuarto nivel
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 1)), a2.Etiqueta(a1.Hijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 1)));
  EXPECT_EQ(a1.Etiqueta(a1.Hijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 2)), a2.Etiqueta(a1.Hijo(a1.Hijo(a1.Hijo(a1.Raiz(), 1), 1), 2)));
}

TEST(Arboles, Stop) {
    std::cin.ignore();
}
