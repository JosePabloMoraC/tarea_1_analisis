set(HEADER_LIST "${TareaProgramada1_SOURCE_DIR}/include/*.hh")

add_executable(TareaProgramada1 main.cc arbol_lista.cc colaLSE.cc traductor.cc algoritmos.cc)
target_include_directories(
	TareaProgramada1
	PUBLIC
	"${TareaProgramada1_SOURCE_DIR}/include")