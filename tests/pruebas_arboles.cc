#include <gtest/gtest.h>
#include <arbolArreglo.hh> //se debe cambiar de acuerdo al árbol a probar 
#include <iostream>

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



TEST(Arboles, Stop) {
    std::cin.ignore();
}
